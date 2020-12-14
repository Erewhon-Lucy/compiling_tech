#include <stdio.h>

extern FILE* yyin;
extern int yyparse();
extern void showAst();
extern struct AST* root;

int main(){
	 char path[50];
	 printf("Enter the path:");
	 scanf("%s",path);
	 yyin = fopen(path,"r");
	 yyparse();
	 showAst(root,0);
	 return 0;

}
