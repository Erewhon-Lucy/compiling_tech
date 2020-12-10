#include "ast.h"

void showAst(past node, int nest)
{
    if (node == NULL)
        return;

    if (node->ivalue != -11)
    {
        int i = 0;
        for (i = 0; i < nest; i++)
            printf("  ");

        if (strcmp(node->nodeType, "expr") == 0)
        {
            printf("%s %c\n", node->nodeType, (char)node->ivalue);
        }
        else if (strcmp(node->nodeType, "intValue") == 0)
        {
            printf("%s %d\n", node->nodeType, node->ivalue);
        }
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
    var->nodeType = "expr";
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