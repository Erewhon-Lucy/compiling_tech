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

void advance()
{
    tok = yylex();
    while (tok == EOL)
    {
        tok = yylex();
    }
    printf("tok: %s\n", yytext);
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

void openInput(int argc, char *argv[]);
void closeInput(FILE *in);
void showAst(past node, int nest);
past astProgram();
past astExternal_declaration();
past astDecl_or_stmt();
past astDeclarator_list();
past astIntstr_list();
past astInitializer();
past astDeclarator();
past astParameter_list();
past astParameter();
past astType();
past astExpr_list();
past astId_list();
past astExpression_statement();
past astStatement();
past astStatement_list();
past astPrimary_expr();
past astMul_expr();
past astAdd_expr();
past astCmp_expr();
past ast_expr();

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

past newNum(int value)
{
    past var = newAstNode();
    var->nodeType = "intValue";
    var->ivalue = value;
    return var;
}
past newExpr(int oper, past left, past right)
{
    past var = newAstNode();
    var->nodeType = "ch";
    var->ivalue = oper;
    var->left = left;
    var->right = right;
    return var;
}

past newList(past left, past right)
{
    past var = newAstNode();
    var->left = left;
    var->right = right;
    var->ivalue = -11;
    var->nodeType = "none";
    return var;
}

past newVarRef(int tok, int i)
{
    past var = newAstNode();
    switch (i)
    {
    case 1: var->nodeType = "expr"; break;
    case 2: var->nodeType = "id";break;
    case 3: var->nodeType = "initializer";break;
    case 4: var->nodeType = "type";break;
    case 5: var->nodeType = "if";break;
    case 6: var->nodeType = "else";break;
    case 7: var->nodeType = "while";break;
    case 8: var->nodeType = "return";break;
    case 9: var->nodeType = "print";break;
    case 10: var->nodeType = "scan";break;
    default:
        break;
    }
    var->ivalue = tok;
    return var;
}

past newBracket(int oper1, past var, int oper2)
{
    if (var == NULL)
    {
        var = newAstNode();
        var->ivalue = -11;
        var->nodeType = "none";
    }
    past var1 = newAstNode();
    past var2 = newAstNode();
    var1->nodeType = "expr";
    var1->ivalue = oper1;
    var2->nodeType = "expr";
    var2->ivalue = oper2;
    past parent1 = newAstNode();
    parent1->ivalue = -11;
    parent1->nodeType = "none";
    parent1->left = var1;
    parent1->right = var;
    past parent2 = newAstNode();
    parent2->ivalue = -11;
    parent2->nodeType = "none";
    parent2->left = parent1;
    parent2->right = var2;
    return parent2;
}

past astProgram()
{
    past l = astExternal_declaration();
    if (l != NULL)
    {
        past n = astExternal_declaration();
        while (n != NULL)
        {
            l = newList(l, n);
            n = astProgram();
        }
    }
    l->nodeType = "program";
    return l;
}

past astExternal_declaration()
{
    past l = astType();
    if (l != NULL)
    {
        past n = astDeclarator();
        if (n != NULL)
        {
            n = newList(l, n);
            past r = astDecl_or_stmt();
            if (r != NULL)
            {
                l = newList(n, r);
            }
        }
    }
    l->nodeType = "external_declaration";
    return l;
}

past astDecl_or_stmt()
{
    if (tok == '{')
    {
        past n = newVarRef(tok,1);
        advance();
        if (tok == '}')
        {
            advance();
        }
        else
        {
            past l = astStatement_list();
            advance();
            l = newBracket('{', l, '}');
            l->nodeType = "decl_or_stmt";
            return l;
        }
    }
    else if (tok == ',')
    {
        past n = newVarRef(tok, 1);
        advance();
        past l = astDeclarator_list();
        if (l != NULL)
        {
            if (tok == ';')
            {
                past r = newVarRef(tok, 1);
                advance();
                l = newList(n, l);
                l = newList(l, r);
                l->nodeType = "decl_or_stmt";
                return l;
            }
        }
    }
    else if (tok == ';')
    {
        past l = newVarRef(tok, 1);
        advance();
        l->nodeType = "decl_or_stmt";
        return l;
    }
    return NULL;
}

past astDeclarator_list()
{
    past l = astDeclarator();
    if (tok == ',')
    {

        advance();
        past r = astDeclarator_list();
        if (r != NULL)
        {
            l = newExpr(',', l, r);
        }
    }
    l->nodeType = "declarator_list";
    return l;
}

past astIntstr_list()
{
    past l = astInitializer();
    if (tok == ',')
    {
        advance();
        past r = astIntstr_list();
        if (r != NULL) 
        {
            l = newExpr(',', l, r);
        }
    }
    l->nodeType = "intstr_list";
    return l;
}

past astInitializer()
{
    if (tok == NUMBER | tok == STRING)
    {
        past l = newVarRef(tok, 3);
        advance();
        l->nodeType = "initializer";
        return l;
    }
    return NULL;
}

past astDeclarator()
{
    if (tok == ID)
    {
        past n = newVarRef(tok, 2);
        advance();
        if (tok == ASSIGN)
        {
            advance();
            past l = ast_expr();
            if (l != NULL)
            {
                l = newExpr('=', n, l);
                l->nodeType = "declarator";
                return l;
            }
        }
        else if (tok == '(')
        {
            advance();
            past l = astParameter_list();
            if (tok == ')')
            {
                l = newBracket('(', l, ')');
                l = newList(n, l);
                advance();
                l->nodeType = "declarator";
                return l;
            }
        }
        else if (tok == '[')
        {
            advance();
            past l = ast_expr();
            if (tok == ']')
            {
                l = newBracket('[', l, ']');
                l = newList(n, l);
                advance();
                if (tok == ASSIGN)
                {
                    advance();
                    if (tok == '{')
                    {
                        advance();
                        past n = astIntstr_list();
                        if (n != NULL)
                        {
                            if (tok == '}')
                            {
                                n = newBracket('{', n, '}');
                                l = newExpr('=', l, n);
                                advance();
                            }
                        }
                    }
                }
                l->nodeType = "declarator";
                return l;
            }
        }
        n->nodeType = "declarator";
        return n;
    }
    return NULL;
}

past astParameter_list()
{
    past l = astParameter();
    if (tok == ',')
    {
        past r = astParameter_list();
        if (r != NULL)
        {
            l = newExpr(',', l, r);
        }
    }
    l->nodeType = "parameter_list";
    return l;
}

past astParameter()
{
    past l = astType();
    if (l != NULL)
    {
        if (tok == ID)
        {
            past r = newVarRef(tok, 2);
            l = newList(l, r);
            advance();
        }
    }
    l->nodeType = "parameter";
    return l;
}

past astType()
{
    if (tok == INT || tok == STR || tok == VOID)
    {
        past l = newVarRef(tok, 4);
        advance();
        l->nodeType = "type";
        return l;
    }
    return NULL;
}

past astStatement()
{
    past l;
    if (tok == '{')
    {
        advance();
        l = astStatement_list();
        if (l != NULL)
        {
            if (tok == '}')
            {
                l = newBracket('{', l, '}');
                advance();
                l->nodeType = "statement";
                return l;
            }
        }
    }
    else if (tok == IF)
    {
        past r = newVarRef(tok, 5);
        advance();
        if (tok == '(')
        {
            advance();
            l = ast_expr();
            if (l != NULL)
            {
                if (tok == ')')
                {
                    l = newBracket('(', l, ')');
                    l = newList(r, l);
                    advance();
                    past n = astStatement();
                    if (n != NULL)
                    {
                        l = newList(n, l);
                        if (tok == ELSE)
                        {
                            r = newVarRef(tok, 6);
                            advance();
                            n = astStatement();
                            if (n != NULL)
                            {
                                n = newList(r, n);
                                l = newList(l, n);
                            }
                        }
                        l->nodeType = "statement";
                        return l;
                    }
                }
            }
        }
    }
    else if (tok == WHILE)
    {
        past n = newVarRef(tok, 7);
        advance();
        if (tok == '(')
        {
            advance();
            past l = ast_expr();
            if (l != NULL)
            {
                if (tok == ')')
                {
                    l = newBracket('(', l, ')');
                    advance();
                    past r = astStatement();
                    if (r != NULL)
                    {
                        l = newList(n, l);
                        l = newList(l, r);
                        l->nodeType = "statement";
                        return l;
                    }
                }
            }
        }
    }
    else if (tok == RETURN)
    {
        past n = newVarRef(tok, 8);
        advance();
        past l = ast_expr();
        if (l != NULL)
        {
            n = newList(n, l);
        }
        if (tok == ';')
        {
            past r = newVarRef(tok, 1);
            advance();
            n = newList(n, r);
            n->nodeType = "statement";
            return n;
        }
    }
    else if (tok == PRINT)
    {
        past n = newVarRef(tok, 3);
        advance();
        past l = astExpr_list();
        if (l != NULL)
        {
            n = newList(n, l);
        }
        if (tok == ';')
        {
            past r = newVarRef(tok, 1);
            advance();
            n = newList(n, r);
            n->nodeType = "statement";
            return n;
        }
    }
    else if (tok == SCAN)
    {
        past n = newVarRef(tok, 10);
        advance();
        past l = astId_list();
        if (l != NULL)
        {
            if (tok == ';')
            {
                past r = newVarRef(tok, 1);
                advance();
                l = newList(n, l);
                l = newList(l, r);
                l->nodeType = "statement";
                return l;
            }
        }
    }
    l = astType();
    if (l != NULL)
    {
        past n = astDeclarator_list();
        if (n != NULL)
        {
            if (tok == ';')
            {
                past r = newVarRef(';', 1);
                l = newList(l, n);
                l = newList(l, r);
                advance();
                l->nodeType = "statement";
                return l;
            }
        }
    }
    l = astExpression_statement();
    if (l != NULL)
    {
        l->nodeType = "statement";
        return l;
    }
    return NULL;
}

past astStatement_list()
{
    past l = astStatement();
    if (l != NULL)
    {
        past n = astStatement();
        while (n != NULL)
        {
            l = newList(l, n);
            n = astStatement_list();
        }
    }
    l->nodeType = "statement_list";
    return l;
}

past astExpression_statement()
{
    // past l = ast_expr();
    // if (tok == ';')
    // {
    //     past n = newVarRef(tok, 1);
    //     if (l != NULL)
    //     {
    //         l = newList(n, l);
    //         advance();
    //         return l;
    //     }
    //     else
    //     {
    //         return n;
    //     }
    // }
    if (tok == ';')
    {
        past r = newVarRef(tok, 1);
        advance();
        r->nodeType = "expression_statement";
        return r;
    }
    else
    {
        past l = ast_expr();
        if (tok == ';')
        {
            past n = newVarRef(tok, 1);
            if (l != NULL)
            {
                l = newList(n, l);
                advance();
                l->nodeType = "expression_statement";
                return l;
            }
            else
            {
                n->nodeType = "expression_statement";
                return n;
            }
        }
    }
    return NULL;
}

past ast_expr()
{
    past l = astCmp_expr();
    l->nodeType = "ast_expr";
    return l;
}

past astCmp_expr()
{
    past l = astAdd_expr();
    if (l != NULL)
    {
        while (tok == CMP)
        {
            advance();
            past r = astAdd_expr();
            if (r != NULL)
            {
                l = newExpr(CMP, l, r);
            }
        }
    }
    l->nodeType = "add_expr";
    return l;
}

past astAdd_expr()
{
    past l = astMul_expr();
    if (l != NULL)
    {
        while (tok == '+' || tok == '-')
        {
            int oper = tok;
            advance();
            past r = astMul_expr();
            if (r != NULL)
            {
                l = newExpr(oper, l, r);
            }
        }
    }
    l->nodeType = "add_expr";
    return l;
}

past astMul_expr()
{
    if (tok == '-')
    {
        advance();
        past l = astPrimary_expr();
        if (l != NULL)
        {
            l = newExpr('-', NULL, l);
            l->nodeType = "mul_expr";
            return l;
        }
    }
    else
    {
        past l = astPrimary_expr();
        if (l != NULL)
        {
            while (tok == '*' || tok == '/' || tok == '%')
            {
                int oper = tok;
                advance();
                past r = astPrimary_expr();
                if (r != NULL)
                {
                    l = newExpr(oper, l, r);
                }
            }
        }
        l->nodeType = "mul_expr";
        return l;
    }
}

past astPrimary_expr()
{
    if (tok == ID)
    {
        past n = newVarRef(tok, 2);
        advance();
        if (tok == '(')
        {
            advance();
            past l = astExpr_list();
            if (tok == ')')
            {
                advance();
                l = newBracket('(', l, ')');
                l = newList(n, l);
                l->nodeType = "primary_expr";
                return l;
            }
        }
        else if (tok == '[')
        {
            advance();
            past l = ast_expr();
            if (l != NULL)
            {
                if (tok == ']')
                {
                    advance();
                    l = newBracket('[', l, ']');
                    l = newList(n, l);
                    if (tok == ASSIGN)
                    {
                        past r = ast_expr();
                        if (r != NULL)
                        {
                            l = newExpr('=', l, r);
                        }
                    }
                    l->nodeType = "primary_expr";
                    return l;
                }
            }
        }
        else if (tok == ASSIGN)
        {
            advance();
            past l = ast_expr();
            if (l != NULL)
            {
                l = newExpr(ASSIGN, n, l);
                l->nodeType = "primary_expr";
                return l;
            }
        }
        return n;
    }
    else if (tok == '(')
    {
        advance();
        past l = ast_expr();
        if (l != NULL)
        {
            if (tok == ')')
            {
                advance();
                l = newBracket('(', l, ')');
                l->nodeType = "primary_expr";
                return l;
            }
        }
    }
    else if (tok == NUMBER)
    {
        past n = newNum(yylval);
        advance();
        n->nodeType = "primary_expr";
        return n;
    }
    else if (tok == STRING)
    {
        past n = newVarRef(tok, 3);
        advance();
        n->nodeType = "primary_expr";
        return n;
    }
    return NULL;
}

past astExpr_list()
{
    past l = ast_expr();
    if (l != NULL)
    {
        if (tok == ',')
        {
            past r = astExpr_list();
            if (r != NULL)
            {
                l = newExpr(',', l, r);
            }
        }
    }
    l->nodeType = "expr_list";
    return l;
}

past astId_list()
{
    if (tok == ID)
    {
        past l = newVarRef(tok, 2);
        advance();
        if (tok == ',')
        {
            past r = astId_list();
            if (r != NULL)
            {
                l = newExpr(',', l, r);
            }
        }
        l->nodeType = "id_list";
        return l;
    }
    return NULL;
}

void showAst(past node, int nest)
{
    if (node == NULL)
        return;

    if (node->ivalue != -11)
    {
        int i = 0;
        for (i = 0; i < nest; i++)
            printf("   ");
        if (strcmp(node->nodeType, "ch") == 0)
        {
            printf("%s %c\n", node->nodeType, (char)node->ivalue);
        }
        else if (strcmp(node->nodeType, "intValue") == 0)
        {
            printf("%s %d\n", node->nodeType, node->ivalue);
        }
        else if(strcmp(node->nodeType,"program") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"external_declaration") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"decl_or_stmt") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"declarator_list") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"intstr_list") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"initializer") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"declarator") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"parameter_list") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"parameter") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"type") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"statement") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"statement_list") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"expression_statement") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"expr") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"cmp_expr") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"add_expr") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"mul_expr") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"primary_expr") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"expr_list") == 0)
            printf("%s\n", node->nodeType);
        else if(strcmp(node->nodeType,"id_list") == 0)
            printf("%s\n", node->nodeType);
        else
        {
            printf("%s ", node->nodeType);
            switch (node->ivalue)
            {
            case 258:printf("INT\n");break;
            case 259:printf("STR\n");break;
            case 260:printf("VOID\n");break;
            case 261:printf("ID\n");break;
            case 262:printf("IF\n");break;
            case 263:printf("ELSE\n");break;
            case 264:printf("WHILE\n");break;
            case 265:printf("RETURN\n");break;
            case 266:printf("PRINT\n");break;
            case 267:printf("SCAN\n");break;
            case 268:printf("STRING\n");break;
            case 269:printf("ASSIGN\n");break;
            case 270:printf("CMP\n");break;
            case 271:printf("NUMBER\n");break;
            case 272:printf("EOL\n");break;
            default:
                break;
            }
        }
    }
    showAst(node->left, nest + 1);
    showAst(node->right, nest + 1);
}

int main(int argc, char **argv)
{
    openInput(argc, argv);
    yyin = fpIn;
    advance();
    past rr = astProgram();
    showAst(rr, 0);

    return 0;
}