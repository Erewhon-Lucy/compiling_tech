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
%token <iValue> EOL 258
%token <iValue> NUMBER 259
%token <String> STRING 260
%token <id>     ID 261
%token <String> INT 262
%token <String> STR 263
%token <String> VOID 264
%token <String> IF 265
%token <String> ELSE 266
%token <String> WHILE 267
%token <String> RETURN 268
%token <String> PRINT 269
%token <String> SCAN 270
%token <String> ASSIGN 271
%token <String> CMP 272

%type  <pAst>	program external_declaration function_definition
%type  <pAst>   declaration init_declarator_list init_declarator intstr_list
%type  <pAst>   initializer declarator direct_declarator parameter_list parameter
%type  <pAst>   type statement compound_statement begin_scope end_scope statement_list
%type  <pAst>   expression_statement selection_statement iteration_statement jump_statement
%type  <pAst>   print_statement scan_statement expr assign_expr cmp_expr add_expr mul_expr
%type  <pAst>   primary_expr expr_list id_list

%%

program: external_declaration          {$$=unite("program",$1,NULL,NULL,NULL,NULL,NULL,NULL);showAst($1,0);}
        | program external_declaration {$$=unite("program",$1,$2,NULL,NULL,NULL,NULL,NULL);showAst($2,0);}

external_declaration: function_definition       {$$ = unite("external_declaration",$1,NULL,NULL,NULL,NULL,NULL,NULL);} 
                    | declaration               {$$ = unite("external_declaration",$1,NULL,NULL,NULL,NULL,NULL,NULL);}

function_definition: type declarator compound_statement         {$$ = unite("function_definition",$1,$2,$3,NULL,NULL,NULL,NULL);}

declaration: type init_declarator_list ';'                      {$$ = unite("declaration",$1,$2,newTerminal(";"),NULL,NULL,NULL,NULL);}

