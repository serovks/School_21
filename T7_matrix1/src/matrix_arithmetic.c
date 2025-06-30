#include <stdio.h>
#include <stdlib.h>

int input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);
void free_matrix(int **matrix, int n);
int read_two_numbers(int *rows, int *cols);

int sum(int **matrix1, int n1, int m1, int **matrix2, int n2, int m2, int ***result, int *n_res, int *m_res);

int mul(int **matrix1, int n1, int m1, int **matrix2, int n2, int m2, int ***result, int *n_res, int *m_res);

int transpose(int **matrix, int n, int m, int ***result, int *n_res, int *m_res);

int main() {
    int operation;
    char c;

    if (scanf("%d%c", &operation, &c) != 2 || c != '\n' || operation < 1 || operation > 3) {
        printf("n/a");
        return 1;
    }

    if (operation == 1 || operation == 2) {
        int n1, m1;
        // first matrix
        if (read_two_numbers(&n1, &m1) == 1) {
            printf("n/a");
            return 1;
        }

        int **matrix1 = (int **)malloc(n1 * sizeof(int *));
        if (!matrix1) {
            printf("n/a");
            return 1;
        }
        for (int i = 0; i < n1; i++) {
            matrix1[i] = (int *)malloc(m1 * sizeof(int));
            if (!matrix1[i]) {
                for (int j = 0; j < i; j++) free(matrix1[j]);
                free(matrix1);
                printf("n/a");
                return 1;
            }
        }
        // first matrix input
        if (input(matrix1, n1, m1)) {
            free_matrix(matrix1, n1);
            printf("n/a");
            return 1;
        }

        // second matrix
        int n2, m2;
        if (read_two_numbers(&n2, &m2) == 1) {
            printf("n/a");
            return 1;
        }

        // check size of matrix
        if ((operation == 1 && (n1 != n2 || m1 != m2)) || (operation == 2 && m1 != n2)) {
            free_matrix(matrix1, n1);
            printf("n/a");
            return 1;
        }

        // second matrix mem
        int **matrix2 = (int **)malloc(n2 * sizeof(int *));
        if (!matrix2) {
            free_matrix(matrix1, n1);
            printf("n/a");
            return 1;
        }
        for (int i = 0; i < n2; i++) {
            matrix2[i] = (int *)malloc(m2 * sizeof(int));
            if (!matrix2[i]) {
                for (int j = 0; j < i; j++) free(matrix2[j]);
                free(matrix2);
                free_matrix(matrix1, n1);
                printf("n/a");
                return 1;
            }
        }

        // second matrix input
        if (input(matrix2, n2, m2)) {
            free_matrix(matrix1, n1);
            free_matrix(matrix2, n2);
            printf("n/a");
            return 1;
        }

        // operations
        int **result = NULL;
        int n_res = 0, m_res = 0;
        int status = 0;

        if (operation == 1) {
            status = sum(matrix1, n1, m1, matrix2, n2, m2, &result, &n_res, &m_res);
        } else {
            status = mul(matrix1, n1, m1, matrix2, n2, m2, &result, &n_res, &m_res);
        }

        if (status) {
            printf("n/a");
        } else {
            output(result, n_res, m_res);
        }

        // total free
        free_matrix(matrix1, n1);
        free_matrix(matrix2, n2);
        free_matrix(result, n_res);
    } else {  // transpose

        int n, m;
        if (read_two_numbers(&n, &m) == 1) {
            printf("n/a");
            return 1;
        }

        // mem
        int **matrix = (int **)malloc(n * sizeof(int *));
        if (!matrix) {
            printf("n/a");
            return 1;
        }
        for (int i = 0; i < n; i++) {
            matrix[i] = (int *)malloc(m * sizeof(int));
            if (!matrix[i]) {
                for (int j = 0; j < i; j++) free(matrix[j]);
                free(matrix);
                printf("n/a");
                return 1;
            }
        }

        // input for transpose
        if (input(matrix, n, m)) {
            free_matrix(matrix, n);
            printf("n/a");
            return 1;
        }

        // transpose
        int **result = NULL;
        int n_res = 0, m_res = 0;

        if (transpose(matrix, n, m, &result, &n_res, &m_res)) {
            printf("n/a");
        } else {
            output(result, n_res, m_res);
        }

        // mem free
        free_matrix(matrix, n);
        free_matrix(result, n_res);
    }

    return 0;
}

int input(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }
    return 0;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j < m - 1) printf(" ");
        }
        if (i < n - 1) printf("\n");
    }
}

void free_matrix(int **matrix, int n) {
    if (matrix) {
        for (int i = 0; i < n; i++) {
            if (matrix[i]) free(matrix[i]);
        }
        free(matrix);
    }
}

int sum(int **matrix1, int n1, int m1, int **matrix2, int n2, int m2, int ***result, int *n_res, int *m_res) {
    if (n1 != n2 || m1 != m2) return 1;

    *n_res = n1;
    *m_res = m1;
    *result = (int **)malloc(n1 * sizeof(int *));
    if (!*result) return 1;

    for (int i = 0; i < n1; i++) {
        (*result)[i] = (int *)malloc(m1 * sizeof(int));
        if (!(*result)[i]) {
            for (int j = 0; j < i; j++) free((*result)[j]);
            free(*result);
            return 1;
        }

        for (int j = 0; j < m1; j++) {
            (*result)[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return 0;
}

int mul(int **matrix1, int n1, int m1, int **matrix2, int n2, int m2, int ***result, int *n_res, int *m_res) {
    if (m1 != n2) return 1;

    *n_res = n1;
    *m_res = m2;
    *result = (int **)malloc(n1 * sizeof(int *));
    if (!*result) return 1;

    for (int i = 0; i < n1; i++) {
        (*result)[i] = (int *)malloc(m2 * sizeof(int));
        if (!(*result)[i]) {
            for (int j = 0; j < i; j++) free((*result)[j]);
            free(*result);
            return 1;
        }

        for (int j = 0; j < m2; j++) {
            (*result)[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                (*result)[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return 0;
}

int transpose(int **matrix, int n, int m, int ***result, int *n_res, int *m_res) {
    *n_res = m;
    *m_res = n;
    *result = (int **)malloc(m * sizeof(int *));
    if (!*result) return 1;

    for (int i = 0; i < m; i++) {
        (*result)[i] = (int *)malloc(n * sizeof(int));
        if (!(*result)[i]) {
            for (int j = 0; j < i; j++) free((*result)[j]);
            free(*result);
            return 1;
        }

        for (int j = 0; j < n; j++) {
            (*result)[i][j] = matrix[j][i];
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