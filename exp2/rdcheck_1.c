#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum yytokentype
{
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
extern FILE *yyin;
FILE *fpIn;
int tok;

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

void advance()
{
    tok = yylex();
    while (tok == EOL)
    {
        printf("tok:EOL\n");
        tok = yylex();
    }

    printf("tok: %s\n", yytext);
}

int program()
{
    external_declaration();
    while (tok != EOF)
    {
        external_declaration();
    }
}
int external_declaration()
{
    type();
    declarator();
    decl_or_stmt();
}

int decl_or_stmt()
{
    //advance();
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

    else
    {
        printf("Finish, it’s all right!\n");
        exit(0);
    }
}
int statement_list()
{
    int k = statement();
    while (k != 0)
    {
        k = statement();
    }
}
int statement()
{
    if (tok == '{')
    {
        advance();
        statement_list();
        if (tok == '}')
        {
            advance();
            return 1;
        }
        else
        {
            error_occur(0);
            return 0;
        }
    }
    else if (tok == INT || tok == STR || tok == VOID)
    {
        advance();
        declarator_list();
        if (tok == ';')
        {
            advance();
            return 1;
        }
        else
        {
            error_occur();
            return 0;
        }
    }
    else if (tok == IF)
    {
        advance();
        if (tok == '(')
        {
            advance();
            if (expr())
            {
                if (tok == ')')
                {
                    advance();
                    int t = statement();
                    if (tok == ELSE)
                    {
                        advance();
                        return statement();
                    }
                    return t;
                }
                else
                {
                    error_occur();
                    return 0;
                }
            }
            else
            {
                error_occur();
                return 0;
            }
        }
        else
        {
            error_occur();
            return 0;
        }
    }
    else if (tok == WHILE)
    {
        advance();
        if (tok == '(')
        {
            advance();
            if (expr())
            {
                if (tok == ')')
                {
                    advance();
                    return statement();
                }
                else
                {
                    error_occur();
                    return 0;
                }
            }
            else
            {
                error_occur();
                return 0;
            }
        }
        else
        {
            error_occur();
            return 0;
        }
    }
    else if (tok == RETURN)
    {
        advance();
        if (tok == ';')
        {
            advance();
            return 1;
        }

        else
        {
            if (expr())
            {
                if (tok == ';')
                {
                    advance();
                    return 1;
                }
                else
                {
                    error_occur();
                    return 0;
                }
            }
            else
            {
                error_occur();
                return 0;
            }
        }
    }
    else if (tok == PRINT)
    {
        advance();
        if (tok == ';')
        {
            advance();
            return 1;
        }
        else
        {
            if (expr_list())
            {
                if (tok == ';')
                {
                    advance();
                    return 1;
                }
                else
                {
                    error_occur();
                    return 0;
                }
            }
            else
            {
                error_occur();
                return 0;
            }
        }
    }
    else if (tok == SCAN)
    {
        advance();
        if (id_list())
        {
            if (tok == ';')
            {
                advance();
                return 1;
            }
            else
            {
                error_occur();
                return 0;
            }
        }
        else
        {
            error_occur();
            return 0;
        }
    }
    else
    {
        return expr_statement();
    }
}
int declarator_list()
{
    declarator();
    while (tok == ',')
    {
        advance();
        declarator();
    }
}

int declarator()
{
    if (tok == ID)
    {
        advance();
        if (tok == ASSIGN)
        {
            advance();
            if (!expr())
            {
                error_occur();
            }
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
                if (tok == ASSIGN)
                {
                    advance();
                    if (tok == '{')
                    {
                        advance();
                        intstr_list();
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
                if (expr())
                {
                    if (tok == ']')
                    {
                        advance();
                        if (tok == ASSIGN)
                        {
                            advance();
                            if (tok == '{')
                            {
                                advance();
                                intstr_list();
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
int intstr_list()
{
    if (tok == NUMBER)
    {
        advance();
    }
    else if (tok == STRING)
    {
        advance();
    }

    while (tok == ',')
    {

        advance();
        if (tok == NUMBER)
        {
            advance();
        }
        else if (tok == STRING)
        {
            advance();
        }
    }
}

int parameter_list()
{
    parameter();
    while (tok == ',')
    {
        advance();
        parameter();
    }
}
int parameter()
{
    type();
    if (tok == ID)
    {
        advance();
    }
    else
    {
        error_occur();
    }
}
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
}
int expr_statement()
{
    if (tok == ';')
    {
        advance();
        return 1;
    }
    else
    {
        if (expr())
        {
            if (tok == ';')
            {
                advance();
                return 1;
            }
            else
            {
                error_occur();
                return 0;
            }
        }
        else
        {
            error_occur();
            return 0;
        }
    }
}

int expr_list()
{
    int t = expr();
    while (tok == ',')
    {
        advance();
        t = expr();
    }
    return t;
}

int expr()
{
    if (cmp_expr())
        return 1;
    else
    {
        return 0;
    }
}
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
int add_expr()
{
    int t = mul_expr();
    while (tok == '+' || tok == '-')
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
        if (t == 1)
        {
            while (tok == '*' || tok == '/' || tok == '%')
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
        else
        {
            t = 0;
        }
    }
    return t;
}
int id_list()
{
    if (tok == ID)
    {
        advance();
        while (tok == ',')
        {
            advance();
            if (tok == ID)
            {
                advance();
            }
            else
            {
                error_occur();
                return 0;
            }
        }
        return 1;
    }
    else
    {
        error_occur();
        return 0;
    }
}

int primary_expr()
{
    if (tok == ID)
    {
        advance();
        if (tok == '(')
        {
            advance();
            if (tok == ')')
            {
                advance();
                return 1;
            }
            else
            {
                if (expr_list())
                {
                    if (tok == ')')
                    {
                        advance();
                        return 1;
                    }
                    else
                    {
                        error_occur();
                        return 0;
                    }
                }
                else
                {
                    error_occur();
                    return 0;
                }
            }
        }

        else if (tok == ASSIGN)
        {
            advance();
            return expr();
        }
        else if (tok == '[')
        {
            advance();
            if (expr())
            {
                if (tok == ']')
                {
                    advance();
                    if (tok == ASSIGN)
                    {
                        advance();
                        return expr();
                    }
                }
                else
                {
                    error_occur();
                    return 0;
                }
            }
            else
            {
                error_occur();
                return 0;
            }
        }
        return 1;
    }
    else if (tok == NUMBER)
    {
        advance();
        return 1;
    }
    else if (tok == STRING)
    {
        advance();
        return 1;
    }
    else
    {
        return 0;
    }
}
void error_occur()
{
    printf("Error occur!Stop checking.\n");
    exit(0);
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
