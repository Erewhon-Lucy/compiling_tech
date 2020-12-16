
#include <stdio.h>
#include "ast.h"
ast yyparse();

void yyerror(char *c) {
    printf("%s\n", c);
}

int main() {
        yyparse();
        return 0;
}