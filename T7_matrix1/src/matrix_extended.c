#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int allocate_1();
int allocate_2();
int allocate_3();
int allocate_4();

int static_input(int matrix[NMAX][NMAX], int n, int m);
void static_output(int matrix[NMAX][NMAX], int n, int m);

int dynamic_input(int** matrix, int n, int m);
void dynamic_output(int** matrix, int n, int m);

int read_two_numbers(int* rows, int* cols);

// new for matrix extended
void print_array(int* a, int N);

void dynamic_search_col_max(int** matrix, int n, int m);
void dynamic_search_rows_min(int** matrix, int n, int m);

void static_search_col_max(int matrix[NMAX][NMAX], int n, int m);
void static_search_rows_min(int matrix[NMAX][NMAX], int n, int m);

int main() {
    int choice, check_input_main = 0;
    char c;
    if (scanf("%d%c", &choice, &c) != 2 || c != '\n' || choice < 1 || choice > 4) {
        printf("n/a");
        return 1;
    }

    switch (choice) {
        case 1:  // static
            if (allocate_1() == 1) {
                check_input_main = 1;
            }
            break;
        case 2:
            if (allocate_2() == 1) {
                check_input_main = 1;
            }
            break;
        case 3:
            if (allocate_3() == 1) {
                check_input_main = 1;
            }
            break;
        case 4:
            if (allocate_4() == 1) {
                check_input_main = 1;
            }
            break;

        default:
            break;
    }

    if (check_input_main == 1) {
        printf("n/a");
    }

    return 0;
}

int allocate_1() {
    int rows, cols, check_input = 0;
    if (read_two_numbers(&rows, &cols) == 1) {
        check_input = 1;
    } else {
        int matrix[NMAX][NMAX];

        if (static_input(matrix, rows, cols) == 1) {
            check_input = 1;
        } else {
            static_output(matrix, rows, cols);
            // new for matrix extended
            static_search_col_max(matrix, rows, cols);
            static_search_rows_min(matrix, rows, cols);
        }
    }
    return check_input;
}

int allocate_2() {  // jpg3
    int rows, cols;
    if (read_two_numbers(&rows, &cols) == 1) {
        return 1;
    }

    int** pointer_array = (int**)malloc(rows * sizeof(int*));
    if (pointer_array == NULL) {
        return 1;
    }

    int* values_array = (int*)malloc(rows * cols * sizeof(int));
    if (values_array == NULL) {
        free(pointer_array);
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        pointer_array[i] = values_array + cols * i;
    }

    if (dynamic_input(pointer_array, rows, cols) == 1) {
        free(values_array);
        free(pointer_array);
        return 1;
    }

    dynamic_output(pointer_array, rows, cols);

    // new for matrix extended
    dynamic_search_col_max(pointer_array, rows, cols);
    dynamic_search_rows_min(pointer_array, rows, cols);

    free(values_array);
    free(pointer_array);
    return 0;
}

int allocate_3() {  // jpg2
    int rows, cols;
    if (read_two_numbers(&rows, &cols) == 1) {
        return 1;
    }

    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (matrix == NULL) {
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            // free mem if problems
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    if (dynamic_input(matrix, rows, cols) == 1) {
        for (int i = 0; i < rows; i++) {  // free mem if problems
            free(matrix[i]);
        }
        free(matrix);
        return 1;
    }

    dynamic_output(matrix, rows, cols);

    // new for matrix extended
    dynamic_search_col_max(matrix, rows, cols);
    dynamic_search_rows_min(matrix, rows, cols);

    // final free
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);
    return 0;
}

int allocate_4() {  // jpg1 tyazelo....
    int rows, cols;
    if (read_two_numbers(&rows, &cols) == 1) {
        return 1;
    }

    int** single_array_matrix = (int**)malloc(rows * cols * sizeof(int) + rows * sizeof(int*));
    if (single_array_matrix == NULL) {
        return 1;
    }

    int* ptr = (int*)(single_array_matrix + rows);

    for (int i = 0; i < rows; i++) {
        single_array_matrix[i] = ptr + cols * i;
    }

    if (dynamic_input(single_array_matrix, rows, cols) == 1) {
        free(single_array_matrix);
        return 1;
    }

    dynamic_output(single_array_matrix, rows, cols);

    // new for matrix extended
    dynamic_search_col_max(single_array_matrix, rows, cols);
    dynamic_search_rows_min(single_array_matrix, rows, cols);

    free(single_array_matrix);
    return 0;
}

int static_input(int matrix[NMAX][NMAX], int n, int m) {
    char c;
    int flag = 0;
    if (n > NMAX || m > NMAX) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d%c", &matrix[i][j], &c) != 2) {
                flag = 1;
                break;
            }
            if (j < m - 1 && c != ' ') {
                flag = 1;
                break;
            }
            if (j == m - 1 && c != '\n') {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }

    return flag;
}

void static_output(int matrix[NMAX][NMAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("%d", matrix[i][0]);
        for (int j = 1; j < m; j++) {
            printf(" %d", matrix[i][j]);
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

int dynamic_input(int** matrix, int n, int m) {
    char c;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d%c", &matrix[i][j], &c) != 2) {
                flag = 1;
                break;
            }
            if (j < m - 1 && c != ' ') {
                flag = 1;
                break;
            }
            if (j == m - 1 && c != '\n') {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }

    return flag;
}

void dynamic_output(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("%d", matrix[i][0]);
        for (int j = 1; j < m; j++) {
            printf(" %d", matrix[i][j]);
        }
        if (i != n - 1) {
            printf("\n");
        }
    }
}

int read_two_numbers(int* rows, int* cols) {
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

// new for matrix_extended.c
void print_array(int* a, int N) {
    if (a == NULL) {
        return;
    }
    printf("\n%d", a[0]);
    for (int i = 1; i < N; i++) {
        printf(" %d", a[i]);
    }
}

void dynamic_search_col_max(int** matrix, int n, int m) {
    int maxs[n];
    for (int i = 0; i < n; i++) {
        int max = matrix[i][0];
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > max) max = matrix[i][j];
        }
        maxs[i] = max;
    }
    print_array(maxs, n);
}

void dynamic_search_rows_min(int** matrix, int n, int m) {
    int mins[m];
    for (int j = 0; j < m; j++) {
        int min = matrix[0][j];
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < min) min = matrix[i][j];
        }
        mins[j] = min;
    }
    print_array(mins, m);
}

void static_search_col_max(int matrix[NMAX][NMAX], int n, int m) {
    int maxs[n];
    for (int i = 0; i < n; i++) {
        int max = matrix[i][0];
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] > max) max = matrix[i][j];
        }
        maxs[i] = max;
    }
    print_array(maxs, n);
}

void static_search_rows_min(int matrix[NMAX][NMAX], int n, int m) {
    int mins[m];
    for (int j = 0; j < m; j++) {
        int min = matrix[0][j];
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] < min) min = matrix[i][j];
        }
        mins[j] = min;
    }
    print_array(mins, m);
}
