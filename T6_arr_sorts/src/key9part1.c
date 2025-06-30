#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int length, length_new, sum;
    int buffer[NMAX];
    int numbers[NMAX];
    if (input(buffer, &length) == 1) {
        printf("n/a");
        return 1;
    }
    sum = sum_numbers(buffer, length);
    if (sum == -1) {
        printf("n/a");
        return 1;
    } else
        printf("%d\n", sum);
    length_new = find_numbers(buffer, length, sum, numbers);
    output(numbers, length_new);
    return 0;
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    int flag = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
            flag++;
        }
    }
    if (flag == 0) {
        sum = -1;
    }

    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int length_new = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0) {
            if (number % buffer[i] == 0) {
                numbers[length_new] = buffer[i];
                length_new++;
            }
        }
    }
    return length_new;
}

int input(int *buffer, int *length) {
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
    return 0;
}

void output(int *a, int length) {
    printf("%d", a[0]);
    for (int i = 1; i < length; i++) {
        printf(" %d", a[i]);
    }
}
