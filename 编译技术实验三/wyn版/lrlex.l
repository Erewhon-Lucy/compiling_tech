%option noyywrap
%{
#include <stdlib.h>
#include "ast.h"
#include "lrparser.tab.h"

void yyerror(char *);
%}

/* Definitions, note: \042 is '"' */
digit		[0-9]
alpha		[A-Za-z_]
alphanum	[A-Za-z0-9_]
alphastr	[A-Za-z0-9_\-*/.:()]

%%

if		{return IF;}
else	{return ElSE;}
while	{return WHILE;}
return	{return RETURN;}
int		{return INT;}
str		{return STR;}
void	{return VOID;}
print	{return PRINT;}
scan	{return SCAN;}

"+"|
"-"|
"*"|
"/"|
"%"|
","|
";"|
"("|
")"|
"="|
"{"|
"}"|
"["|
"]"|	{return yytext[0];}

"<"		{yyval.iValue = CMP_LES; return CMP;}
">"		{yyval.iValue = CMP_GRE; return CMP;}
"=="	{yyval.iValue = CMP_EQU; return CMP;}
"<="	{yyval.iValue = CMP_LESE; return CMP;}
">="	{yyval.iValue = CMP_GREE; return CMP;}
"!="	{yyval.iValue = CMP_NEQU; return CMP;}

"+="	{yyval.iValue = ADD_ASSIGN; return ASSIGN;}
"-="	{yyval.iValue = SUB_ASSIGN; return ASSIGN;}
"*="	{yyval.iValue = MUL_ASSIGN; return ASSIGN;}
"/="	{yyval.iValue = DIV_ASSIGN; return ASSIGN;}
"%="	{yyval.iValue = REM_ASSIGN; return ASSIGN;}
		
[ \t]	break; 	/* skip whitespace */
"\n"	++lineno;
"//".*

{alpha}+{alphanum}*		{ /*identifier*/
						yyval.sValue = strdup(yytext);
						return ID;
						}
						
{digit}+				{ /*some number*/
						yyval.iValue = atoi(yytext);
						return NUMBER;
						}

\"[^"]*\"				{ /*string enclosed in quotes*/
						char* tem = strdup(yytext + 1);
						tem[yyleng - 2] = 0;
						yyval.sValue = strdup(tem);
						free(tem);
						return STRING;
						}
					
.						{
							fprintf(stderr, "Illegal character \'%s\'on line #%d\n", yytext, lineno);
							exit(1);

%%

int yyerror(char* s)
{
	fprintf(stderr, "error: %s\n", s);
	return 0;
}

int yywrap(void) 
{
	return 1;
}