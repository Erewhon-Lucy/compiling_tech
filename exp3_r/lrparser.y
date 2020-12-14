%{

#include <stdio.h>
#include "ast.h"
extern char* yytext;
int yylex(void);
struct AST* root;
extern char value[50];
%}

%union{
	int		num;//储存数字类
	char		str[50];//储存非数字类
	struct AST*	Ast;
};




%token <num> NUMBER  
%token <str> ID STRING INT VOID STR ASSIGN CMP WHILE IF ELSE PRINT SCAN RETURN END
%type  <Ast>	program external_declaration function_definition declaration init_declarator_list init_declarator intstr_list initializer declarator direct_declarator parameter_list parameter type statement compound_statement begin_scope end_scope statement_list expression_statement selection_statement iteration_statement jump_statement print_statement scan_statement expr assign_expr cmp_expr add_expr mul_expr primary_expr expr_list id_list

%%
program: external_declaration			{$$ = newnode("program",NULL,1,$1);}
	   | program external_declaration	{$$ = newnode("program",NULL,2,$1,$2);root = $$;}
	   ;

external_declaration: function_definition 	{$$ = newnode("external_declaration",NULL,1,$1);}
					| declaration 		{$$ = newnode("external_declaration",NULL,1,$1);}
					;
function_definition: type declarator compound_statement 	{$$ = newnode("function_definition",NULL,3,$1,$2,$3);}
				;
declaration: type init_declarator_list ';'			{$$ = newnode("declaration",NULL,2,$1,$2);}
				;

init_declarator_list: init_declarator				{$$ = newnode("init_declarator_list",NULL,1,$1);}		
			| init_declarator_list ',' init_declarator	{$$ = newnode("init_declarator_list",NULL,2,$1,$3);}
			;	    
init_declarator: declarator 					
			   | declarator '=' add_expr 		{$$ = newnode("init_declarator",NULL,2,$1,$3);}
			   | declarator '=' '{' intstr_list '}' {$$ = newnode("init_declarator",NULL,2,$1,$4);}
			   ;

intstr_list: initializer					{$$ = newnode("intstr_list",NULL,1,$1);}
		   | intstr_list ',' initializer		{$$ = newnode("intstr_list",NULL,2,$1,$3);}
		   ;
		 
initializer: NUMBER						{$$ = newnode("initializer",NULL,1,newnode("NUMBER",value,1,NULL));}
		   | STRING 					{$$ = newnode("initializer",NULL,1,newnode("STRING",value,1,NULL));}
		   ;
declarator: direct_declarator					{$$ = newnode("declarator",NULL,1,$1);}	
		   ;
		  
direct_declarator: ID						{$$ = newnode("direct_declarator",NULL,1,newnode("ID",value,1,NULL));}							          
				 | direct_declarator '(' parameter_list ')'	 {$$ = newnode("direct_declarator",NULL,2,$1,$3);}
				 | direct_declarator '(' ')'			 {$$ = newnode("direct_declarator",NULL,1,$1);}
				 | ID '[' expr ']'  			      	 {$$ = newnode("direct_declarator",NULL,2,newnode("ID",value,1,NULL),$3);}
				 | ID '[' ']'					 {$$ = newnode("direct_declarator",NULL,1,newnode("ID",value,1,NULL));}
				 ;
parameter_list: parameter						 	 {$$ = newnode("parameter_list",NULL,1,$1);}					
              | parameter_list ',' parameter					 {$$ = newnode("parameter_list",NULL,2,$1,$3);}		
	      ;
parameter: type ID								 {$$ = newnode("parameter",NULL,2,$1,newnode("ID",value,1,NULL));}   							
		;
type:  INT									 {$$ = newnode("type",NULL,1,newnode("INT",NULL,1,NULL));}						
     | STR									 {$$ = newnode("type",NULL,1,newnode("STR",NULL,1,NULL));}
     | VOID									 {$$ = newnode("type",NULL,1,newnode("VOID",NULL,1,NULL));}
     ;
statement: compound_statement						 	 {$$ = newnode("statement",NULL,1,$1);}
         | expression_statement							 {$$ = newnode("statement",NULL,1,$1);}
         | selection_statement							 {$$ = newnode("statement",NULL,1,$1);}
         | iteration_statement							 {$$ = newnode("statement",NULL,1,$1);}
         | jump_statement							 {$$ = newnode("statement",NULL,1,$1);}
         | print_statement							 {$$ = newnode("statement",NULL,1,$1);}
         | scan_statement							 {$$ = newnode("statement",NULL,1,$1);}
         | declaration								 {$$ = newnode("statement",NULL,1,$1);}							 
	 ;
compound_statement: begin_scope end_scope					 {$$ = newnode("compound_statement",NULL,2,$1,$2);}
                  | begin_scope statement_list end_scope			 {$$ = newnode("compound_statement",NULL,2,$1,$2);}
		  ;
