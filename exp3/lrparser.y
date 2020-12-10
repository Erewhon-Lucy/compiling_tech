%{

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
int yylex(void);
void yyerror(char *);

%}

%union{
	int			iValue;
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

program : program expr '\n'	{showAst($2, 0);}
        |	{}
;

expr: factor			  
	| expr '+' factor     {$$ = newExpr('+', $1, $3);}
	| expr '-' factor     {$$ = newExpr('-', $1, $3);}
	;
	
factor: term
	| factor '*' term    {$$ = newExpr('*', $1, $3);} 
	| factor '/' term    {$$ = newExpr('/', $1, $3);}
	;
	
term: NUMBER            {$$ = newNum($1);}
	| '-' term          {$$ = newExpr('-', NULL, $2); }
	;

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
