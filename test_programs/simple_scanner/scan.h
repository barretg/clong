typedef enum {
    TOKEN_MULT,
    TOKEN_ADD,
    TOKEN_SUB,
    TOKEN_DIV,
    TOKEN_EQ,
    TOKEN_NOT,
    TOKEN_NEQ,
    TOKEN_NUM,
    TOKEN_ID,
    TOKEN_SPACE,
    TOKEN_ERR,
} Token;

static const char *TOKEN_STRING[] = {
    "*", "+", "-", "/", "=", "!", "!=", "num", "id", " ", "err"
};

Token scan_token( FILE *fp );