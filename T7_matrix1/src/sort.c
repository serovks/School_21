#include <stdio.h>
#include <stdlib.h>

int input(int *a, int N);
void output(int *a, int N);
void bubble_sort(int *a, int N);

int main() {
    int n;
    char c;
    if (scanf("%d%c", &n, &c) != 2 || c != '\n') {
        printf("n/a");
        return 1;
    }
    if (n < 1) {
        printf("n/a");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("n/a");
        return 1;
    }
    if (input(arr, n) == 1) {
        printf("n/a");
        free(arr);
        return 1;
    }
    bubble_sort(arr, n);
    output(arr, n);
    free(arr);
    return 0;
}

void bubble_sort(int *a, int N) {
    int temp = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int input(int *a, int N) {
    char c;
    for (int i = 0; i < N; i++) {
        if (scanf("%d%c", &a[i], &c) != 2 || (i < N - 1 && c != ' ') || (i == N - 1 && c != '\n')) {
            return 1;
        }
    }

    return 0;
}

void output(int *a, int N) {
    printf("%d", a[0]);
    for (int i = 1; i < N; i++) {
        printf(" %d", a[i]);
    }
}
