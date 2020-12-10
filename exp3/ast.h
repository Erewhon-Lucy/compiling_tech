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

typedef struct _ast ast;
typedef struct _ast *past;

extern int yylex();
extern int yylval;
extern char *yytext;
extern FILE *yyin;
FILE *fpIn;

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