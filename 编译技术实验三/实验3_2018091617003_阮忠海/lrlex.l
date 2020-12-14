%{
#include <stdlib.h>
#include "y.tab.h"
#define YYSTYPE struct ast*
char value[50];
extern int lineno;
void yyerror(char *);

%}

%x  COMMENT

%%


"//".*		    {}

"/*"		    {BEGIN COMMENT;}
<COMMENT>"*/"       {BEGIN INITIAL;}
<COMMENT>.          {}


<<EOF>>		    { return END; }




"while"  {return WHILE;}
"if" 	 {return IF;}
"else"   {return ELSE;}
"print"  {return PRINT;}
"scan"   {return SCAN;}
"int"    {return INT;}
"void"   {return VOID;}
"str"    {return STR;}
"return" {return RETURN;}

[0-9]+(l|L)?   {strcpy(value,yytext);return NUMBER;}
[a-zA-Z][a-zA-Z_0-9]*  {strcpy(value,yytext);return ID;}
\042[^\042\n]*\042		{strcpy(value,yytext);return STRING;}


"."                 { return yytext[0];        	  }
"?"  		    { return yytext[0];           }
"+"		    { return yytext[0];           }
"-"		    { return yytext[0];           }
"/"		    { return yytext[0];           }
"*"		    { return yytext[0];           }	
"("		    { return yytext[0];           }
")"		    { return yytext[0];           }	
":"		    { return yytext[0];           }
";"                 { return yytext[0];           }
"{"		    { return yytext[0];           }
"}"		    { return yytext[0];           }
"="		    { return yytext[0];           }
"'"		    { return yytext[0];           }
"]"		    { return yytext[0];           }
"["		    { return yytext[0];           }
","		    { return yytext[0];           }

"+="		{ return ASSIGN; }
"-="		{ return ASSIGN; }
"*="		{ return ASSIGN; }
"/="            { return ASSIGN; }

">="		{return CMP; }
"<="            {return CMP; } 
">"		{return CMP; }
"<"		{return CMP; }
"=="		{return CMP; }


[ \t] ; 	/* skip whitespace */
[\n]	{}



%%


void yyerror(char *s){
	printf("%s\n",s);
}


int yywrap(void) 
{
	return 1;
}



