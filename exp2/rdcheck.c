#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

extern int yylex();
extern int yylval;
extern char *yytext;
FILE *yyin;
FILE *fpIn;

int program();
int external_declaration();
int decl_or_stmt();
int declarator_list();
int intstr_list();
int initializer();
int declarator();
int parameter_list();
int parameter();
int type();
int statement();
int statement_list();
int expr_statement();
int expr();
int cmp_expr();
int add_expr();
int mul_expr();
int primary_expr();
int expr_list();
int id_list();

int tok;

void openInput(int argc, char *argv[])
{
	fpIn = NULL;
	if (argc > 1)
	{
		if ((fpIn = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr, "Error opening input file:  %s", argv[1]);
		}
	}
	else
		fpIn = stdin;
}

void closeInput(FILE *in)
{
	fclose(in);
}

void error_occur()
{
	if (yylex() != NULL)
	{
		printf("Error occur!Stop checking\n");
		exit(0);
	}
	else
	{
		printf("Finish, it's all right!\n");
		exit(0);
	}
		
}

void advance()
{
	tok = yylex();
	while(tok==EOL)
	{
		printf("tok:EOL\n");
		tok = yylex();
	}
	printf("tok: %s\n", yytext);
}

// program
//     : external_declaration
//     | program external_declaration
//     ;

int program()
{
	external_declaration();
	while (tok != EOF)
	{
		external_declaration();
	}
	exit(0);
}

// external_declaration
//     : type declarator decl_or_stmt
//     ;

int external_declaration()
{
	type();
	declarator();
	decl_or_stmt();
}

// decl_or_stmt
//     : '{' statement_list '}'
//     | '{' '}'
//     | ',' declarator_list ';'
//     | ';'
//     ;

int decl_or_stmt()
{
	if (tok == '{')
	{
		advance();
		if (tok == '}')
		{
			advance();
		}
		else
		{
			statement_list();
			if (tok == '}')
			{
				advance();
			}
			else
			{
				error_occur();
			}
		}
	}
	else if (tok == ',')
	{
		advance();
		declarator_list();
		if (tok == ';')
		{
			advance();
		}
		else
		{
			error_occur();
		}
	}
	else if (tok == ';')
	{
		advance();
	}
}

// declarator_list
//     : declarator
//     | declarator_list ',' declarator
//     ;

int declarator_list()
{
	declarator();
	while (yylex() != EOL)
	{
		if (tok == ',')
		{
			advance();
			declarator();
		}
	}
}

// intstr_list
//     : initializer
//     | intstr_list ',' initializer
//     ;

int instr_list()
{
	initializer();
	while (yylex() != EOL)
	{
		if (tok == ',')
		{
			advance();
			initializer();
		}
	}
}

// initializer
//     : NUMBER
//     | STRING
//     ;

int initializer()
{
	if (tok == NUMBER)
	{
		advance();
	}
	else if (tok == STRING)
	{
		advance();
	}
	else
	{
		error_occur();
	}
}

// declarator
//     : ID
//     | ID '=' expr
//     | ID '(' parameter_list ')'
//     | ID '(' ')'
//     | ID '[' expr ']'
//     | ID '[' ']'
//     | ID '[' expr ']' '=' '{' intstr_list '}'
//     | ID '[' ']' '=' '{' intstr_list '}'
//     ;
int declarator()
{
	if (tok == ID)
	{
		advance();
		if (tok == EOL)
		{
			advance();
		}
		else if (tok == '=')
		{
			advance();
			expr();
		}
		else if (tok == '(')
		{
			advance();
			if (tok == ')')
			{
				advance();
			}
			else
			{
				parameter_list();
				if (tok == ')')
				{
					advance();
				}
				else
				{
					error_occur();
				}
			}
		}
		else if (tok == '[')
		{
			advance();
			if (tok == ']')
			{
				advance();
				if (tok == '=')
				{
					advance();
					if (tok == '{')
					{
						advance();
						instr_list();
						if (tok == '}')
						{
							advance();
						}
						else
						{
							error_occur();
						}
					}
					else
					{
						error_occur();
					}
				}
			}
			else
			{
				expr();
				advance();
				if (tok == ']')
				{
					advance();
					if (tok == '=')
					{
						advance();
						if (tok == '{')
						{
							advance();
							instr_list();
							if (tok == '}')
							{
								advance();
							}
							else
							{
								error_occur();
							}
						}
						else
						{
							error_occur();
						}
					}
				}
			}
		}
	}
}

// parameter_list
//         : parameter
//         | parameter_list ',' parameter
//         ;

int parameter_list()
{
	parameter();
	while (yylex() != EOL)
	{
		if (tok == ',')
		{
			advance();
			parameter();
		}
	}
}

// parameter
//         : type ID
//         ;

int parameter()
{
	type();
	if (tok == ID)
	{
		advance();
	}
}

// type
//         : INT
//         | STR
//         | VOID
//         ;

int type()
{
	if (tok == INT)
	{
		advance();
	}
	else if (tok == STR)
	{
		advance();
	}
	else if (tok == VOID)
	{
		advance();
	}
	else
		error_occur();
}

// statement
//     : type declarator_list ';'
//     | '{' statement_list '}'
//     | expr_statement
//     | IF '(' expr ')' statement
//     | IF '(' expr ')' statement ELSE statement
//     | WHILE '(' expr ')' statement
//     | RETURN ';'
//     | RETURN expr ';'
//     | PRINT ';'
//     | PRINT expr_list ';'
//     | SCAN id_list ';'
//     ;

