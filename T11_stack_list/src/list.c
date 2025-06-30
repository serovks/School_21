#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->door = door;
    new_node->next = NULL;
    return new_node;
}

struct node* add_door(struct node* elem, struct door* door) {
    if (!elem) return NULL;
    struct node* new_node = malloc(sizeof(struct node));
    new_node->door = door;
    new_node->next = elem->next;
    elem->next = new_node;
    return new_node;
    ;
}

struct node* find_door(int door_id, struct node* root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->door->id == door_id) {
        return root;
    }

    return find_door(door_id, root->next);
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (elem == NULL || root == NULL) {
        return root;
    }

    if (elem == root) {
        struct node* new_root = root->next;
        free(root);
        return new_root;
    }

    struct node* current = root;
    while (current->next != NULL) {
        if (current->next == elem) {
            struct node* node_to_remove = current->next;
            current->next = node_to_remove->next;
            free(node_to_remove);
            return root;
        }
        current = current->next;
    }

    return root;
}

void destroy(struct node* root) {
    while (root != NULL) {
        struct node* node_to_remove = root;
        root = root->next;
        free(node_to_remove);
    }
}