#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
void output(int *a, int n);
void shift_left(int *a, int n, int c);
void shift_right(int *a, int n, int c);

int main() {
    int a[NMAX];
    int n, c;
    if (input(a, &n, &c) == 1) {
        printf("n/a");
        return 1;
    }

    if (c >= 0) shift_left(a, n, c);
    if (c < 0) shift_right(a, n, c);
    output(a, n);
    return 0;
}

void shift_right(int *a, int n, int c) {
    c = -c;
    if (c >= n) {
        c = (c % n);
    }

    if (c == 0) {
        return;
    }

    int temp[c];
    for (int i = 0; i < c; i++) {
        temp[i] = a[n - c + i];
    }

    for (int i = n - 1; i >= c; i--) {
        a[i] = a[i - c];
    }

    for (int i = 0; i < c; i++) {
        a[i] = temp[i];
    }
}

void shift_left(int *a, int n, int c) {
    if (c >= n) {
        c = c % n;
    }
    if (c == 0) {  // Если сдвиг не нужен
        return;
    }
    int temp[c];
    for (int i = 0; i < c; i++) {
        temp[i] = a[i];
    }
    for (int i = c; i < n; i++) {
        a[i - c] = a[i];
    }
    for (int i = 0; i < c; i++) {
        a[n - 1 - i] = temp[c - 1 - i];
    }
}

int input(int *buffer, int *length, int *num) {
    char c;
    if (scanf("%d%c", length, &c) != 2 || *length < 1 || *length > NMAX || c != '\n') {
        return 1;
    }
    for (int i = 0; i < *length; i++) {
        if (scanf("%d%c", &buffer[i], &c) != 2 || (i < *length - 1 && c != ' ') ||
            (i == *length - 1 && c != '\n')) {
            return 1;
        }
    }
    if (scanf("%d%c", num, &c) != 2 || c != '\n') {
        return 1;
    }
    return 0;
}

void output(int *a, int n) {
    printf("%d", a[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", a[i]);
    }
}
