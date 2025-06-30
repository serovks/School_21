#include "graphics.h"

#include <stdio.h>

void reset_matrix(int matrix[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++)
        for (int col = 0; col < WIDTH; col++) matrix[row][col] = 0;
}

void print_matrix(int matrix[HEIGHT][WIDTH]) {
    for (int i = HEIGHT; i > 0; i--) {
        for (int j = 0; j < WIDTH; j++) printf(matrix[i][j] ? "*" : ".");
        printf("\n");
    }
}
