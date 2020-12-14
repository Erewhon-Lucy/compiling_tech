/*
 * ast.h
 *
 *  Created on: 2019/12/5
 *      Author: erqiang
 */


typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
	int ivalue;
	char *nodeType;
	past left;
	past right;
};

past newNum(int value);
past newExpr(int oper,past left, past right);
past newSTR(char* str);
past newVOID(char* _void) ;
past newExpr_list( past left, past right);
past newCmp(past left, past oper, past right);
past newEmptyComp(char* l, char* r);
past newNum(int value);
past newSTRING(char* str);
past newMul(int oper, past var);
past newPrim(past left, past right);
past newFunc(past left, past middle, past right);
past newDecl(past left, past right);
past newDecl_list(past left, past right);
past newDeclarator(int oper, past left, past right);
past newIntstr(past left, past right);
past newID(char * id);
past newID_list(past left, past right);
past newDir_dec(past left, past right);
past newPara_list(past left, past right);
past newPara(past left, past right);
past newInt(char* _int);
past newSTR(char* str);
past newWhile(char* _while, past var1, past var2);
past newStat_list(past left, past right);
past newIf_stmt(char *_if, past var2, past var3);
past newRET(char* _ret, past var1);
past newIf_Else(char *_if, past var1, past var2, char* _else, past var3);
past newPrint(char* _print, past p);
past newScan(char* _print, past p) ;
past newComp(char *l, past mid, char *r);
past newAss_expr_1(int oper, past var1,past var2, past var3);
void showAst(past node, int nest);
past new_Expr(past oper, past left, past right);
past newCMP(char* id);
past newASSIGN(char* id);