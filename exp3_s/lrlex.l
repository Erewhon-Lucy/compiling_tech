%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "lrparser.tab.h"

void yyerror(char *);

%}

digit [0-9]
number {digit}+
letter [A-Za-z]
letters {letter}+
identifier (_|{letter})({letter}|{digit}|_)*

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

[>=]|[<=]|[==]|[!=]|[>]|[<]|[|]|[&]&|[&]|[||]		{return CMP;}
[+=]|[-=]|[/=]|[*=]|[%=]							{return ASSIGN;}
[,]|[(]|[)]|[{]|[}]|[[]|[]]|[=]|[*]|[/]|[%]|[+]|[-]|[;]		{return *yytext;}

{identifier}	{return ID;}
[0-9]+ {return NUMBER;}
"\n"	{}
"\""(.)+"\""    {return STRING;}
"//"+.*

[ |\t] { /* ignore whitespace */ }
. 	{ printf("Mystery character %c\n", *yytext); }

%%

int yywrap(void) 
{
	return 1;
}
