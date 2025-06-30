#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"  // files from data_libs
#include "decision.h"              // files from data_module

int main() {
    double *data;
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 1;
    } else {
        data = (double *)malloc(sizeof(double) * n);
    }
    // Don`t forget to allocate memory !
    input(data, n);

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    free(data);
    return 0;
}
