#include "monads.h"

#include "parser.h"

Maybe just(void* value) {
    Maybe result;
    result.has_value = 1;
    result.value = value;
    return result;
}

Maybe nothing() {
    Maybe result;
    result.has_value = 0;
    result.value = 0;
    return result;
}

int is_nothing(Maybe m) { return m.has_value ? 0 : 1; }

/* int is_just(Maybe m) { return m.has_value ? 1 : 0; } */

// применяет функцию f к монаде m
Maybe bind(Maybe (*f)(void* a), Maybe m) { return m.has_value ? f(m.value) : nothing(); }

// применяет функцию f к монадам m1 и m2
Maybe bind2(Maybe (*f)(void* a, void* b), Maybe m1, Maybe m2) {
    return m1.has_value && m2.has_value ? f(m1.value, m2.value) : nothing();
}
