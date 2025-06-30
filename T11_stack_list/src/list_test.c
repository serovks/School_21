#include "list.h"

#include <stdio.h>

void test_add_door() {
    struct door test_door = {1, 0};
    struct node* list = init(&test_door);
    struct door new_door = {2, 0};
    struct node* added = add_door(list, &new_door);

    // test 1
    if (find_door(2, list) != NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    // test 2
    if (added != NULL && list->next == added) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    remove_door(added, list);

    // test 3
    if (find_door(2, list) != NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    // test 4
    if (added != NULL && list->next == added) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }

    destroy(list);
}

int main() {
    test_add_door();
    return 0;
}