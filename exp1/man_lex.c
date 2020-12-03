#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>

#define N 1000000

bool isInteger(char *str);
bool isKeyword(char temp[]);
bool isIdentifier(char *str);
bool isOperator(char *temp);
bool isComment(char *str);
void parse(char *str);


int main(int argc, char const *argv[]) {
	FILE *fp;
	fp = fopen("rubik.txt","r");
    freopen("result.txt","w",stdout);
    
    if(fp == NULL) {
		printf("error while opening the file\n");
		exit(0);
	}

    char str[N];
    char ch;
    for (int i = 0; ch = fgetc(fp) != EOF; i++) {
        str[i] = fgetc(fp);
    }

    parse(str); // calling the parse function 
    
    fclose(fp);
    fclose(stdout);
    return (0); 
}

void parse(char *str) {
    int len = strlen(str);

    while (*str != EOF)
    {
        for (int i = 0; i < len ; i++) {
            if(str[i] == ' '|'\n'|'\t')
                printf("");   
            
            if(isInteger(str)) {
                printf("integer: %s\n", str);
            }

            // else if(isIdentifier(str)) {
            //     printf("identifier: %s\n", str);
            // }

            else if(isKeyword(str)) {
                printf("keyword: %s\n", str);
            }

            else if(isOperator(str)) {
                printf("operator: %s\n", str);
            }

            // else if(isComment(str)) {
            //     printf("comment: %s\n", str);
            // }
        }
    }
}

bool isInteger(char *str) {
	int i, len = strlen(str);

	if (len == 0) 
        return false;

    for (i = 0; i < len; i++) { 
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0)) 
            return false; 
    } 
    return true; 
}

bool isIdentifier(char *str) {
    return true;
}

bool isKeyword(char temp[]) {
	int i = 0;

	char keyword[32][12] = {"return", "continue", "extern", "static", "long", "signed",
                               "switch", "char", "else", "unsigned", "if", "struct",
                               "union", "goto", "while", "float", "enum", "sizeof", "double", "volatile",
                               "const", "case", "for", "break", "void", "register", "int",
                               "do", "default", "short", "typedef", "auto"};
    for(i = 0; i < 32; i++) {
    	if(strcmp(keyword[i], temp) == 0) {
    		return true;
    	}
    }

    return false;          
}

bool isOperator(char *temp) {
	int flag = 0;
	int i = 0;
	char* operator[20]={"<",">","!=",">=","<=","==",",","(",")","+","-","*","/","=","!","||","&&",".","&"};
	for(i = 0; i < 32; i++) {
		if(strcmp(operator[i], temp) == 0) {
			return true;
		}
	}
	return false;
}

bool isComment(char *str) {
    if (*str == '/') {
        
        
        if (*str == '\n') {
            
        }
    }

    return true;
}