%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"

int yylex(void);
void yyerror(char *);
struct _ast* root;

%}

%union{
    int	iValue;
	struct _ast*	pAst;
    char *String;
    char * id;
};

%token <String> VOID 264
%token <String> STR 263
%token <String> STRING 260
%token <String> INT
%token <id> ID
%token <String> ASSIGN
%token <iValue> NUMBER 
%token <String> CMP
%token <String> IF 266
%token <String> WHILE 267
%token <String> ELSE 268
%token <String> PRINT 270
%token <String> SCAN 271
%token <String> RETURN 
%type  <pAst>	program external_declaration function_definition
%type  <pAst>   declaration init_declarator_list init_declarator intstr_list
%type  <pAst>   initializer declarator direct_declarator parameter_list parameter
%type  <pAst>   type statement compound_statement begin_scope end_scope statement_list
%type  <pAst>   expression_statement selection_statement iteration_statement jump_statement
%type  <pAst>   print_statement scan_statement expr assign_expr cmp_expr add_expr mul_expr
%type  <pAst>   primary_expr expr_list id_list

%%

program: external_declaration          {$$=connect("program",$1,NULL,NULL,NULL,NULL,NULL,NULL);showAst($1,0);}
        | program external_declaration {$$=connect("program",$1,$2,NULL,NULL,NULL,NULL,NULL);showAst($2,0);}

external_declaration: function_definition       {$$ = connect("external_declaration",$1,NULL,NULL,NULL,NULL,NULL,NULL);} 
                    | declaration               {$$ = connect("external_declaration",$1,NULL,NULL,NULL,NULL,NULL,NULL);}

function_definition: type declarator compound_statement         {printf("***()");$$ = connect("function_definition",$1,$2,$3,NULL,NULL,NULL,NULL);}

declaration: type init_declarator_list ';'                      {$$ = connect("declaration",$1,$2,newTerminal(";"),NULL,NULL,NULL,NULL);}

