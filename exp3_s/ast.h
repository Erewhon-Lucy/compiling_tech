#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// enum yytokenType
// {
//     INT = 258,
//     STR = 259,
//     VOID = 260,
//     ID = 261,
//     IF = 262,
//     ELSE = 263,
//     WHILE = 264,
//     RETURN = 265,
//     PRINT = 266,
//     SCAN = 267,
//     STRING = 268,
//     ASSIGN = 269,
//     CMP = 270,
//     NUMBER = 271,
//     EOL = 272
// };

typedef struct _ast ast;
typedef struct _ast *past;
struct _ast{
    char *nodeType;
    int atri_value;
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