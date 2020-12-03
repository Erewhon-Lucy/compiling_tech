#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum yytokentype
{
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
	printf("Error occur!Please check your file\n");
	exit(0);
}

void advance()
{
	tok = yylex();
	printf("tok: %s\n", yytext);
}

// program
//     : external_declaration
//     | program external_declaration
//     ;

int program()
{
	external_declaration();
	while (yylex() != EOF)
	{
		program();
	}
	printf("pass!\n");
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
	if (tok == '{' || tok == ',' || tok == ';')
	{
		advance();
		if (tok == '}')
		{
			advance();
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
				error_occur();
		}
		else if (tok == ';')
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
				error_occur();
		}
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
		printf("ERROR: need NUMBER OR STRING\n");
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
	int l = tok;
	advance();
	if (tok == EOL)
	{
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
			advance();
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
		else
			error_occur();
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
	add_expr();
	while (tok == CMP)
	{
		advance();
		add_expr();
	}
}

// add_expr
//     : mul_expr
//     | add_expr '+' mul_expr
//     | add_expr '-' mul_expr
//     ;
int add_expr()
{
	mul_expr();
	while (tok == '+' | tok == '-')
	{
		advance();
		mul_expr();
	}
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
	if (tok == '-')
	{
		advance();
		primary_expr();
	}
	else
	{
		primary_expr();
		while (tok == '*' | tok == '/' | tok == '%')
		{
			advance();
			primary_expr();
		}
	}
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
	while (tok == ID)
	{
		advance();
		while (tok == ',')
		{
			advance();
			goto loop;
		}
	}
}

typedef struct _ast ast;
typedef struct _ast *past;
struct _ast
{
	int ivalue;
	char *nodeType;
	past left;
	past right;
};

past newAstNode()
{
	past node = malloc(sizeof(ast));
	if (node == NULL)
	{
		printf("run out of memory.\n");
		exit(0);
	}
	memset(node, 0, sizeof(ast));
	return node;
}

past newKey(int value)
{
	past var = newAstNode();
	var->nodeType = "keyWord";
	var->ivalue = value;
	return var;
}
past newNum(int value)
{
	past var = newAstNode();
	var->nodeType = "intValue";
	var->ivalue = value;
	return var;
}


int main(int argc, char **argv)
{
	/*
	rdcheck.c
	If you are going to generate AST,please comment out the following code
	*/
	openInput(argc, argv);
	yyin = fpIn;
	advance();
	int f = program();
	closeInput;
	return 0;

	/*
	rdparser.c
	If you are going to check, please comment out the following code.
	*/
}
