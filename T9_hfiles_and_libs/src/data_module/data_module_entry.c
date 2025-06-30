#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"  // files from data_libs
#include "data_process.h"          // files from data_module

int main() {
    double *data;
    int n;
    if (scanf("%d", &n)) {
        data = (double *)malloc(sizeof(double) * n);
    } else {
        return 1;
    }
    // Don`t forget to allocate memory !
    input(data, n);

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");

    free(data);
    return 0;
}
