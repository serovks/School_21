#ifndef PARSER_H
#define PARSER_H
#include "node.h"

typedef enum {          // типа структуры но пронумерованное
    TOKEN_NUM,          // = 0
    TOKEN_OPERATOR,     // = 1
    TOKEN_FUNCTION,     // = 2
    TOKEN_VARIABLE_X,   // = 3
    TOKEN_LEFT_PAREN,   // = 4
    TOKEN_RIGHT_PAREN,  // = 5
    TOKEN_END           // = 6
} TokenType;

typedef struct {
    TokenType type;
    union {            // типа структуры но хранит только что-то одно
        double num;    // Для чисел
        char op;       // Для операторов: '+', '-', '*', '/', '^', ' ', 'x', '\0'
        char func[4];  // Для функций: "sin", "cos", и т.д.
    } value;
} Token;

int valid_input(const char *input_str);  // str -> bool 1/0
Token *rpn_convert(const char *infix_expr,
                   int *output_index);  // infix -> reverse_polish_notation (rpn)
double rpn_calculate(Token *rpn_root, int n, double x);
// helpers:
int get_priority(char op);
int get_token_priority(Token t);
int my_isdigit(char c);
int my_isspace(char c);
int my_isoper(char c);
int my_isalpha(int c);
int my_strlen(const char *str);
Token read_num(const char *infix_expr, int *i);
Token read_func(const char *infix_expr, int *i);

#endif
