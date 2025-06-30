#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack* init(int data) {
    struct stack* new_stack = malloc(sizeof(struct stack));
    if (new_stack == NULL) {
        return NULL;
    }
    new_stack->data = data;
    new_stack->next = NULL;
    return new_stack;
}

void push(struct stack** root, int data) {
    struct stack* new_elem = init(data);
    if (new_elem == NULL) {
        return;
    }
    new_elem->next = *root;
    *root = new_elem;
}

int pop(struct stack** root) {
    if (*root == NULL) {
        return -1;
    }
    struct stack* temp = *root;
    int popped_data = temp->data;
    *root = (*root)->next;
    free(temp);
    return popped_data;
}

void destroy(struct stack* root) {
    while (root != NULL) {
        struct stack* temp = root;
        root = root->next;
        free(temp);
    }
}