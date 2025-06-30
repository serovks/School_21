#include <stdio.h>
#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int one_input(int *a, int *len_a);
void output(int *a, int len_a);

int main() {
    int a[LEN] = {0}, b[LEN] = {0}, sum_res[LEN] = {0}, sub_res[LEN] = {0};
    int len_a = 0, len_b = 0, len_sum_res = 0, len_sub_res = 0;

    if (one_input(a, &len_a) || one_input(b, &len_b)) {
        printf("n/a");
        return 1;
    }

    sum(a, len_a, b, len_b, sum_res, &len_sum_res);
    sub(a, len_a, b, len_b, sub_res, &len_sub_res);

    output(sum_res, len_sum_res);
    printf("\n");

    if (len_sub_res == -1) {
        printf("n/a");
    } else {
        output(sub_res, len_sub_res);
    }

    return 0;
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int carry = 0;  // перенос десятка
    int max_len = (len1 > len2) ? len1 : len2;
    *result_length = 0;

    for (int i = 0; i < max_len || carry; i++) {
        int digit1 = (i < len1) ? buff1[len1 - 1 - i] : 0;
        int digit2 = (i < len2) ? buff2[len2 - 1 - i] : 0;

        int sum = digit1 + digit2 + carry;
        result[i] = sum % 10;
        carry = sum / 10;
        (*result_length)++;
    }

    // Удаление ведущих нулей
    while (*result_length > 1 && result[*result_length - 1] == 0) {
        (*result_length)--;
    }

    // Переворот результата
    for (int i = 0; i < *result_length / 2; i++) {
        int temp = result[i];
        result[i] = result[*result_length - 1 - i];
        result[*result_length - 1 - i] = temp;
    }
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    // Проверка, что buff1 >= buff2
    if (len1 < len2) {
        *result_length = -1;
        return;
    }
    if (len1 == len2) {
        for (int i = 0; i < len1; i++) {
            if (buff1[i] < buff2[i]) {
                *result_length = -1;
                return;
            } else if (buff1[i] > buff2[i]) {
                break;
            }
        }
    }

    int borrow = 0;  // заем десятка
    *result_length = 0;

    for (int i = 0; i < len1; i++) {
        int digit1 = buff1[len1 - 1 - i] - borrow;
        int digit2 = (i < len2) ? buff2[len2 - 1 - i] : 0;

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result[i] = digit1 - digit2;
        (*result_length)++;
    }

    // Удаление ведущих нулей
    while (*result_length > 1 && result[*result_length - 1] == 0) {
        (*result_length)--;
    }

    // Переворот результата
    for (int i = 0; i < *result_length / 2; i++) {
        int temp = result[i];
        result[i] = result[*result_length - 1 - i];
        result[*result_length - 1 - i] = temp;
    }
}

int one_input(int *a, int *len_a) {
    char c;
    *len_a = 0;

    while (*len_a < LEN) {
        if (scanf("%d%c", &a[*len_a], &c) != 2) {
            return 1;
        }

        if (a[*len_a] < 0 || a[*len_a] > 9) {
            return 1;
        }

        (*len_a)++;

        if (c == '\n') {
            break;
        }

        if (c != ' ') {
            return 1;
        }
    }

    return 0;
}

void output(int *a, int len_a) {
    if (len_a == 0) {
        printf("0");
        return;
    }

    for (int i = 0; i < len_a; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", a[i]);
    }
}