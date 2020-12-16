%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "lrparser.tab.h"

void yyerror(char *);

%}

DIGIT [0-9]
LETTER [a-zA-Z]
STRING \"[^\"]*\"

%%


if			{return IF;}
else		{return ELSE;}
while		{return WHILE;}
return		{return RETURN;}
int			{return INT;}
str 		{return STR;}
void		{return VOID;}
print   	{return PRINT;}
scan    	{return SCAN;}
[a-zA-Z]?[a-zA-Z0-9]*			{return ID;}
[>=]|[<=]|[==]|[!=]|[>]|[<]|[|]|[&]&|[&]|[||]		{return CMP;}
[+=]|[-=]|[/=]|[*=]|[%=]							{return ASSIGN;}
[,]|[(]|[)]|[{]|[}]|[[]|[]]|[=]		{return *yytext;}
[/*-+%\n]						{return *yytext;}
[;\n]							{return *yytext;}

[0-9]+			{return NUMBER;}
"\""(.)+"\""    {return STRING;}
"//"+.*

[ |\t] { /* ignore whitespace */ }
. 	{ printf("Mystery character %c\n", *yytext); }

%%

int yywrap(void) 
{
	return 1;
}