int statement()
{
	if (tok == INT || tok == STR || tok == VOID)
	{
		advance();
		declarator_list();
		if (tok == ';')
		{
			advance();
		}
	}
	else if (tok == '{')
	{
		advance();
		statement_list();
		if (tok == '}')
		{
			advance();
		}
		else
			error_occur();
	}
	else if (tok == IF)
	{
		advance();
		if (tok == '(')
		{
			advance();
			expr();
			if (tok == ')')
			{
				advance();
				statement();
				if (tok == ELSE)
				{
					advance();
					statement();
				}
			}
		}
	}
	else if (tok == WHILE)
	{
		advance();
		if (tok == '(')
		{
			advance();
			expr();
			if (tok == ')')
			{
				advance();
				statement();
			}
		}
	}
	else if (tok == RETURN)
	{
		advance();
		if (tok == ';')
		{
			advance();
		}
		else
		{
			expr();
			if (tok == ';')
			{
				advance();
			}
			else
				error_occur();
		}
	}
	else if (tok == PRINT)
	{
		advance();
		if (tok == ';')
		{
			advance();
		}
		else
		{
			expr_list();
			if (tok == ';')
			{
				advance();
			}
			else
				error_occur();
		}
	}
	else if (tok == SCAN)
	{
		advance();
		id_list();
		if (tok == ';')
		{
			advance();
		}
		else
			error_occur();
	}
	else
	{
		expr_statement();
	}
}

// statement_list
//     : statement
//     | statement_list statement
//     ;

int statement_list()
{
	statement();
	while (yylex() != EOL)
	{
		statement();
	}
}

// expr_statement
//     : ';'
//     | expr ';'
//     ;

int expr_statement()
{
	if (tok == ';')
	{
		advance();
	}
	else
	{
		expr();
		if (tok == ';')
		{
			advance();
		}
		else
			error_occur();
	}
}

// expr
//     : cmp_expr
//     ;

int expr()
{
	cmp_expr();
}

// cmp_expr
//     : add_expr
//     | cmp_expr CMP add_expr
//     ;

int cmp_expr()
{
	int t = add_expr();
	while (tok == CMP)
	{
		advance();
		t = add_expr();
	}
	return t;
}

// add_expr
//     : mul_expr
//     | add_expr '+' mul_expr
//     | add_expr '-' mul_expr
//     ;
int add_expr()
{
	int t = mul_expr();
	while (tok == '+' | tok == '-')
	{
		int ntok = tok;
        if (ntok == '+')
        {
            advance();
            t = mul_expr();
        }
        else if (ntok == '-')
        {
            advance();
            t = mul_expr();
        }
	}
	return t;
}

// mul_expr
//     : primary_expr
//     | mul_expr '*' primary_expr
//     | mul_expr '/' primary_expr
//     | mul_expr '%' primary_expr
//     | '-' primary_expr
//     ;
int mul_expr()
{
	int t;
	if (tok == '-')
	{
		advance();
		t = primary_expr();
	}
	else
	{
		t = primary_expr();
		while (tok == '*' | tok == '/' | tok == '%')
		{
			int ntok = tok;
			if (ntok == '*')
			{
				advance();
				t = primary_expr();
			}
			else if (ntok == '/')
			{
				advance();
				t = primary_expr();
			}
			else if (ntok == '%')
			{
				advance();
				t = primary_expr();
			}
		}
	}
	return t;
}

// primary_expr
//     : ID '(' expr_list ')'
//     | ID '(' ')'
//     | '(' expr ')'
//     | ID
//     | NUMBER
//     | STRING
//     | ID ASSIGN expr
//     | ID '=' expr
//     | ID '[' expr ']'
//     | ID '[' expr ']' '=' expr
//     ;
int primary_expr()
{
	if (tok == '(')
	{
		advance();
		expr_list();
		if (tok == ')')
		{
			advance();
		}
		else
		{
			error_occur();
		}
	}
	else if (tok == ID)
	{
		advance();
		if (tok == '(')
		{
			advance();
			if (tok == ')')
			{
				advance();
			}
			else
			{
				expr_list();
				if (tok == ')')
				{
					advance();
				}
				else
				{
					error_occur();
				}
			}
		}
		else if (tok == '=')
		{
			advance();
			expr();
		}
		else if (tok == '[')
		{
			advance();
			expr();
			if (tok == ']')
			{
				advance();
				if (tok == '=')
				{
					advance();
					expr();
				}
			}
			else
			{
				error_occur();
			}
		}
		else if (tok == ASSIGN)
		{
			advance();
			expr();
		}
	}
	else if (tok == NUMBER)
	{
		advance();
	}
	else if (tok == STRING)
	{
		advance();
	}
}

// expr_list
//     : expr
//     | expr_list ',' expr
//     ;
int expr_list()
{
	expr();
	while (tok == ',')
	{
		expr();
	}
}

// id_list
//     : ID
//     | id_list ',' ID
//     ;
int id_list()
{
loop:
	if (tok == ID)
	{
		advance();
		if (tok == ',')
		{
			advance();
			goto loop;
		}
	}
}

int main(int argc, char **argv)
{
	openInput(argc, argv);
	yyin = fpIn;
	advance();
	int f = program();
	closeInput;
	printf("Finish, it's all right!\n");
	return 0;
}
