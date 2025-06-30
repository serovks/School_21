#include "io.h"

#include <string.h>

#include "node.h"
#include "stack.h"

int get_expr(char *input_expr, int bufsize) {
    int len = 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        input_expr[len++] = (char)ch;
        if (len == bufsize) {
            bufsize *= 2;
            char *temp = realloc(input_expr, bufsize);
            if (!temp) {
                free(input_expr);
                printf("n/a");
                return 1;
            }
            input_expr = temp;
        }
    }
    input_expr[len] = '\0';
    return 0;
}

int my_isfunc(const char *str) {
    const char *funcs[6] = {"cos", "sin", "tg", "ctg", "sqrt", "ln"};

    for (int i = 0; i < 6; i++) {
        if (!strcmp(str, funcs[i])) {
            return 1;
        }
    }

    return 0;
}

int valid_input(const char *input_str) {
    Node *stack = new_Stack();
    int i = 0;
    int len = my_strlen(input_str);

    while (i < len) {
        char c = input_str[i];
        if (!my_isspace(c)) {
            if (my_isalpha(c) && i + 2 < len) {
                Token function = read_func(input_str, &i);
                if (!my_isfunc(function.value.func)) {
                    free_stack(stack);
                    return 1;
                }
            } else if (c == 'x') {
                //
            } else if (!my_isdigit(c) && !my_isoper(c) && c != '(' && c != ')') {
                free_stack(stack);
                return 1;
            }

            if (c == '(') {
                if (i + 1 < len && input_str[i + 1] == ')') {
                    free_stack(stack);
                    return 1;
                }
                Token *left_paren = malloc(sizeof(Token));
                if (!left_paren) {
                    free_stack(stack);
                    return 1;
                }
                *left_paren = (Token){.type = TOKEN_LEFT_PAREN, .value.op = '('};
                push(stack, left_paren);
            } else if (c == ')') {
                if (is_empty(stack)) {
                    free_stack(stack);
                    return 1;
                }
                Maybe top_maybe = peek(stack);
                if (is_nothing(top_maybe)) {
                    free_stack(stack);
                    return 1;
                }
                Token *top_token = (Token *)top_maybe.value;
                if (top_token->type != TOKEN_LEFT_PAREN) {
                    free_stack(stack);
                    return 1;
                }
                Token *popped = (Token *)pop(stack).value;
                free(popped);
            }
        }
        i++;
    }

    if (!is_empty(stack)) {
        while (!is_empty(stack)) {
            Token *popped = (Token *)pop(stack).value;
            free(popped);
        }
        free_stack(stack);
        return 1;
    }

    free_stack(stack);
    return 0;
}
