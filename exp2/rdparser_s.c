//
//  main.c
//  rdparser
//
//  Created by Jackie shi on 2020/12/6.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum yytokenType{ID = 258,NUMBER = 259,ELSE = 260,EOL = 261,STRING = 262,CMP = 264,RETURN = 265,IF = 266,PRINT = 267,SCAN = 268,WHILE = 269,INT = 270, STR = 271, VOID = 272};
extern int yylex();
extern int yylval;
extern char *yytext;
extern FILE *yyin;
int token;


typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
    //结点类型
    char *nodeType;
    //属性值
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
past connect();

void advance();
past astId_list();

void advance(){
    token = yylex();
}

//新建结点,初始化
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

past astId_list(){
    if(token == ID){
        past l1 = newTerminal("ID");
        advance();
        while(token == ','){
            past l2 = newTerminal(",");
            advance();
            if(token == ID){
                past l3 = newTerminal("ID");
                l1 = connect("id_list",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                advance();
            }
            else{
                return NULL;
            }
        }
        return l1;
    }
    else{
        return NULL;
    }
}

past astExpr_list(){
    past l1 = astExpr();
    if(l1 != NULL){
        while(token == ','){
            past l2 = newTerminal(",");
            advance();
            past l3 = astExpr();
            if(l3 != NULL){
                l1 = connect("expr_list",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
            }
            else{
                return NULL;
            }
        }
        return l1;
    }
    else{
        return NULL;
    }
}

past astPrimary_expr(){
    if(token == ID){
        past l1 = newTerminal("ID");
        advance();
        switch (token) {
            case '(':{
                past l2 = newTerminal("(");
                advance();
                if(token == ')'){
                    past l3 = newTerminal(")");
                    advance();
                    l1 = connect("primary_expr",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                    return l1;
                }
                else{
                    past l3 = astExpr_list();
                    if(token == ')'){
                        past l4 = newTerminal(")");
                        advance();
                        l1 = connect("primary_expr",l1,l2,l3,l4,NULL,NULL,NULL,NULL);
                        return l1;
                    }
                }
                break;
            }
            case '=':{
                past l2 = newTerminal("=");
                advance();
                past l3 = astExpr();
                l1 = connect("primary_expr",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                return l1;
                break;
            }
            case '[':{
                past l2 = newTerminal("[");
                advance();
                past l3 = astExpr();
                if(token == ']'){
                    past l4 = newTerminal("]");
                    advance();
                    if(token == '='){
                        past l5 = newTerminal("=");
                        advance();
                        past l6 = astExpr();
                        l1 = connect("primary_expr",l1,l2,l3,l4,l5,l6,NULL,NULL);
                        return l1;
                    }
                    else{
                        l1 = connect("primary_expr",l1,l2,l3,l4,NULL,NULL,NULL,NULL);
                        return l1;
                    }
                }
                break;
            }
            default:{
                return l1;
            }
        }
    }else if(token == NUMBER){
        past l1 = newTerminal("NUMBER");
        advance();
        return l1;
    }else if(token == STRING){
        past l1 = newTerminal("STRING");
        advance();
        return l1;
    }else if(token == '('){
        past l1 = newTerminal("(");
        advance();
        past l2 = astExpr();
        if(token == ')'){
            past l3 = newTerminal(")");
            advance();
            l1 = connect("primary_expr",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
            return l1;
        }
    }else{
        return NULL;
    }
    return NULL;
}

past astMul_expr(){
    if(token == '-'){
        past l1 = newTerminal("-");
        advance();
        past l2 = astPrimary_expr();
        l1 = connect("mul_expr",l1,l2,NULL,NULL,NULL,NULL,NULL,NULL);
        return l1;
    }else{
        past l1 = astPrimary_expr();
        while(token == '*' || token == '/'|| token == '%'){
            if(token == '*'){
                past l2 = newTerminal("*");
                advance();
                past l3 = astPrimary_expr();
                l1 = connect("mul_expr",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
            }else if(token == '/'){
                past l2 = newTerminal("/");
                advance();
                past l3 = astPrimary_expr();
                l1 = connect("mul_expr",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
            }else if(token == '%'){
                past l2 = newTerminal("%");
                advance();
                past l3 = astPrimary_expr();
                l1 = connect("mul_expr",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
            }else{
                return NULL;
            }
        }
        return l1;
    }
}

past astAdd_expr(){
    past l1 = astMul_expr();
    while(token == '+' || token == '-'){
        if(token == '+'){
            past l2 = newTerminal("+");
            advance();
            past l3 = astMul_expr();
            l1 = connect("add_expr",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
        }else if(token == '-'){
            past l2 = newTerminal("-");
            advance();
            past l3 = astMul_expr();
            l1 = connect("add_expr",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
        }else{
            return NULL;
        }
    }
    return l1;
}

past astCmp_expr(){
    past l1 = astAdd_expr();
    while(token == CMP){
        past l2 = newTerminal("CMP");
        advance();
        past l3 = astAdd_expr();
        l1 = connect("cmp_expr",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
    }
    return l1;
}

past astExpr(){
    past l1 = astCmp_expr();
    return l1;
}

past astExpression_statement(){
    if(token == ';'){
        past l1 = newTerminal(";");
        advance();
        return l1;
    }
    else{
        past l1 = astExpr();
        if(token == ';'){
            past l2 = newTerminal(";");
            advance();
            l1 = connect("expression_statement",l1,l2,NULL,NULL,NULL,NULL,NULL,NULL);
            return l1;
        }else{
            return NULL;
        }
    }
}

//待斟酌
past astStatement_list(){
    past l1 = astStatement();
    if(l1 != NULL){
        past l2 = astStatement();
        while(l2 != NULL){
            l1 = connect("statement_list",l1,l2,NULL,NULL,NULL,NULL,NULL,NULL);
            l2 = astStatement();
        }
        return l1;
    }
    else{
        return NULL;
    }
}

past astStatement(){
    past l1 = astType();
    if(l1 != NULL){
        past l2 = astDeclarator_list();
        if(token == ';'){
            past l3 = newTerminal(";");
            advance();
            l1 = connect("statement",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
            return l1;
        }
        else{
            return NULL;
        }
    }
//    else{
//        l1 = astExpression_statement();
//        if(l1 != NULL){
//            return l1;
//        }
//        else{
//            return NULL;
//        }
//    }
    switch (token) {
        case '{':{
            l1 = newTerminal("{");
            advance();
            past l2 = astStatement_list();
            if(token == '}'){
                past l3 = newTerminal("}");
                advance();
                l1 = connect("statement",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                return l1;
            }
            else{
                return NULL;
            }
            break;
        }
        case IF:{
            l1 = newTerminal("IF");
            advance();
            if(token == '('){
                past l2 = newTerminal("(");
                advance();
                past l3 = astExpr();
                if(token == ')'){
                    past l4 = newTerminal(")");
                    advance();
                    past l5 = astStatement();
                    if(token == ELSE){
                        past l6 = newTerminal("ELSE");
                        advance();
                        past l7 = astStatement();
                        l1 = connect("statement",l1,l2,l3,l4,l5,l6,l7,NULL);
                        return l1;
                    }
                    else{
                        l1 = connect("statement",l1,l2,l3,l4,l5,NULL,NULL,NULL);
                        return l1;
                    }
                }
                else{
                    return NULL;
                }
            }
            else{
                return NULL;
            }
            break;
        }
        case WHILE:{
            l1 = newTerminal("WHILE");
            advance();
            if(token == '('){
                past l2 = newTerminal("(");
                advance();
                past l3 = astExpr();
                if(token == ')'){
                    past l4 = newTerminal(")");
                    advance();
                    past l5 = astStatement();
                    l1 = connect("statement",l1,l2,l3,l4,l5,NULL,NULL,NULL);
                    return l1;
                }
                else{
                    return NULL;
                }
            }
            else{
                return NULL;
            }
            break;
        }
        case RETURN:{
            l1 = newTerminal("RETURN");
            advance();
            if(token == ';'){
                past l2 = newTerminal(";");
                advance();
                l1 = connect("statement",l1,l2,NULL,NULL,NULL,NULL,NULL,NULL);
                return l1;
            }
            else{
                past l2 = astExpr();
                if(token == ';'){
                past l3 = newTerminal(";");
                    advance();
                    l1 = connect("statement",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                    return l1;
                }
                else{
                    return NULL;
                }
            }
            break;
        }
        case PRINT:{
            l1 = newTerminal("PRINT");
            advance();
            if(token == ';'){
                past l2 = newTerminal(";");
                advance();
                l1 = connect("statement",l1,l2,NULL,NULL,NULL,NULL,NULL,NULL);
                return l1;
            }
            else{
                past l2 = astExpr_list();
                if(token == ';'){
                    past l3 = newTerminal(";");
                    advance();
                    l1 = connect("statement",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                    return l1;
                }
                else{
                    return NULL;
                }
            }
            break;
        }
        case SCAN:{
            l1 = newTerminal("SCAN");
            advance();
            past l2 = astId_list();
            if(token == ';'){
                past l3 = newTerminal(";");
                advance();
                l1 = connect("statement",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                return l1;
            }
            else{
                return NULL;
            }
            break;
        }
        default:
            return NULL;
    }
}

past astType(){
    past l1;
    if(token == INT){
        l1 = newTerminal("INT");
        advance();
    }else if(token == STR){
        l1 = newTerminal("STR");
        advance();
    }else if(token == VOID){
        l1 = newTerminal("VOID");
        advance();
    }else{
        return NULL;
    }
    return l1;
}

past astParameter(){
    past l1 = astType();
    if(token == ID){
        past l2 = newTerminal("ID");
        advance();
        l1 = connect("parameter",l1,l2,NULL,NULL,NULL,NULL,NULL,NULL);
        return l1;
    }
    else{
        return NULL;
    }
}

past astParameter_list(){
    past l1 = astParameter();
    if(l1 != NULL){
        while(token == ','){
            past l2 = newTerminal(",");
            advance();
            past l3 = astParameter();
            if(l3 != NULL){
                l1 = connect("parameter_liat",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
            }
            else{
                return NULL;
            }
        }
        return l1;
    }
    else{
        return NULL;
    }
}

past astDeclarator(){
    if(token == ID){
        past l1 = newTerminal("ID");
        advance();
        switch (token) {
            case '=':{
                past l2 = newTerminal("=");
                advance();
                past l3 = astExpr();
                if(l3 != NULL){
                    l1 = connect("declarator",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                    return l1;
                }
                else{
                    return NULL;
                }
                break;
            }
            case '(':{
                past l2 = newTerminal("(");
                advance();
                if(token == ')'){
                    past l3 = newTerminal(")");
                    advance();
                    l1 = connect("declarator",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                    return l1;
                }
                else{
                    past l3 = astParameter_list();
                    if(l3 != NULL){
                        if(token == ')'){
                            past l4 = newTerminal(")");
                            advance();
                            l1 = connect("declarator",l1,l2,l3,l4,NULL,NULL,NULL,NULL);
                            return l1;
                        }
                        else{
                            return NULL;
                        }
                    }
                    else{
                        return NULL;
                    }
                }
                break;
            }
            case '[':{
                past l2 = newTerminal("[");
                advance();
                if(token == ']'){
                    past l3 = newTerminal("]");
                    advance();
                    if(token == '='){
                        past l4 = newTerminal("=");
                        advance();
                        if(token == '{'){
                            past l5 = newTerminal("{");
                            advance();
                            past l6 = astInstr_list();
                            if(l6 != NULL){
                                if(token == '}'){
                                    past l7 = newTerminal("}");
                                    advance();
                                    l1 = connect("declarator",l1,l2,l3,l4,l5,l6,l7,NULL);
                                    return l1;
                                }
                                else{
                                    return NULL;
                                }
                            }
                            else{
                                return NULL;
                            }
                        }
                        else{
                            return NULL;
                        }
                    }
                    else{
                        l1 = connect("declarator",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                        return l1;
                    }
                }
                else{
                    past l3 = astExpr();
                    if(l3 != NULL){
                        if(token == ']'){
                            past l4 = newTerminal("]");
                            advance();
                            if(token == '='){
                                past l5 = newTerminal("=");
                                advance();
                                if(token == '{'){
                                    past l6 = newTerminal("{");
                                    advance();
                                    past l7 = astInstr_list();
                                    if(l7 != NULL){
                                        if(token == '}'){
                                            past l8 = newTerminal("}");
                                            advance();
                                            l1 = connect("declarator",l1,l2,l3,l4,l5,l6,l7,l8);
                                            return l1;
                                        }
                                        else{
                                            return NULL;
                                        }
                                    }
                                    else{
                                        return NULL;
                                    }
                                }
                                else{
                                    return NULL;
                                }
                            }
                            else{
                                l1 = connect("declarator",l1,l2,l3,l4,NULL,NULL,NULL,NULL);
                                return l1;
                            }
                        }
                        else{
                            return NULL;
                        }
                    }
                    else{
                        return NULL;
                    }
                }
                break;
            }
            default:{
                return l1;
            }
        }
    }
    else{
        return NULL;
    }
}

past astInitializer(){
    if(token == NUMBER){
        past l1 = newTerminal("NUMBER");
        advance();
        return l1;
    }else if(token == STRING){
        past l1 = newTerminal("STRING");
        advance();
        return l1;
    }else{
        return NULL;
    }
}

past astInstr_list(){
    past l1 = astInitializer();
    if(l1 != NULL){
        while(token == ','){
            past l2 = newTerminal(",");
            advance();
            past l3 = astInitializer();
            if(l3 != NULL){
                l1 = connect("instr_list",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
            }
            else{
                return NULL;
            }
        }
        return l1;
    }
    else{
        return NULL;
    }
    return NULL;
}

past astDeclarator_list(){
    past l1 = astDeclarator();
    if(l1 != NULL){
        while(token == ','){
            past l2 = newTerminal(",");
            advance();
            past l3 = astDeclarator();
            if(l3 != NULL){
                l1 = connect("declarator_list",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
            }
            else{
                return NULL;
            }
        }
        return l1;
    }
    else{
        return NULL;
    }
    return NULL;
}

past astDecl_or_stmt(){
    switch (token) {
        case '{':{
            past l1 = newTerminal("{");
            advance();
            if(token == '}'){
                past l2 = newTerminal("}");
                advance();
                l1 = connect("decl_or_stmt",l1,l2,NULL,NULL,NULL,NULL,NULL,NULL);
                return l1;
            }
            else{
                past l2 = astStatement_list();
                if(l2 != NULL){
                    if(token == '}'){
                        past l3 = newTerminal("}");
                        advance();
                        l1 = connect("decl_or_stmt",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                        return l1;
                    }
                    else{
                        return NULL;
                    }
                }
                else{
                    return NULL;
                }
            }
            break;
        }
        case ',':{
            past l1 = newTerminal(",");
            advance();
            past l2 = astDeclarator_list();
            if(l2 != NULL){
                if(token == ';'){
                    past l3 = newTerminal(";");
                    advance();
                    l1 = connect("decl_or_stmt",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                    return l1;
                }
                else{
                    return NULL;
                }
            }
            else{
                return NULL;
            }
            break;
        }
        case ';':{
            past l1 = newTerminal(";");
            advance();
            return l1;
            break;
        }
        default:
            return NULL;
    }
    return NULL;
}

past astExternal_delcaration(){
    past l1 = astType();
    if(l1 != NULL){
        past l2 = astDeclarator();
        if(l2 != NULL){
            past l3 = astDecl_or_stmt();
            if(l3 != NULL){
                l1 = connect("external_declaration",l1,l2,l3,NULL,NULL,NULL,NULL,NULL);
                return l1;
            }
            else{
                return NULL;
            }
        }
        else{
            return NULL;
        }
    }
    else{
        return NULL;
    }
}

past astProgram(){
    past l1 = astExternal_delcaration();
    if(l1 != NULL){
        past l2 = astExternal_delcaration();
        while(l2 != NULL){
            l1 = connect("program",l1,l2,NULL,NULL,NULL,NULL,NULL,NULL);
            l2 = astExternal_delcaration();
        }
        return l1;
    }
    else{
        return NULL;
    }
}

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

int main(int argc, const char * argv[]) {
    advance();
    past l = astProgram();
    showAst(l,0);
    return 0;
}
