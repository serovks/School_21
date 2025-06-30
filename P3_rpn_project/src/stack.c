#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "monads.h"

/* Node node = new Stack(); */
Node* new_Stack() {
    Node* dummy = malloc(sizeof(Node));
    if (dummy) {
        dummy->next = dummy;
    }
    return dummy;
}

/* Node node = new Node(21); */
Node* new_Node(void* value) {
    Node* node = malloc(sizeof(Node));
    if (node) {
        node->value = value;
        node->next = NULL;
    }
    return node;
}

Node* push(Node* root, void* value) {
    Node* node = new_Node(value);
    if (node) {
        node->next = root->next;
        root->next = node;
    }
    return node;
}

// Извлекаем узел из стека
Maybe pop(Node* root) {
    Node* node = root->next;
    if (node == root) {
        /* printf("pop\n\t returning nothing...\n"); */
        return nothing();
    } else {
        root->next = node->next;
        void* value = node->value;
        free(node);
        /* printf("pop\n\t returning just(%p)\n", value); */
        return just(value);
    }
}

// Просмотр верхнего элемента без извлечения
Maybe peek(Node* root) {
    Node* node = root->next;
    return node == root ? nothing() : just(node->value);
}

Node* next(const Node* current_node, const Node* root) {
    Node* next_node = current_node->next;
    return next_node == root ? NULL : next_node;
}

// Проверка на пустоту
int is_empty(Node* root) { return root->next == root; }

void free_stack(Node* root) {
    for (Node* current = root->next; current != root;) {
        Node* node = current->next;
        free(current);
        current = node;
    }
    free(root);
}
