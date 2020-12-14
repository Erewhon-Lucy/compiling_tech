/*
 * ast.c
 *
 *  Created on: 2014年10月23日
 *      Author: erqiang
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
enum yytokentype {
    EOL = 258,
    NUMBER = 259,
    STRING = 260,
    ID = 261,
    INT = 262,
    STR = 263,
    VOID = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    RETURN = 268,
    PRINT = 269,
    SCAN = 270,
    ASSIGN = 271, /* 类似+=的复合赋值 */ 
    CMP = 272,
    SCOPE = 273
};
void showAst(past node, int nest)
{
	if(node == NULL)
		return;

	int i = 0;
	for(i = 0; i < nest; i ++)
		printf("  ");
	  if(strcmp(node->nodeType, " ") == 0){
      	nest--;
      }
	else if(strcmp(node->nodeType, "intValue") == 0)
		  printf("%s %d\n", node->nodeType, node->ivalue);
	 else if(strcmp(node->nodeType, "expr") == 0)
		  printf("%s '%c'\n", node->nodeType, (char)node->ivalue);
    else if(strcmp(node->nodeType, "expr_list") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "Cmp_expr") == 0)
		  printf("%s %c\n", node->nodeType, node->ivalue);
    else if(strcmp(node->nodeType, "intstr_list") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "dircet_declarator") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "primary_expr") == 0)
		  printf("%s \n", node->nodeType);  
    else if(strcmp(node->nodeType, "declaration") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "newDeclarator") == 0)
		  printf("%s %c\n", node->nodeType, (char)node->ivalue);
    else if(strcmp(node->nodeType, "declaration_list") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "parameter_list") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "parameter") == 0)
		printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "compound_statement") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "statement_list") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "IF_stmt") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "IF_ELSE") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "ELSE_stmt") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "WHILE_stmt") == 0)
		  printf("%s \n", node->nodeType);
    else if(strcmp(node->nodeType, "RET_stmt") == 0)
		  printf("%s \n", node->nodeType);
    else if(node->ivalue == INT)
        printf("%s  %d\n", node->nodeType, node->ivalue);
    else if(node->ivalue == IF)
        printf("%s  %d\n", node->nodeType, node->ivalue);
    else if(node->ivalue == ELSE)
        printf("%s  %d\n", node->nodeType, node->ivalue);
    else if(node->ivalue == WHILE)
        printf("%s  %d\n", node->nodeType, node->ivalue);
    else if(node->ivalue == STR)
        printf("%s  %d\n", node->nodeType, node->ivalue);
    else if(node->ivalue == VOID)
        printf("%s  %d\n", node->nodeType, node->ivalue);
    else if(node->ivalue == SCOPE)
        printf("%s  %d\n", node->nodeType, node->ivalue);
    else if(node->ivalue == ID)
        printf("ID: %s\n", node->nodeType);
    else if(node->ivalue == RETURN)
        printf("RET: %s\n", node->nodeType);
    else if(node->ivalue == CMP)
        printf("CMP: %s\n", node->nodeType);
    else if(node->ivalue == STRING)
        printf("STR: %s\n", node->nodeType);
	showAst(node->left, nest+1);
	showAst(node->right, nest+1);
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
    node->nodeType = " ";
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
past new_Expr(past oper, past left, past right)
{
    
	past var = newAstNode();
    past var1 = newAstNode();
    var1->left = oper;
	var->left = left;
	var->right = right;
    var1->right = var;
	return var1;
}
past newExpr_list( past left, past right) {
    past var = newAstNode();
    var->left = left;
    var->right = right;
    var->nodeType = "expr_list";
    return var;
}
past newMul(int oper, past var) {
    past p = newAstNode();
    p = var;
    p->ivalue = oper;
    p->nodeType = "expr";
    return p;
}

past newPrim(past left, past right) {
    past var = newAstNode();
    var->left = left;
    var->right = right;
    var->nodeType = "primary_expr";
    return var;
}
past newID(char* id) {
//    printf("%s\n", id);
    past var = newAstNode();
    var->ivalue = ID;
    var->nodeType = (char*)malloc(10);
    strcpy(var->nodeType, id);
    return var;
}
past newASSIGN(char* id) {
//    printf("%s\n", id);
    past var = newAstNode();
    var->ivalue = ASSIGN;
    var->nodeType = (char*)malloc(10);
    strcpy(var->nodeType, id);
    return var;
}
past newCMP(char* id) {
//    printf("%s\n", id);
    past var = newAstNode();
    var->ivalue = CMP;
    var->nodeType = (char*)malloc(10);
    strcpy(var->nodeType, id);
    return var;
}
past newInt(char* _int) {
    past var = newAstNode();
    var->ivalue = INT;
    var->nodeType = "int";
    return var;
}
past newSTR(char* str) {
    past var = newAstNode();
    var->ivalue = STR;
    var->nodeType = "str";
    return var;
}

