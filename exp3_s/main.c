#include <stdio.h>
#include "ast.h"
extern FILE *yyin;
past yyparse();

FILE *fpIn;

void openInput(int argc, char *argv[])
{
    fpIn = NULL;
    if (argc > 1)
    {
        if ((fpIn = fopen(argv[1], "r")) == NULL)
        {
            fprintf(stderr, "Error opening input file:  %s", argv[1]);
        }
    }
    else
        fpIn = stdin;
}

void closeInput(FILE *in)
{
    fclose(in);
}

int main(int argc, char ** argv) {
    openInput(argc, argv);
    yyin = fpIn;
    yyparse();
    return 0;
}