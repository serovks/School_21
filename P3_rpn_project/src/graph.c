#include "graph.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"
#include "io.h"
#include "mat.h"
#include "parser.h"
#include "stack.h"

int main() {
    int len = 0;
    int matrix[HEIGHT][WIDTH];

    reset_matrix(matrix);
    const int bufsize = 21;
    char* input_expr = malloc(21);
    if (!input_expr) {
        printf("n/a");
        return 0;
    }
    get_expr(input_expr, bufsize);

    if (valid_input(input_expr) != 0) {
        printf("n/a");
        free(input_expr);
        return 0;
    }
    Token* rpn_tokens = rpn_convert(input_expr, &len);

    double ys[WIDTH];

    for (int i = 0; i < WIDTH; i++) ys[i] = rpn_calculate(rpn_tokens, len, i * STEP_X);
    normalize(ys, WIDTH);
    for (int j = 0; j < WIDTH; j++) matrix[(int)round(ys[j] * 24)][j] = 1;
    print_matrix(matrix);
    free(rpn_tokens);
    free(input_expr);
}
