#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
    char *nodeType;
    int atri_value;
    past child1;
    past child2;
    past child3;
    past child4;
    past child5;
    past child6;
    past child7;
    past child8;
};

past astId_list();
past astExpr_list();
past astPrimary_expr();
past astMul_expr();
past astAdd_expr();
past astCmp_expr();
past astExpr();
past astExpression_statement();
past astStatement_list();
past astStatement();
past astType();
past astParameter();
past astParameter_list();
past astDeclarator();
past astInitializer();
past astInstr_list();
past astDeclarator_list();
past astDecl_or_stmt();
past astExternal_delcaration();
past astProgram();
void showAst();
void advance();
past newTerminal();
past newAstNode();
past newNum();
past connect();

void advance();
past astId_list();