init_declarator_list: init_declarator                           {$$ = connect("init_declarator",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | init_declarator_list ',' init_declarator  {$$ = connect("init_declarator_list",$1,newTerminal(","),$3,NULL,NULL,NULL,NULL);}

init_declarator: declarator                             {$$ = connect("init_declarator",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
                | declarator '=' add_expr               {$$ = connect("init_declarator",$1,newTerminal("="),$3,NULL,NULL,NULL,NULL);}
                | declarator '=' '{' intstr_list '}'    {$$ = connect("init_declarator",$1,newTerminal("="),newTerminal("{"),$4,newTerminal("}"),NULL,NULL);}

intstr_list: initializer                                {$$ = connect("intstr_list",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
            | intstr_list ',' initializer               {$$ = connect("intstr_list",$1,newTerminal(","),$3,NULL,NULL,NULL,NULL);}

initializer: NUMBER                                     {$$ = connect(newTerminal("NUMBER"),NULL,NULL,NULL,NULL,NULL,NULL);}
            | STRING                                    {$$ = connect(newTerminal("STRING"),NULL,NULL,NULL,NULL,NULL,NULL);}

declarator: direct_declarator                           {$$ = connect("declarator",$1,NULL,NULL,NULL,NULL,NULL,NULL);}

direct_declarator: ID                                           {$$ = connect(newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
                | direct_declarator '(' parameter_list ')'      {$$ = connect("direct_declarator",$1,newTerminal("("),$3,newTerminal(")"),NULL,NULL,NULL);}
                | direct_declarator '(' ')'                     {$$ = connect("direct_declarator",$1,newTerminal("("),newTerminal(")"),NULL,NULL,NULL,NULL);}
                | ID '[' expr ']'                               {$$ = connect("direct_declaration",newTerminal("ID"),newTerminal("["),$3,newTerminal("]"),NULL,NULL,NULL);}
                | ID '[' ']'                                    {$$ = connect("direct_declaration",newTerminal("ID"),newTerminal("["),newTerminal("]"),NULL,NULL,NULL,NULL);}


parameter_list: parameter                               {$$ = connect("parameter_list",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
              | parameter_list ',' parameter            {$$ = connect("parameter_list",$1,newTerminal(","),$3,NULL,NULL,NULL,NULL);}

parameter: type ID      {$$ = connect("parameter",$1,newTerminal("ID"),NULL,NULL,NULL,NULL,NULL);}

type: INT               {$$ = connect("type",newTerminal("INT"),NULL,NULL,NULL,NULL,NULL,NULL);}
    | STR               {$$ = connect("type",newTerminal("STR"),NULL,NULL,NULL,NULL,NULL,NULL);}
    | VOID              {$$ = connect("type",newTerminal("VOID"),NULL,NULL,NULL,NULL,NULL,NULL);} 

statement: compound_statement   {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | expression_statement {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | selection_statement  {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | iteration_statement  {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | jump_statement       {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | print_statement      {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | scan_statement       {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | declaration          {$$ = connect("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}

compound_statement: begin_scope end_scope                       {printf("***begin_scope end_scope");$$ = connect("compound_statement",$1,$2,NULL,NULL,NULL,NULL,NULL);}
                  | begin_scope statement_list end_scope        {$$ = connect("compound_statement",$1,$2,$3,NULL,NULL,NULL,NULL);}

begin_scope: '{'                {$$ = connect("begin_scope",newTerminal("{"),NULL,NULL,NULL,NULL,NULL,NULL);}

end_scope: '}'                  {$$ = connect("end_scope",newTerminal("}"),NULL,NULL,NULL,NULL,NULL,NULL);}

statement_list: statement                       {$$ = connect("statement_list",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
              | statement_list statement        {$$ = connect("statement_list",$1,$2,NULL,NULL,NULL,NULL,NULL);}

expression_statement: ';'       {$$ = connect("expression_statement",newTerminal(";"),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | expr ';'  {$$ = connect("expression_statement",$1,newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}

selection_statement: IF '(' expr ')' statement                  {$$ = connect("selection_statement",newTerminal("IF"),newTerminal("("),$3,newTerminal(")"),$5,NULL,NULL);}
                   | IF '(' expr ')' statement ELSE statement   {$$ = connect("selection_statement",newTerminal("IF"),newTerminal("("),$3,newTerminal(")"),$5,NULL,$7);}

iteration_statement: WHILE '(' expr ')' statement       {$$ = connect("iteration_statement",newTerminal("WHILE"),newTerminal("("),$3,newTerminal(")"),$5,NULL,NULL);}

jump_statement: RETURN ';'              {$$ = connect("jump_statement",newTerminal("RETURN"),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
              | RETURN expr ';'         {$$ = connect("jump_statement",newTerminal("RETURN"),$2,newTerminal(";"),NULL,NULL,NULL,NULL);}

print_statement: PRINT ';'              {$$ = connect("print_statement",newTerminal(PRINT),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
               | PRINT expr_list ';'    {$$ = connect("print_statement",newTerminal(PRINT),$2,newTerminal(";"),NULL,NULL,NULL,NULL);}

scan_statement: SCAN id_list ';'        {$$ = connect("statement",newTerminal("SCAN"),$2,newTerminal(";"),NULL,NULL,NULL,NULL);}

expr: assign_expr       {$$ = connect("expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}

assign_expr: cmp_expr                           {$$ = connect("assign_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
           | ID ASSIGN assign_expr              {$$ = connect("assign_expr",newTerminal("ID"),newTerminal("ASSIGN"),$3,NULL,NULL,NULL,NULL);}
           | ID '=' assign_expr                 {$$ = connect("assign_expr",newTerminal("ID"),newTerminal("="),$3,NULL,NULL,NULL,NULL);}
           | ID '[' expr ']' '=' assign_expr    {$$ = connect("assign_expr",newTerminal("ID"),newTerminal("["),$3,newTerminal("]"),newTerminal("="),$6,NULL);}

cmp_expr: add_expr                      {$$ = connect("cmp_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
        | cmp_expr CMP add_expr         {$$ = connect("cmp_expr",$1,newTerminal("CMP"),$3,NULL,NULL,NULL,NULL);}

add_expr: mul_expr                      {$$ = connect("add_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
        | add_expr '+' mul_expr         {$$ = connect("add_expr",$1,newTerminal("+"),$3,NULL,NULL,NULL,NULL);}
        | add_expr '-' mul_expr         {$$ = connect("add_expr",$1,newTerminal("-"),$3,NULL,NULL,NULL,NULL);}

mul_expr: primary_expr                  {$$ = connect("mul_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
        | mul_expr '*' primary_expr     {$$ = connect("mul_expr",$1,newTerminal("*"),$3,NULL,NULL,NULL,NULL);}
        | mul_expr '/' primary_expr     {$$ = connect("mul_expr",$1,newTerminal("/"),$3,NULL,NULL,NULL,NULL);}
        | mul_expr '%' primary_expr     {$$ = connect("mul_expr",$1,newTerminal("%"),$3,NULL,NULL,NULL,NULL);}
        | '-' primary_expr              {$$ = connect("mul_expr",newTerminal("-"),$2,NULL,NULL,NULL,NULL,NULL);}

primary_expr: ID '(' expr_list ')'      {$$ = connect("primary_expr",newTerminal("ID"),newTerminal("("),$3,newTerminal(")"),NULL,NULL,NULL);}
            | ID '(' ')'                {$$ = connect("primary_expr",newTerminal("ID"),newTerminal("("),newTerminal(")"),NULL,NULL,NULL,NULL);}
            | '(' expr ')'              {$$ = connect("primary_expr",newTerminal("("),$2,newTerminal(")"),NULL,NULL,NULL,NULL);}
            | ID                        {$$ = connect("primary_expr",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
            | initializer               {$$ = connect("primary_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
            | ID '[' expr ']'           {$$ = connect("primary_expr",newTerminal("ID"),newTerminal("["),$3,newTerminal("]"),NULL,NULL,NULL);}

expr_list: expr                         {$$ = connect("expr_list",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | expr_list ',' expr           {$$ = connect("expr_list",$1,newTerminal(","),$3,NULL,NULL,NULL,NULL);}

id_list: ID                             {$$ = connect("id_list",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
       | id_list ',' ID                 {$$ = connect("id_list",$1,newTerminal(","),newTerminal("ID"),NULL,NULL,NULL,NULL);}

%%

void yyerror(char *s) 
{
    fprintf(stderr, "%s\n", s);
}
