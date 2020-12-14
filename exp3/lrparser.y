%{

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);

%}

%union{
	int		iValue;
	past		pAst;
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

program: external_declaration   {$$ = newList(NULL, $1);}
        | program external_declaration  {$$ = }

external_declaration: function_definition      {$$ = } 
                    | declaration

function_definition: type declarator compound_statement

declaration: type init_declarator_list ';'

init_declarator_list: init_declarator
                    | init_declarator_list ',' init_declarator

init_declarator: declarator
                | declarator '=' add_expr
                | declarator '=' '{' intstr_list '}'

intstr_list: initializer
            | intstr_list ',' initializer

initializer: NUMBER     {$$ = newNum($1);}
            | STRING    {$$ = newVarRef($1, 3);}

declarator: direct_declarator

direct_declarator: ID
                | direct_declarator '(' parameter_list ')'
                | direct_declarator '(' ')'
                | ID '[' expr ']'
                | ID '[' ']'


parameter_list: parameter
              | parameter_list ',' parameter

parameter: type ID

type: INT   {}
    | STR   {}
    | VOID

statement: compound_statement
         | expression_statement
         | selection_statement
         | iteration_statement
         | jump_statement
         | print_statement
         | scan_statement
         | declaration

compound_statement: begin_scope end_scope
                  | begin_scope statement_list end_scope

begin_scope: '{'

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
