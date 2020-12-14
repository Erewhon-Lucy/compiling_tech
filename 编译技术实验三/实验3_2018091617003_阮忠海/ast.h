#ifndef AST_
#define AST_
int flag;
extern int yylineno;
extern char* text;
void yyerror(char* s,...);
struct AST{
	char* value;
	char* name;
	struct AST *l;
	struct AST *r;
};

struct AST *newnode(char* name,char* value,int num,...);

void showAst(struct AST*,int level);

#endif