init_declarator_list: init_declarator                           {$$ = unite("init_declarator_list",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
                    | init_declarator_list ',' init_declarator  {$$ = unite("init_declarator_list",$1,newTerminal(","),$3,NULL,NULL,NULL,NULL);}

init_declarator: declarator                             {$$ = unite("init_declarator",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
                | declarator '=' add_expr               {$$ = unite("init_declarator",$1,newTerminal("="),$3,NULL,NULL,NULL,NULL);}
                | declarator '=' '{' intstr_list '}'    {$$ = unite("init_declarator",$1,newTerminal("="),newTerminal("{"),$4,newTerminal("}"),NULL,NULL);}

intstr_list: initializer                                {$$ = unite("intstr_list",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
            | intstr_list ',' initializer               {$$ = unite("intstr_list",$1,newTerminal(","),$3,NULL,NULL,NULL,NULL);}

initializer: NUMBER                                     {$$ = unite("initializer",newTerminal("NUMBER"),NULL,NULL,NULL,NULL,NULL,NULL);}
            | STRING                                    {$$ = unite("initializer",newTerminal("STRING"),NULL,NULL,NULL,NULL,NULL,NULL);}

declarator: direct_declarator                           {$$ = unite("declarator",$1,NULL,NULL,NULL,NULL,NULL,NULL);}

direct_declarator: ID                                           {$$ = unite("direct_declarator",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
                | direct_declarator '(' parameter_list ')'      {$$ = unite("direct_declarator",$1,newTerminal("("),$3,newTerminal(")"),NULL,NULL,NULL);}
                | direct_declarator '(' ')'                     {$$ = unite("direct_declarator",$1,newTerminal("("),newTerminal(")"),NULL,NULL,NULL,NULL);}
                | ID '[' expr ']'                               {$$ = unite("direct_declaratior",newTerminal("ID"),newTerminal("["),$3,newTerminal("]"),NULL,NULL,NULL);}
                | ID '[' ']'                                    {$$ = unite("direct_declaratior",newTerminal("ID"),newTerminal("["),newTerminal("]"),NULL,NULL,NULL,NULL);}


parameter_list: parameter                               {$$ = unite("parameter_list",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
              | parameter_list ',' parameter            {$$ = unite("parameter_list",$1,newTerminal(","),$3,NULL,NULL,NULL,NULL);}

parameter: type ID      {$$ = unite("parameter",$1,newTerminal("ID"),NULL,NULL,NULL,NULL,NULL);}

type: INT               {$$ = unite("type",newTerminal("INT"),NULL,NULL,NULL,NULL,NULL,NULL);}
    | STR               {$$ = unite("type",newTerminal("STR"),NULL,NULL,NULL,NULL,NULL,NULL);}
    | VOID              {$$ = unite("type",newTerminal("VOID"),NULL,NULL,NULL,NULL,NULL,NULL);} 

statement: compound_statement   {$$ = unite("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | expression_statement {$$ = unite("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | selection_statement  {$$ = unite("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | iteration_statement  {$$ = unite("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | jump_statement       {$$ = unite("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | print_statement      {$$ = unite("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | scan_statement       {$$ = unite("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | declaration          {$$ = unite("statement",$1,NULL,NULL,NULL,NULL,NULL,NULL);}

compound_statement: begin_scope end_scope                       {$$ = unite("compound_statement",$1,$2,NULL,NULL,NULL,NULL,NULL);}
                  | begin_scope statement_list end_scope        {$$ = unite("compound_statement",$1,$2,$3,NULL,NULL,NULL,NULL);}

begin_scope: '{'                {$$ = unite("begin_scope",newTerminal("{"),NULL,NULL,NULL,NULL,NULL,NULL);}

end_scope: '}'                  {$$ = unite("end_scope",newTerminal("}"),NULL,NULL,NULL,NULL,NULL,NULL);}

statement_list: statement                       {$$ = unite("statement_list",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
              | statement_list statement        {$$ = unite("statement_list",$1,$2,NULL,NULL,NULL,NULL,NULL);}

expression_statement: ';'       {$$ = unite("expression_statement",newTerminal(";"),NULL,NULL,NULL,NULL,NULL,NULL);}
                    | expr ';'  {$$ = unite("expression_statement",$1,newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}

selection_statement: IF '(' expr ')' statement                  {$$ = unite("selection_statement",newTerminal("IF"),newTerminal("("),$3,newTerminal(")"),$5,NULL,NULL);}
                   | IF '(' expr ')' statement ELSE statement   {$$ = unite("selection_statement",newTerminal("IF"),newTerminal("("),$3,newTerminal(")"),$5,NULL,$7);}

iteration_statement: WHILE '(' expr ')' statement       {$$ = unite("iteration_statement",newTerminal("WHILE"),newTerminal("("),$3,newTerminal(")"),$5,NULL,NULL);}

jump_statement: RETURN ';'              {$$ = unite("jump_statement",newTerminal("RETURN"),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
              | RETURN expr ';'         {$$ = unite("jump_statement",newTerminal("RETURN"),$2,newTerminal(";"),NULL,NULL,NULL,NULL);}

print_statement: PRINT ';'              {$$ = unite("print_statement",newTerminal(PRINT),newTerminal(";"),NULL,NULL,NULL,NULL,NULL);}
               | PRINT expr_list ';'    {$$ = unite("print_statement",newTerminal(PRINT),$2,newTerminal(";"),NULL,NULL,NULL,NULL);}

scan_statement: SCAN id_list ';'        {$$ = unite("scan_statement",newTerminal("SCAN"),$2,newTerminal(";"),NULL,NULL,NULL,NULL);}

expr: assign_expr       {$$ = unite("expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}

assign_expr: cmp_expr                           {$$ = unite("assign_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
           | ID ASSIGN assign_expr              {$$ = unite("assign_expr",newTerminal("ID"),newTerminal("ASSIGN"),$3,NULL,NULL,NULL,NULL);}
           | ID '=' assign_expr                 {$$ = unite("assign_expr",newTerminal("ID"),newTerminal("="),$3,NULL,NULL,NULL,NULL);}
           | ID '[' expr ']' '=' assign_expr    {$$ = unite("assign_expr",newTerminal("ID"),newTerminal("["),$3,newTerminal("]"),newTerminal("="),$6,NULL);}

cmp_expr: add_expr                      {$$ = unite("cmp_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
        | cmp_expr CMP add_expr         {$$ = unite("cmp_expr",$1,newTerminal("CMP"),$3,NULL,NULL,NULL,NULL);}

add_expr: mul_expr                      {$$ = unite("add_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
        | add_expr '+' mul_expr         {$$ = unite("add_expr",$1,newTerminal("+"),$3,NULL,NULL,NULL,NULL);}
        | add_expr '-' mul_expr         {$$ = unite("add_expr",$1,newTerminal("-"),$3,NULL,NULL,NULL,NULL);}

mul_expr: primary_expr                  {$$ = unite("mul_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
        | mul_expr '*' primary_expr     {$$ = unite("mul_expr",$1,newTerminal("*"),$3,NULL,NULL,NULL,NULL);}
        | mul_expr '/' primary_expr     {$$ = unite("mul_expr",$1,newTerminal("/"),$3,NULL,NULL,NULL,NULL);}
        | mul_expr '%' primary_expr     {$$ = unite("mul_expr",$1,newTerminal("%"),$3,NULL,NULL,NULL,NULL);}
        | '-' primary_expr              {$$ = unite("mul_expr",newTerminal("-"),$2,NULL,NULL,NULL,NULL,NULL);}

primary_expr: ID '(' expr_list ')'      {$$ = unite("primary_expr",newTerminal("ID"),newTerminal("("),$3,newTerminal(")"),NULL,NULL,NULL);}
            | ID '(' ')'                {$$ = unite("primary_expr",newTerminal("ID"),newTerminal("("),newTerminal(")"),NULL,NULL,NULL,NULL);}
            | '(' expr ')'              {$$ = unite("primary_expr",newTerminal("("),$2,newTerminal(")"),NULL,NULL,NULL,NULL);}
            | ID                        {$$ = unite("primary_expr",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
            | initializer               {$$ = unite("primary_expr",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
            | ID '[' expr ']'           {$$ = unite("primary_expr",newTerminal("ID"),newTerminal("["),$3,newTerminal("]"),NULL,NULL,NULL);}

expr_list: expr                         {$$ = unite("expr_list",$1,NULL,NULL,NULL,NULL,NULL,NULL);}
         | expr_list ',' expr           {$$ = unite("expr_list",$1,newTerminal(","),$3,NULL,NULL,NULL,NULL);}

id_list: ID                             {$$ = unite("id_list",newTerminal("ID"),NULL,NULL,NULL,NULL,NULL,NULL);}
       | id_list ',' ID                 {$$ = unite("id_list",$1,newTerminal(","),newTerminal("ID"),NULL,NULL,NULL,NULL);}

%%

void yyerror(char *s) 
{
    fprintf(stderr, "%s\n", s);
}
