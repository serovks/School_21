#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int read_two_numbers(int *rows, int *cols);
void free_matrix(int **matrix, int n);
void bubble_sort_simple(int *arr, int size);
void matrix_to_array(int **matrix, int n, int m, int *arr);

int main() {
    int **matrix = NULL, **result = NULL;
    int n, m;

    if (input(&matrix, &n, &m) == 1) {
        printf("n/a");
        return 1;
    }

    // mem for result
    result = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        result[i] = (int *)malloc(m * sizeof(int));
    }

    sort_vertical(matrix, n, m, result);
    output(result, n, m);
    printf("\n");

    sort_horizontal(matrix, n, m, result);
    output(result, n, m);

    free_matrix(matrix, n);
    free_matrix(result, n);
    return 0;
}

void matrix_to_array(int **matrix, int n, int m, int *arr) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[index++] = matrix[i][j];
        }
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int size = n * m;
    int *arr = (int *)malloc(size * sizeof(int));
    matrix_to_array(matrix, n, m, arr);
    bubble_sort_simple(arr, size);

    int index = 0;
    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                result_matrix[i][j] = arr[index++];
            }
        } else {
            for (int i = n - 1; i >= 0; i--) {
                result_matrix[i][j] = arr[index++];
            }
        }
    }
    free(arr);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int size = n * m;
    int *arr = (int *)malloc(size * sizeof(int));
    matrix_to_array(matrix, n, m, arr);
    bubble_sort_simple(arr, size);

    int index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                result_matrix[i][j] = arr[index++];
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                result_matrix[i][j] = arr[index++];
            }
        }
    }
    free(arr);
}

int input(int ***matrix, int *n, int *m) {
    if (read_two_numbers(n, m) == 1) {
        return 1;
    }

    *matrix = (int **)malloc(*n * sizeof(int *));
    if (!*matrix) {
        return 1;
    }

    for (int i = 0; i < *n; i++) {
        (*matrix)[i] = (int *)malloc(*m * sizeof(int));
        if (!(*matrix)[i]) {
            for (int j = 0; j < i; j++) free((*matrix)[j]);
            free(*matrix);
            return 1;
        }
    }

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            if (scanf("%d", &(*matrix)[i][j]) != 1) {
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

void free_matrix(int **matrix, int n) {
    if (matrix) {
        for (int i = 0; i < n; i++) {
            if (matrix[i]) free(matrix[i]);
        }
        free(matrix);
    }
}

void bubble_sort_simple(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
