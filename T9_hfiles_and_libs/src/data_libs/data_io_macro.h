// data_io_macro.h
#ifndef DATA_IO_MACRO_H
#define DATA_IO_MACRO_H

#include <stdio.h>
#include <stdlib.h>

#define DECLARE_IO_FUNCTIONS(TYPE, SCANF_FMT, PRINTF_FMT) \
    int input_##TYPE(TYPE *data, int n) {                 \
        for (int i = 0; i < n; i++) {                     \
            if (scanf(SCANF_FMT, &data[i]) != 1) {        \
                return 0;                                 \
            }                                             \
        }                                                 \
        return 1;                                         \
    }                                                     \
    void output_##TYPE(TYPE *data, int n) {               \
        for (int i = 0; i < n; i++) {                     \
            printf(PRINTF_FMT " ", data[i]);              \
        }                                                 \
        printf("\n");                                     \
    }

// Then declare for each type:
DECLARE_IO_FUNCTIONS(double, "%lf", "%.2f")
// DECLARE_IO_FUNCTIONS(int, "%d", "%d")
// смысл в том, что если бы мне нужно было добавить реализацию для int мне было бы
// достаточно просто раскоментить эту строку без копипаста одинаковых по содержанию
// функций, но так как дальнейшая программа работает только с double *data
// это работать не будет поэтому сейчас на деле data_io_macro.h
// и data_io.h работают абсолютно одинаково просто разная реализация

#endif