#ifndef STACK_H
#define STACK_H

struct stack {
    int data;
    struct stack* next;
};

struct stack* init(int data);
void push(struct stack** root, int data);
int pop(struct stack** root);
void destroy(struct stack* root);

#endif