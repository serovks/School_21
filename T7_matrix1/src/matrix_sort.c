#include <stdio.h>
#include <stdlib.h>

int allocate_2();
int allocate_3();
int allocate_4();

int dynamic_input(int** matrix, int n, int m);
void dynamic_output(int** matrix, int n, int m);

int read_two_numbers(int* rows, int* cols);

// new in matrix_sort
void sort(int** matrix, int n);
int row_sum(int* row, int cols);

int main() {
    int choice, check_input_main = 0;
    char c;
    if (scanf("%d%c", &choice, &c) != 2 || c != '\n' || choice < 1 || choice > 3) {
        printf("n/a");
        return 1;
    }

    switch (choice) {
        case 1:  // static
            if (allocate_2() == 1) {
                check_input_main = 1;
            }
            break;
        case 2:
            if (allocate_3() == 1) {
                check_input_main = 1;
            }
            break;
        case 3:
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
    sort(pointer_array, rows);
    dynamic_output(pointer_array, rows, cols);
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
            // if problems freee mem
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return 1;
        }
    }

    if (dynamic_input(matrix, rows, cols) == 1) {
        for (int i = 0; i < rows; i++) {  // if problems freee mem
            free(matrix[i]);
        }
        free(matrix);
        return 1;
    }
    sort(matrix, rows);
    dynamic_output(matrix, rows, cols);

    // final free
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);
    return 0;
}

int allocate_4() {  // jpg1
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
    sort(single_array_matrix, rows);
    dynamic_output(single_array_matrix, rows, cols);
    free(single_array_matrix);
    return 0;
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

int row_sum(int* row, int cols) {
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += row[j];
    }
    return sum;
}

void sort(int** matrix, int n) {
    int sums[n];
    int row_indeces[n];

    for (int i = 0; i < n; i++) {
        sums[i] = row_sum(matrix[i], n);
        row_indeces[i] = i;  // iniialization;
    }

    // bubble sort for sums and for indeces
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sums[j] > sums[j + 1]) {
                int temp_sum = sums[j];
                sums[j] = sums[j + 1];
                sums[j + 1] = temp_sum;

                int temp_idx = row_indeces[j];
                row_indeces[j] = row_indeces[j + 1];
                row_indeces[j + 1] = temp_idx;
            }
        }
    }

    // sort for matrix
    int* matrix_copy[n];
    for (int i = 0; i < n; i++) {
        matrix_copy[i] = matrix[row_indeces[i]];
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = matrix_copy[i];
    }
}
