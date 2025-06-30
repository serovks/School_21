#ifndef MONADS_H
#define MONADS_H

#include "parser.h"

typedef struct {
    int has_value;
    void* value;
} Maybe;

Maybe just(void* value);
Maybe nothing();

int is_nothing(Maybe m);
int is_just(Maybe m);
Maybe bind(Maybe (*f)(void* a), Maybe m2);
Maybe bind2(Maybe (*f)(void* a, void* b), Maybe m1, Maybe m2);

#endif