begin_scope: '{'		  						 {$$ = newnode("begin_scope",NULL,1,NULL);}
	    ;

end_scope: '}'									 {$$ = newnode("end_scope",NULL,1,NULL);}
	;

statement_list: statement  							 {$$ = newnode("statement_list",NULL,1,$1);}
              | statement_list statement					 {$$ = newnode("statement_list",NULL,2,$1,$2);}
;
expression_statement: ';'							 {$$ = newnode("expression_statement",NULL,1,NULL);}		
                    | expr ';'							 {$$ = newnode("expression_statement",NULL,1,$1);}		
;
selection_statement: IF '(' expr ')' statement					 {$$ = newnode("selection_statement",NULL,3,newnode("IF",NULL,1,NULL),$3,$5);}			
                   | IF '(' expr ')' statement ELSE statement			 {$$ = newnode("selection_statement",NULL,5,newnode("IF",NULL,1,NULL),$3,$5,newnode("ELSE",NULL,1,NULL),$7);}
;
iteration_statement: WHILE '(' expr ')' statement				 {$$ = newnode("iteration_statement",NULL,3,newnode("WHILE",NULL,1,NULL),$3,$5);}
;
jump_statement: RETURN ';'							 {$$ = newnode("jump_statement",NULL,1,newnode("RETURN",NULL,1,NULL));}								
              | RETURN expr ';'							 {$$ = newnode("jump_statement",NULL,2,newnode("RETURN",NULL,1,NULL),$2);}		
;
print_statement: PRINT ';'							 {$$ = newnode("print_statement",NULL,1,newnode("PRINT",NULL,1,NULL));}							
               | PRINT expr_list ';'						 {$$ = newnode("print_statement",NULL,2,newnode("PRINT",NULL,1,NULL),$2);}
;
scan_statement: SCAN id_list ';'					 	 {$$ = newnode("scan_statement",NULL,2,newnode("SCAN",NULL,1,NULL),$2);}	
;
expr: assign_expr								 {$$ = newnode("expr",NULL,1,$1);}
;
assign_expr: cmp_expr								 {$$ = newnode("assign_expr",NULL,1,$1);}			
           | ID ASSIGN assign_expr						 {$$ = newnode("assign_expr",NULL,3,newnode("ID",value,1,NULL),newnode("ASSING",NULL,1,NULL),$3);}
           | ID '=' assign_expr							 {$$ = newnode("assign_expr",NULL,2,newnode("ID",value,1,NULL),$3);}
           | ID '[' expr ']' '=' assign_expr					 {$$ = newnode("assign_expr",NULL,3,newnode("ID",value,1,NULL),$3,$6);}
;
cmp_expr: add_expr								 {$$ = newnode("cmp_expr",NULL,1,$1);}		
        | cmp_expr CMP add_expr							 {$$ = newnode("cmp_expr",NULL,3,$1,newnode("CMP",NULL,1,NULL),$3);}
;
add_expr: mul_expr								 {$$ = newnode("add_expr",NULL,1,$1);}
        | add_expr '+' mul_expr							 {$$ = newnode("add_expr",NULL,2,$1,$3);}
        | add_expr '-' mul_expr							 {$$ = newnode("add_expr",NULL,2,$1,$3);}
;
mul_expr: primary_expr								 {$$ = newnode("mul_expr",NULL,1,$1);}
        | mul_expr '*' primary_expr						 {$$ = newnode("mul_expr",NULL,2,$1,$3);}
        | mul_expr '/' primary_expr						 {$$ = newnode("mul_expr",NULL,2,$1,$3);}
        | mul_expr '%' primary_expr						 {$$ = newnode("mul_expr",NULL,2,$1,$3);}
        | '-' primary_expr						 	 {$$ = newnode("mul_expr",NULL,1,$2);}
;
primary_expr: ID '(' expr_list ')'						 {$$ = newnode("primary_expr",NULL,2,newnode("ID",value,1,NULL),$3);}
            | ID '(' ')'							 {$$ = newnode("primary_expr",NULL,1,newnode("ID",value,1,NULL));}
            | '(' expr ')'							 {$$ = newnode("primary_expr",NULL,1,$2);}
            | ID								 {$$ = newnode("primary_expr",NULL,1,newnode("ID",value,1,NULL));}
            | initializer							 {$$ = newnode("primary_expr",NULL,1,$1);}
            | ID '[' expr ']'							 {$$ = newnode("primary_expr",NULL,2,newnode("ID",value,1,NULL),$3);}
;
expr_list: expr									 {$$ = newnode("expr_list",NULL,1,$1);}
         | expr_list ',' expr							 {$$ = newnode("expr_list",NULL,2,$1,$3);}
;
id_list: ID									 {$$ = newnode("id_list",NULL,1,newnode("ID",value,1,NULL));}
       | id_list ',' ID								 {$$ = newnode("id_list",NULL,2,$1,newnode("ID",value,1,NULL));}
   ;
   			

%%
