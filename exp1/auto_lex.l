%{
int integerCount = 0;
int identifierCount = 0;
int keywordCount = 0;
int operatorCount = 0;
int commentCount = 0;
%}
/* regular definitions */
digit [0-9]
number {digit}+
letter [A-Za-z]
letters {letter}+
identifier (_|{letter})({letter}|{digit}|_)*
comment ([/][*][^*]*[*]+([^*/][^*]*[*]+)*[/])|([/][/][^\n]*)
operator ([+]|[-]|[*]|[/]|[||]|[!]|[&&]|[=]|[%]|[&]|[[]|[]])

%%
[ \t]+ {}
\n {} /* ignore line feed */
"#" /* ignore */
"{"|"}"|"<"|">"|"#"|";"|"\""|"\""|"\\"|":"|","|"."|"("|")" {printf("separator: %s\n", yytext);} /* separator */
{number} {integerCount++;printf("integer: %s\n",yytext);} /* number */
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {keywordCount++;printf("keyword: %s\n",yytext);} /* keyword */
{number}({letter}|{digit}|_)* {} /* illegal identifier */
{identifier} {identifierCount++;printf("identifier: %s\n",yytext);} /* identifier */
{operator} {operatorCount++;printf("operator: %s\n",yytext);} /* operators */
{comment} {commentCount++;printf("comment: %s\n",yytext);} /* comments */

%%

#include <stdio.h>

int main(int argc, char const *argv[])
{
	yylex();
	printf("numbers of integer: %d\n", integerCount);
	printf("numbers of identifier: %d\n", identifierCount);
	printf("numbers of keyword: %d\n", operatorCount);
	printf("numbers of operators: %d\n", operatorCount);
	printf("numbers of commentCount: %d\n", commentCount);
}
