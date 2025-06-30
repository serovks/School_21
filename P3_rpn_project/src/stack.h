#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "monads.h"
#include "node.h"

Node* new_Stack();
Node* new_Node(void* value);
Node* push(Node* root, void* value);
Maybe pop(Node* root);
Maybe peek(Node* root);
int is_empty(Node* root);
void free_stack(Node* root);
Node* next(const Node* current_node, const Node* root);

#endif
