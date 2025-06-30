#include <stdio.h>
#define N 10

int input(int *a);
void output(int *a);
void bubble_sort(int *a);

int main() {
    int arr[N];
    if (input(arr) == 1) {
        printf("n/a");
        return 1;
    }
    bubble_sort(arr);
    output(arr);
    return 0;
}

void bubble_sort(int *a) {
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

int input(int *a) {
    char c;
    for (int i = 0; i < N; i++) {
        if (scanf("%d%c", &a[i], &c) != 2 || (i < N - 1 && c != ' ') || (i == N - 1 && c != '\n')) {
            return 1;
        }
    }

    return 0;
}

void output(int *a) {
    printf("%d", a[0]);
    for (int i = 1; i < N; i++) {
        printf(" %d", a[i]);
    }
}
