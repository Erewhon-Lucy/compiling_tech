%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "lrlex.tab.h"

enum yytokentype {
	INT = 258,
	STR = 259,
	VOID = 260,
	ID = 261,
	IF = 262,
	ELSE = 263,
	WHILE = 264,
	RETURN = 265,
	PRINT = 266,
	SCAN = 267,
	STRING = 268,
	ASSIGN = 269,
	CMP = 270,
	NUMBER = 271,
	EOL = 272
};

int yylval;
void yyerror(char *);

%}

digit [0-9]
number {digit}+
letter [A-Za-z]
letters {letter}+
identifier (_|{letter})({letter}|{digit}|_)*

%%


"if"		{yylval = atoi(yytext); return IF;}
"else"	{yylval = atoi(yytext); return ELSE;}
"while"	{yylval = atoi(yytext); return WHILE;}
"return"	{yylval = atoi(yytext); return RETURN;}
"int"		{yylval = atoi(yytext); return INT;}
"str" 	{yylval = atoi(yytext); return STR;}
"void"	{yylval = atoi(yytext); return VOID;}
"print"   {yylval = atoi(yytext); return PRINT;}
"scan"    {yylval = atoi(yytext); return SCAN;}
"+"|"-"|"*"|"/"|"%"|","|";"|"("|")"|"{"|"}"|"["|"]" { return yytext[0]; }
"<"|">"|"=="	{yylval = atoi(yytext); return CMP;}
"="		{yylval = atoi(yytext); return ASSIGN;}
{identifier}	{yylval = atoi(yytext); return ID;}
[0-9]+			{yylval = atoi(yytext);return NUMBER;}
"\""(.)+"\""    {yylval = atoi(yytext); return STRING;}
"//"+.*;  
[\n]	{ return EOL; }
[ \t] { /* ignore whitespace */ }
. 	{ printf("Mystery character %c\n", *yytext); }

%%

int yywrap(void) 
{
	return 1;
}
