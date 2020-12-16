%{
#include <stdio.h>
#include "ast.h"
int yylex(void);
void yyerror(char *c);

%}

%union{
    int iValue;
    past pAst;
    char *String;
    char * id;
 //   char bracket;
    char c;
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
%type <pAst> program intstr_list id cmp assign parameter_list parameter


%type <pAst>declaration extr_decl add_expr mul_expr primary_expr expr_list cmp_expr assign_expr

%type <pAst>declarator init_declarator_list init_declarator direct_declarator 

%type <pAst> type expr initializer function_definition statement_list print_statement scan_statement

%type <pAst> compound_statement statement expression_statement selection_statement iteration_statement jump_statement

// %type <pAst>id_list 

 %left '+' '-'
 %left '*' '/' '%'
 %left '(' ')'
%precedence "ELSE"F
%expect 1

%%

program: 
        extr_decl '\n' {showAst($1, 0);}
        |program extr_decl '\n' { showAst($2, 0); }
        ;
extr_decl: 
         declaration
         |function_definition {$$ = $1;}
         ;
function_definition:type declarator compound_statement {$$ = newFunc($1, $2, $3);}
                    ;
  
statement_list:statement
              | statement_list statement {$$=newStat_list($1, $2);}
              ; 
statement:compound_statement
         |expression_statement
         |iteration_statement
         |selection_statement
         |print_statement
         |scan_statement 
         |jump_statement
         |declaration
         ;   
 compound_statement:'{' '}' {$$=newEmptyComp("{", "}");}
                  |'{' statement_list '}' {$$=newComp("{", $2, "}");}
                  ;  
expression_statement: ';' {$$ = 0;}
                    | expr ';'
selection_statement: IF '(' expr ')' statement {$$ = newIf_stmt($1, $3, $5);}
                   | IF '(' expr ')' statement ELSE statement {$$ = newIf_Else($1, $3, $5, $6, $7);}
                   ;
iteration_statement: WHILE '(' expr ')' statement {$$ = newWhile($1, $3, $5);}
                   ;
jump_statement: RETURN ';'      {$$ = newRET($1, 0);}
                    ;
               | RETURN expr ';' {$$=newRET($1, $2);}
               ;    
print_statement: PRINT ';' {$$=newPrint($1, 0);}
               | PRINT expr_list ';' {$$=newPrint($1, $2);}
               ;
scan_statement: SCAN ';' {$$=newScan($1, 0);}
                | SCAN expr_list ';' {$$=newScan($1, $2);}
                ;               
declaration:type init_declarator_list';' {$$ = newDecl($1, $2);}
            ;
init_declarator_list:init_declarator    
                     |init_declarator_list ',' init_declarator {$$ = newDecl_list($1, $3);}
                    ;
init_declarator:declarator      
                |declarator '=' add_expr {$$=newDeclarator('=', $1, $3);}
                |declarator '=' '{' intstr_list '}' {$$ = newDeclarator('=', $1, $4);} 
               ;
parameter_list:parameter
              |parameter_list ',' parameter {$$ = newPara_list($1, $3);}
              ;
parameter:type id {$$ = newPara($1, $2);}
         ;
declarator:direct_declarator
        ;
direct_declarator:id 
                 | direct_declarator '(' parameter_list ')' {$$ = newDir_dec($1, $3);}
                 | direct_declarator '(' ')'
                 |id '[' expr ']' {$$ = newDir_dec($1, $3);}
                 |id '[' ']' 
                 ;
type:INT {$$ = newInt($1);}
    |STR {$$ = newSTR($1);}
    |VOID {$$ = newVOID($1);}
    ;
expr: assign_expr
    ;
assign_expr: cmp_expr
           | id cmp assign_expr {$$=new_Expr($2, $1, $3);}
           | id '[' expr ']' '=' assign_expr {$$=newAss_expr_1('=', $1,$3,$6);}
           ;
cmp_expr:add_expr
        |cmp_expr assign add_expr {$$=newCmp($1,$2,$3);}
        ;
add_expr:
        mul_expr
        |add_expr '+' mul_expr {$$=newExpr('+', $1, $3);}
        |add_expr '-' mul_expr {$$=newExpr('-', $1, $3);}
        ;
mul_expr:primary_expr
        |mul_expr '*' primary_expr {$$=newExpr('*', $1, $3);}
        |mul_expr '/' primary_expr {$$=newExpr('/', $1, $3);}
        |mul_expr '%' primary_expr {$$=newExpr('%', $1, $3);}
        |'-'primary_expr {$$=newMul('-',$2);}
        ;
primary_expr: id '(' expr_list ')' {$$=newPrim($1, $3);}
               | id '(' ')'     {$$=newPrim($1, 0);}
               | '(' expr ')'   {$$=newPrim(0, $2);}
               | id            
               | initializer
//               | ID '[' expr ']'    {$$=newPrim($1, $3);}
               ;
expr_list: expr
         | expr_list ',' expr {$$=newExpr_list($1, $3);}
         ;
initializer: NUMBER {$$ = newNum($1);}
           | STRING {$$ = newSTRING($1);}  //和91行的是否一样？
           ;

intstr_list :initializer  
            | intstr_list ',' initializer {$$ = newIntstr($1, $3);}
            ;

id: ID {$$ = newID($1);}
  ;
cmp: CMP {$$ = newCMP($1);}
   ;
assign: ASSIGN {$$ = newASSIGN($1);}
   ;
%%