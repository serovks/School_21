#include "parser.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mat.h"
#include "monads.h"
#include "stack.h"

int get_priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Для функций 4
int get_token_priority(Token t) {
    if (t.type == TOKEN_FUNCTION) return 4;
    if (t.type == TOKEN_OPERATOR) return get_priority(t.value.op);
    return 0;
}

int my_isdigit(char c) {
    if (strchr("1234567890", c) || c == '.') {
        return 1;
    }
    return 0;
}

int my_isspace(char c) { return c == ' '; }

int my_isoper(char c) {
    if (strchr("+-*/^", c)) {
        return 1;
    }
    return 0;
}

Token read_num(const char *infix_expr, int *i) {
    char num_str[16];
    int num_pos = 0;
    while (my_isdigit(infix_expr[*i])) {
        num_str[num_pos++] = infix_expr[(*i)++];
    }

    num_str[num_pos] = '\0';
    double num = atof(num_str);
    Token number = {.type = TOKEN_NUM, .value.num = num};

    return number;
}

Token read_func(const char *infix_expr, int *i) {
    char func_str[4];
    int pos = 0;
    while (my_isalpha(infix_expr[*i])) {
        func_str[pos++] = infix_expr[(*i)++];
    }

    func_str[pos] = '\0';
    Token func = {.type = TOKEN_FUNCTION, .value.func = {0}};
    strcpy(func.value.func, func_str);

    return func;
}

int my_isalpha(int c) { return (c >= 'a' && c <= 'z' && c != 'x'); }

int my_strlen(const char *str) {  // нужна инт а не саййзт
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// infix -> reverse_polish_notation (rpn)
Token *rpn_convert(const char *infix_expr, int *output_index) {
    Node *stack = new_Stack();
    Token *output = (Token *)calloc(256, sizeof(Token));
    int i = 0;
    *output_index = 0;

    while (infix_expr[i] != '\0') {
        char c = infix_expr[i];
        if (!my_isspace(c)) {  // ignore spaces

            if (my_isdigit(c)) {
                Token token = read_num(infix_expr, &i);
                output[(*output_index)++] = token;
                i--;  // compensate for i++ at end
            }

            else if (c == 'x') {
                Token *var_x = malloc(sizeof(Token));
                *var_x = (Token){.type = TOKEN_VARIABLE_X, .value.op = 'x'};
                push(stack, var_x);
            }

            else if (my_isoper(c)) {
                while (!is_empty(stack)) {
                    Maybe top_maybe = peek(stack);
                    if (is_nothing(top_maybe)) break;

                    Token *top_token = (Token *)top_maybe.value;
                    if (top_token->type != TOKEN_OPERATOR) break;
                    if (get_token_priority(*top_token) < get_priority(c)) break;

                    Token *popped = (Token *)pop(stack).value;
                    output[(*output_index)++] = *popped;
                    free(popped);
                }

                Token *op_token = malloc(sizeof(Token));
                *op_token = (Token){.type = TOKEN_OPERATOR, .value.op = c};
                push(stack, op_token);
            }

            else if (c == '(') {
                Token *left_paren = malloc(sizeof(Token));
                *left_paren = (Token){.type = TOKEN_LEFT_PAREN, .value.op = c};
                push(stack, left_paren);
            }

            else if (c == ')') {
                while (!is_empty(stack)) {
                    Maybe top_maybe = pop(stack);
                    if (is_nothing(top_maybe)) break;
                    Token *t = (Token *)top_maybe.value;
                    if (t->type == TOKEN_LEFT_PAREN) {
                        free(t);
                        break;
                    }
                    output[(*output_index)++] = *t;
                    free(t);
                }
            }

            else if (my_isalpha(c) && i + 2 < my_strlen(infix_expr)) {
                Token token = read_func(infix_expr, &i);
                Token *func_token = malloc(sizeof(Token));
                *func_token = token;
                push(stack, func_token);
            }
        }
        i++;
    }

    // Pop remaining tokens from stack
    while (!is_empty(stack)) {
        Maybe top_maybe = pop(stack);
        if (is_nothing(top_maybe)) break;
        Token *t = (Token *)top_maybe.value;
        output[(*output_index)++] = *t;
        free(t);
    }

    Token end = {.type = TOKEN_END, .value.op = '\0'};
    output[(*output_index)++] = end;

    free_stack(stack);

    return output;
}

double rpn_calculate(Token *rpn_root, int n, double x) {
    Node *eval_expr = new_Stack();
    for (int i = 0; i < n; i++) {
        switch (rpn_root[i].type) {
            case TOKEN_NUM: {
                double *number = malloc(sizeof(double));
                *number = rpn_root[i].value.num;
                push(eval_expr, number);
                /* printf("case TOKEN_NUMBER\n\t (node->value)->value=%lf\n", ((Token
                 * *)node->value)->value.num); */
                break;
            }
            case TOKEN_OPERATOR: {
                Maybe maybe_right = pop(eval_expr);
                Maybe maybe_left = pop(eval_expr);

                if (!maybe_left.has_value || !maybe_right.has_value) {
                    free(maybe_right.value);
                    free(maybe_left.value);
                    break;
                }

                char op = rpn_root[i].value.op;

                Maybe maybe_result = nothing();

                switch (op) {
                    case '+':
                        maybe_result = bind2(sumM, maybe_left, maybe_right);
                        break;
                    case '-':
                        maybe_result = bind2(difM, maybe_left, maybe_right);
                        break;
                    case '*':
                        maybe_result = bind2(mulM, maybe_left, maybe_right);
                        break;
                    case '/':
                        maybe_result = bind2(divM, maybe_left, maybe_right);
                        break;
                    default:
                        break;
                }

                if (maybe_result.has_value) {
                    push(eval_expr, maybe_result.value);
                }

                free(maybe_right.value);
                free(maybe_left.value);
                break;
            }

            case TOKEN_FUNCTION: {
                const char *func_name = rpn_root[i].value.func;
                Maybe maybe_operand = pop(eval_expr);

                if (!maybe_operand.has_value) {
                    free(maybe_operand.value);
                    break;
                }

                Maybe maybe_result = nothing();

                if (strcmp(func_name, "sin") == 0) {
                    maybe_result = bind(sinM, maybe_operand);
                } else if (strcmp(func_name, "cos") == 0) {
                    maybe_result = bind(cosM, maybe_operand);
                } else if (strcmp(func_name, "tg") == 0) {
                    maybe_result = bind(tgM, maybe_operand);
                } else if (strcmp(func_name, "ctg") == 0) {
                    maybe_result = bind(ctgM, maybe_operand);
                } else if (strcmp(func_name, "ln") == 0) {
                    maybe_result = bind(lnM, maybe_operand);
                } else if (strcmp(func_name, "sqrt") == 0) {
                    maybe_result = bind(sqrtM, maybe_operand);
                } else {
                    // Unknown function: handle error if needed
                }

                if (maybe_result.has_value) {
                    push(eval_expr, maybe_result.value);
                }

                free(maybe_operand.value);
                break;
            }
            case TOKEN_VARIABLE_X: {
                double *number = malloc(sizeof(double));
                *number = x;
                push(eval_expr, number);
                /* printf("case TOKEN_VARIABLE_X\n\t x=%lf\n", *x); */
                /* printf("\t root->next->value=%lf\n", *(double *)next(eval_expr, eval_expr)->value); */
                break;
            }
            default:
                break;
        }
    }

    Maybe m = pop(eval_expr);
    free_stack(eval_expr);
    if (m.has_value) {
        double d = *(double *)(m.value);
        free(m.value);
        return d;
    }
    return 0;
}
