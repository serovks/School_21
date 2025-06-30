#include "stack.h"

#include <stdio.h>

void testing() {
    struct stack* s = NULL;
    for (int i = 0; i < 5; i++) {
        push(&s, i);
    }

    for (int i = 0; i < 5; i++) {
        if (pop(&s) == 4 - i) {
            printf("SUCCESS\n");
        } else {
            printf("FAIL\n");
        }
    }

    destroy(s);

    if (s == NULL) {
        printf("SUCCES\n");
    } else {
        printf("FAIL\n");
    }
}

int main() {
    testing();
    return 0;
}