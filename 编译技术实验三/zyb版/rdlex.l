%{
#include <stdlib.h>
#include "ast.h"
#include "bison_test.tab.h"

void yyerror(char *);
%}

DIGIT [0-9]
LETTER [a-zA-Z]
STRING \"[^\"]*\"


%%
[ |\t]                              { /* eat up blank space */ }
int                                 {yylval.String = yytext; 
                                       return INT;}
str                               {return STR;}
{STRING}                                 {yylval.String = yytext; return STRING;}
if									{yylval.String = yytext; return IF;}
else								{yylval.String = yytext; return ELSE;}
while								{yylval.String = yytext; return WHILE;}
return								{yylval.String = yytext; return RETURN;}
print								{yylval.String = yytext; return PRINT;}
scan								{yylval.String = yytext; return SCAN;}
[0-9]+  {
			yylval.iValue = atoi(yytext);
			return NUMBER;
		}
[=]                   {return *yytext;}
[/*-+%\n]            {return *yytext;}
[>=]|[<=]|[==]|[!=]|[>]|[<]|[|]|[&]&|[&]|[||]  {
			yylval.String = yytext;
			return CMP;
		}
[+=]|[-=]|[/=]|[*=]|[%=] {
			yylval.String = yytext;
			return ASSIGN;
		}

[;\n]                   {return *yytext;}


[,]|[(]|[)]|[{]|[}]	 {return *yytext;}	
[[][]]           {return *yytext;}						
[a-zA-Z]?[a-zA-Z0-9]*      {yylval.id = yytext;return ID;}
("//".*)|("/*"([^*]|"*"[^/])*"*/")  { /* eat up comments */ }
. yyerror("invalid character");
%%



int yywrap()
{
	return 1;
}