past newVOID(char* _void) {
    past var = newAstNode();
    var->ivalue = VOID;
    var->nodeType = "void";
    return var; 
}

past newDecl(past left, past right) {
    past var = newAstNode();
    var->left = left;
    var->right = right;
    var->nodeType = "declaration";
    return var;
}
past newDecl_list(past left, past right) {
    past var = newAstNode();
    var->left = left;
    var->right = right;
    var->nodeType = "declarator_list";
    return var;
}
past newAss_expr_1(int oper, past var1,past var2, past var3) {
        past var = newAstNode();
        past varp = newAstNode();
        var->left = var1;
        var->right=var2;
        var->nodeType = " ";
        varp->ivalue = oper;
        varp->nodeType = "assign_expr_4";
        varp->left = var;
        varp->right = var3;
        return varp;
}

past newCmp(past left, past oper, past right) {
    past var = newAstNode();
    past var1 = newAstNode();
	var->nodeType = "Cmp_expr";
    var1->left = oper;
	var->left = left;
	var->right = right;
    var1->right = var;
	return var1;
}
past newDeclarator(int oper, past left, past right) {
    past var = newAstNode();
    var->nodeType = "newDeclarator";
    var->ivalue = oper;
    var->left = left;
    var->right = right;
    return var;
}

past newSTRING(char* str) {
    past var = newAstNode();
    var->nodeType = (char*)malloc(100);
    strcpy(var->nodeType, str);
    var->ivalue = STRING;
    return var;
}

past newIntstr(past left, past right) {
    past var = newAstNode();
    var->nodeType = "intstr_list";
    var->left = left;
    var->right = right;
    return var;
}

past newEmptyComp(char* l, char* r){
    past var = newAstNode();
    var->left = newAstNode();
    var->right = newAstNode();
    var->nodeType = "compound_statement";
    var->left->ivalue = SCOPE;
    var->left->nodeType = "{";
    var->right->ivalue = SCOPE;
    var->right->nodeType = "}";
    return var;
}

past newComp(char *l, past mid, char *r) {
    past var = newAstNode();
    var->left = newAstNode();
    var->right = newAstNode();
    var->nodeType = "compound_statement";
    var->left->ivalue = SCOPE;
    var->left->nodeType = " ";
    var->right->nodeType = " ";
    var->left->right = mid;
    var->left->nodeType = "{";
    var->right->ivalue = SCOPE;
    var->right->nodeType = "}";
    return var;
}

past newStat_list(past left, past right) {
    past var = newAstNode();
    var->nodeType = "statement_list";
    var->left = left;
    var->right = right;
    return var;
}

past newFunc(past left, past middle, past right){
    past var = newAstNode();
    past _var = newAstNode();
    var->left = middle;
    var->right =right;
    var->nodeType = " ";

    _var->left = left;
    _var->right = var;
    _var->nodeType = "function_declarator";
    return _var;
}
past newIf_stmt(char *_if, past var2, past var3) {
    past var = newAstNode();
    var->nodeType = "IF_stmt";
    var->ivalue = IF;
    var->left = var2;
    var->right = var3;
    return var;
}

past newIf_Else(char *_if, past var1, past var2, char* _else, past var3){
    past var = newAstNode();
    var->nodeType = "IF_ELSE";
    var->left = newAstNode();
    var->left->nodeType = "IF_stmt";
    var->left->ivalue = IF;
    var->left->left = var1;
    var->left->right = var2;
    var->right = var3;
    var->right->ivalue = ELSE;
    var->right->nodeType = "ELSE_stmt";
    return var;
}

past newWhile(char* _while, past var1, past var2) {
    past var = newAstNode();
    var->nodeType = "WHILE_stmt";
    var->ivalue = WHILE;
    var->left = var1;
    var->right = var2;
    return var;
}
past newRET(char* _ret, past var1) {
    past var = newAstNode();
    var->nodeType = "RET_stmt";
    var->ivalue = RETURN;
    var->left = var1;
    var->right = NULL;

    return var;
}

past newPrint(char* _print, past p) {
    past var = newAstNode();
    var->nodeType = "PRINT_stmt";
    var->ivalue = PRINT;
    var->left = p;
    var->right = NULL;
    return var;
}

past newScan(char* _print, past p) {
    past var = newAstNode();
    var->nodeType = "SCAN_stmt";
    var->ivalue = SCAN;
    var->left = p;
    var->right = NULL;
    return var;
}
past newDir_dec(past left, past right) {
    past var = newAstNode();
    var->nodeType = "dircet_declarator";
    var->left = left;
    var->right = right;
    return var;
}
past newPara_list(past left, past right) {
    past var = newAstNode();
    var->nodeType = "parameter_list";
    var->left = left;
    var->right = right;
    return var;
}

past newPara(past left, past right) {
    past var = newAstNode();
    var->nodeType = "parameter";
    var->left = left;
    var->right = right;
    return var;
}