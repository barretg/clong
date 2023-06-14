#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "scan.h"

Token scan_token( FILE *fp ) {
    int c = fgetc(fp);
    char d;

    switch(c) {
        case '*':
            return TOKEN_MULT;
        case '+':
            return TOKEN_ADD;
        case '-':
            return TOKEN_SUB;
        case '/':
            return TOKEN_DIV;
        case '=':
            return TOKEN_EQ;
        case '!':
            d = fgetc(fp);
            if(d == '=') {
                return TOKEN_NEQ;
            } else {
                ungetc(d, fp);
                return TOKEN_NOT;
            }
    }
    
    if (isspace(c)){
        return TOKEN_SPACE;
    } else if(isalnum(c)) {
        bool num = true;
        char d = c;
        do {
            if(!isdigit(d)){
                num = false;
            }
            d = fgetc(fp);
        } while(isalnum(d));
        ungetc(d, fp);
        return num ? TOKEN_NUM : TOKEN_ID;
    } else {
        return TOKEN_ERR;
    }
}