typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
    char *nodeType;
    int ivalue;
    past child1;
    past child2;
    past child3;
    past child4;
    past child5;
    past child6;
    past child7;
};

void showAst();
void advance();
past newTerminal();
past newAstNode();
past newNum();
past connect();