#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n);
int input(double ***matrix, int *n, int *m);
void output_matrix(double **matrix, int n);
void free_matrix(double **matrix, int n);
int read_two_numbers(int *rows, int *cols);
int inverse_matrix(double **matrix, int n, double ***result);

int main() {
    double **matrix = NULL;
    double **result = NULL;
    int n, m;

    if (input(&matrix, &n, &m) == 1) {
        printf("n/a");
        return 1;
    }

    if (n != m) {
        printf("n/a");
        return 1;
    }
    if (inverse_matrix(matrix, n, &result) == 1) {
        printf("n/a");
    } else {
        output_matrix(result, n);
    }
    free_matrix(matrix, n);
    free_matrix(result, n);
    return 0;
}

int inverse_matrix(double **matrix, int n, double ***result) {
    double determinant = det(matrix, n);

    if (fabs(determinant) < 1e-10) {
        return 1;  // errror - inverse matrix does not exist
    }

    *result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        (*result)[i] = (double *)malloc(n * sizeof(double));
    }

    double **temp = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; i++) {
        temp[i] = (double *)malloc((n - 1) * sizeof(double));
    }

    // like in det
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int row = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                int col = 0;
                for (int l = 0; l < n; l++) {
                    if (l == j) continue;
                    temp[row][col] = matrix[k][l];
                    col++;
                }
                row++;
            }
            // cofactor = algebraicheskoe dopolnenie po russki)
            double minor_det = det(temp, n - 1);
            double cofactor = ((i + j) % 2 == 0 ? 1 : -1) * minor_det;

            // transpose /det
            (*result)[j][i] = cofactor / determinant;
        }
    }

    free_matrix(temp, n - 1);
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

void output_matrix(double **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.6lf", matrix[i][j]);
            if (j < n - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}