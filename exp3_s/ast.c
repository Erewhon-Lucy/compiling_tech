#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ast.h"

void showAst(past node, int nest)
{
    if(node == NULL)
        return;
    int i = 0;
    for(i = 0; i < nest; i ++)
        printf("    ");
    if(strcmp(node->nodeType,"program") == 0)//实际上忽略
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"external_declaration") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"function_definition") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"declaration") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"init_declarator_list") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"init_declarator") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"intstr_list") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"initializer") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"declarator") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"direct_declarator") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"parameter_list") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"parameter") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"type") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"statement") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"compound_statement") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"begin_scope") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"end_scope") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"statement_list") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"expression_statement") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"selection_statement") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"iteration_statement") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"jump_statement") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"print_statement") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"scan_statement") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"expr") == 0)
        printf("%s\n", node->nodeType);
    else if(strcmp(node->nodeType,"assign_expr") == 0)
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
    else if(strcmp(node->nodeType, ",") == 0)
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
}

// past newNum(int num)
// {
//     past l = newAstNode();
//     l->nodeType = "NUMBER";
//     l->ivalue = num;
// }

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

past unite(char *ch,past c1,past c2,past c3,past c4,past c5,past c6,past c7,past c8){
    past leader = newAstNode();
    leader->nodeType = ch;
    leader->child1 = c1;
    leader->child2 = c2;
    leader->child3 = c3;
    leader->child4 = c4;
    leader->child5 = c5;
    leader->child6 = c6;
    leader->child7 = c7;
    return leader;
}

past newTerminal(char *ch){
    past l = newAstNode();
    l->nodeType = ch;
    return l;
}