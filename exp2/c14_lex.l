%{
enum yytokentype {
	EOL = 258,
	ID = 259,
	NUMBER = 260,
	STRING = 261,
	ASSIGN = 262,
	CMP = 263,
	IF = 264,
	ELSE = 265,
	WHILE = 266,
	RETURN = 267,
	INT = 268,
	STR = 269,
	VOID = 270,
	PRINT = 271,
	SCAN = 272
};

int yylval;

%}

digit [0-9]
number {digit}+
letter [A-Za-z]
letters {letter}+
identifier (_|{letter})({letter}|{digit}|_)*

%%

if		{return IF;}
else	{return ELSE;}
while	{return WHILE;}
return	{return RETURN;}
int		{return INT;}
str 	{return STR;}
void	{return VOID;}
print   {return PRINT;}
scan    {return SCAN;}


"+" |
"-" |
"*" |
"/" |
"%" |
"," |
";" |
"(" |
")" |
"=" |
"{" |
"}" |
"[" |
"]" { return yytext[0]; }

"<"		{return CMP;}
">" 	{return CMP;}
"=="	{return CMP;}
"<="	{return CMP;}
">="	{return CMP;}
"!="	{return CMP;}

"+="	{return ASSIGN;}
"-="	{return ASSIGN;}
"*="	{return ASSIGN;}
"/="	{return ASSIGN;}
"%="	{return ASSIGN;}

{identifier}	{yylval = atoi(yytext);return ID;}
[0-9]+				{yylval = atoi(yytext);return NUMBER;}
\"[^"]*\				{
							char* tem = strdup(yytext + 1);
							tem[yyleng - 2] = 0;
							yylval = atoi(tem);
							free(tem);
							return STRING;
						}


\n	{ return EOL; }
[ \t] { /* ignore whitespace */ }
. 	{ printf("Mystery character %c\n", *yytext); }


%%


int yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
	return 0;
}

int yywrap()
{
	return 1;
}
