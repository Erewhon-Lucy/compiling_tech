#include "ast.h"

void showAst(past node, int nest)
{
    if(node == NULL)
        return;
    int i = 0;
    for(i = 0; i < nest; i ++)
        printf("  ");
    if(strcmp(node->nodeType, ",") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "=") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "]") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "[") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "(") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, ")") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "-") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "+") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "*") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "/") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "%") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, ";") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "{") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "}") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "ID") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "NUMBER") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "STRING") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "CMP") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "IF") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "RETURN") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "PRINT") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "SCAN") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "WHILE") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "INT") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "VOID") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType, "STR") == 0)
        printf("%s\n", node->nodeType);
    
    showAst(node->child1, nest+1);
    showAst(node->child2, nest+1);
    showAst(node->child3, nest+1);
    showAst(node->child4, nest+1);
    showAst(node->child5, nest+1);
    showAst(node->child6, nest+1);
    showAst(node->child7, nest+1);
    showAst(node->child8, nest+1);
}

past newAstNode()
{
    past node = malloc(sizeof(ast));
    if(node == NULL)
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
    var->child1 = value;
    return var;
}

past connect(char *ch,past c1,past c2,past c3,past c4,past c5,past c6,past c7,past c8){
    past leader = newAstNode();
    leader->nodeType = ch;
    leader->child1 = c1;
    leader->child2 = c2;
    leader->child3 = c3;
    leader->child4 = c4;
    leader->child5 = c5;
    leader->child6 = c6;
    leader->child7 = c7;
    leader->child8 = c8;
    return leader;
}

past newTerminal(char *ch){
    past l = newAstNode();
    l->nodeType = ch;
    return l;
}