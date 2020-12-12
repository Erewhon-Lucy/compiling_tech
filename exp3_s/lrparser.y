%{

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);

%}

%union{
	int		iValue;
	past	pAst;
};

%token IF ELSE WHILE RETURN PRINT SCAN STR INT VOID
%token <iValue> NUMBER CMP ASSIGN ID STRING
%type  <pAst>	program external_declaration function_definition
%type  <pAst>   declaration init_declarator_list init_declarator intstr_list
%type  <pAst>   initializer declarator direct_declarator parameter_list parameter
%type  <pAst>   type statement compound_statement begin_scope end_scope statement_list
%type  <pAst>   expression_statement selection_statement iteration_statement jump_statement
%type  <pAst>   print_statement scan_statement expr assign_expr cmp_expr add_expr mul_expr
%type  <pAst>   primary_expr expr_list id_list

%%

program: external_declaration   {$$ = connect("program",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
        | program external_declaration  {showAst($1,0);}

external_declaration: function_definition      {$$ = connect("external_declaration",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);} 
                    | declaration    {$$ = connect("external_declaration",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}

function_definition: type declarator compound_statement     {$$ = connect("function_definition",$1,$2,$3,NULL,NULL,NULL,NULL,NULL);}

declaration: type init_declarator_list ';'  {$$ = connect("declaration",$1,$2,$3,NULL,NULL,NULL,NULL,NULL); $3 = newTerminal(";");}

init_declarator_list: init_declarator    {$$ = connect("init_declarator",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | init_declarator_list ',' init_declarator    {$$ = connect("init_declarator_list",$1,$2,$3,NULL,NULL,NULL,NULL,NULL);$2=newTerminal(",");}

init_declarator: declarator    {$$ = connect("init_declarator",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
                | declarator '=' add_expr    {$$ = connect("init_declarator",$1,$2,$3,NULL,NULL,NULL,NULL,NULL);$2=newTerminal("=");}
                | declarator '=' '{' intstr_list '}'    {$$ = connect("init_declarator",$1,$2,$3,$4,$5,NULL,NULL,NULL);$2=newTerminal("=");$3=newTerminal("{");$5=newTerminal("}");}

intstr_list: initializer    {$$ = connect("intstr_list",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
            | intstr_list ',' initializer   {$$ = connect("intstr_list",$1,$2,$3,NULL,NULL,NULL,NULL,NULL);$2=newTerminal(",");}

initializer: NUMBER     {$$ = newNum($1);}
            | STRING    {$$ = newTerminal("STRING");}

declarator: direct_declarator    {$$ = connect("declarator",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}

direct_declarator: ID    {$$ = newTerminal("ID");}
                | direct_declarator '(' parameter_list ')'  {$$ = connect("direct_declarator",$1,$2,$3,$4,NULL,NULL,NULL,NULL);$2=newTerminal("(");$4=newTerminal(")");}
                | direct_declarator '(' ')' {$$ = connect("direct_declarator",$1,$2,$3,NULL,NULL,NULL,NULL,NULL);$2=newTerminal("(");$3=newTerminal(")");}
                | ID '[' expr ']'   {$$ = connect("direct_declaration",$1,$2,$3,$4,NULL,NULL,NULL,NULL);$1=newTerminal("ID");$2=newTerminal("[");$4=newTerminal(}]);}
                | ID '[' ']'    {$$ = connect("direct_declaration",$1,$2,$3,NULL,NULL,NULL,NULL,NULL);$1=newTerminal("ID");$2=newTerminal("[");$3=newTerminal(}]);}


parameter_list: parameter    {$$ = connect("parameter_list",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
              | parameter_list ',' parameter    {$$ = connect("parameter_list",$1,$2,$3,NULL,NULL,NULL,NULL,NULL); $2=newTerminal(",");}

parameter: type ID    {$$ = connect("parameter",$1,$2,NULL,NULL,NULL,NULL,NULL,NULL,NULL);$1=newTerminal("ID");$2=newTerminal(";");}

type: INT   {$$ = connect("type",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);$1=newTerminal("INT");}
    | STR   {$$ = connect("type",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);$1=newTerminal("STR");}
    | VOID  {$$ = connect("type",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);$1=newTerminal("VOID");} 

statement: compound_statement   {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
         | expression_statement {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
         | selection_statement  {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
         | iteration_statement  {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
         | jump_statement   {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
         | print_statement  {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
         | scan_statement   {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}
         | declaration    {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);}

compound_statement: begin_scope end_scope   {$$ = connect("compound_statement",$1,$2,NULL,NULL,NULL,NULL,NULL,NULL);}
                  | begin_scope statement_list end_scope    {$$ = connect("compound_statement",$1,$2,$3,NULL,NULL,NULL,NULL,NULL);}

begin_scope: '{'    {$$ = connect("begin_scope",$1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);$1=newTerminal("{");}

end_scope: '}'

statement_list: statement
              | statement_list statement

expression_statement: ';'
                    | expr ';'

selection_statement: IF '(' expr ')' statement
                   | IF '(' expr ')' statement ELSE statement

iteration_statement: WHILE '(' expr ')' statement

jump_statement: RETURN ';'
              | RETURN expr ';'

print_statement: PRINT ';'
               | PRINT expr_list ';'

scan_statement: SCAN id_list ';'

expr: assign_expr

assign_expr: cmp_expr
           | ID ASSIGN assign_expr
           | ID '=' assign_expr
           | ID '[' expr ']' '=' assign_expr

cmp_expr: add_expr
        | cmp_expr CMP add_expr

add_expr: mul_expr
        | add_expr '+' mul_expr
        | add_expr '-' mul_expr

mul_expr: primary_expr
        | mul_expr '*' primary_expr
        | mul_expr '/' primary_expr
        | mul_expr '%' primary_expr
        | '-' primary_expr

primary_expr: ID '(' expr_list ')'
            | ID '(' ')'
            | '(' expr ')'
            | ID
            | initializer
            | ID '[' expr ']'

expr_list: expr
         | expr_list ',' expr

id_list: ID
       | id_list ',' ID

%%

void yyerror(char *s) 
{
	fprintf(stderr, "%s\n", s);
}
int main(void) 
{
    yyparse();
    return 0;
}
