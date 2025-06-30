#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
int input(double ***matrix, int *n, int *m);
void output(double det);
void free_matrix(double **matrix, int n);
int read_two_numbers(int *rows, int *cols);

int main() {
    double **matrix = NULL;
    int n, m;

    if (input(&matrix, &n, &m) == 1) {
        printf("n/a");
        return 1;
    }

    if (n != m) {
        printf("n/a");
        return 1;
    }

    output(det(matrix, n));
    free_matrix(matrix, n);
    return 0;
}

double det(double **matrix, int n) {
    double det_res = 0;
    // stop variants
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    // for minors
    double **minor = (double **)malloc(sizeof(double *) * (n - 1));
    for (int i = 0; i < n - 1; i++) {
        minor[i] = (double *)malloc(sizeof(double) * (n - 1));
    }

    // by first row
    for (int col = 0; col < n; col++) {
        // making minor
        for (int i = 1; i < n; i++) {
            int minor_col = 0;
            for (int j = 0; j < n; j++) {
                if (j == col) continue;
                minor[i - 1][minor_col] = matrix[i][j];
                minor_col++;
            }
        }
        double minor_det = det(minor, n - 1);
        int sign = (col % 2 == 0) ? 1 : -1;

        det_res += sign * matrix[0][col] * minor_det;
    }

    // free mem minor
    free_matrix(minor, n - 1);

    return det_res;
}

void output(double det) { printf("%.6lf", det); }

int input(double ***matrix, int *n, int *m) {
    if (read_two_numbers(n, m) == 1) {
        return 1;
    }

    *matrix = (double **)malloc(*n * sizeof(double *));
    if (!*matrix) {
        return 1;
    }

    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (double *)malloc(*m * sizeof(double));
        if (!(*matrix)[i]) {
            for (int j = 0; j < i; j++) free((*matrix)[j]);
            free(*matrix);
            return 1;
        }
    }

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            if (scanf("%lf", &(*matrix)[i][j]) != 1) {
                return 1;
            }
        }
    }
    return 0;
}

int read_two_numbers(int *rows, int *cols) {
    char c_space, c_enter;
    int flag = 0;
    if (scanf("%d%c", rows, &c_space) != 2 || *rows < 1 || c_space != ' ') {
        flag = 1;
    } else {
        if (scanf("%d%c", cols, &c_enter) != 2 || *cols < 1 || c_enter != '\n') {
            flag = 1;
        }
    }
    return flag;
}

void free_matrix(double **matrix, int n) {
    if (matrix) {
        for (int i = 0; i < n; i++) {
            if (matrix[i]) free(matrix[i]);
        }
        free(matrix);
    }
}