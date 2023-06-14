#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "scan.h"


int main(void) {
    
    FILE *fp = fopen("test.txt", "r");
    
    char d;
    while((d = getc(fp)) != EOF) {
        ungetc(d, fp);
        printf("%s", TOKEN_STRING[scan_token(fp)]);
    }
    printf("\n");
}