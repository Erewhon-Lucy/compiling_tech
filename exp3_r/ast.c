#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "ast.h"

struct AST *newnode(char* name, char* value,int num,...){
    va_list valist;//define parameters list
    struct AST *a = (struct AST*)malloc(sizeof(struct AST));
    struct AST *temp = (struct AST*)malloc(sizeof(struct AST));
    if(a == NULL){
        printf("out of space!");
        exit(0);
    }
    a->value = (char*)malloc(sizeof(char)*50);
    if(value)
	    strcpy(a->value,value);
    else
	    strcpy(a->value,".");
    a->name = name;
    va_start(valist,num);
    temp = va_arg(valist,struct AST*);
    a->l = temp;
    if(num > 1){
	int i;
        for(i = 0;i < num-1;i++){
            temp->r = va_arg(valist,struct AST*);
            temp = temp->r;
        }
    }
    return a;
}

void showAst(struct AST* a,int level){
    if(a != NULL){
	int i;
        for(i = 0;i < level;i++){
            printf("  ");
        }
        printf("%s",a->name);
	if(strcmp(a->name,"NUMBER")==0||strcmp(a->name,"STRING")==0||strcmp(a->name,"ID")==0){
	    printf("：%s",a->value);
	}
        printf("\n");
        showAst(a->l,level+1);
        showAst(a->r,level);
    }
}

