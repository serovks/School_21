#include <stdio.h>
#include <stdlib.h>

// #include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"
#include "sort.h"

#ifdef USE_IO_MACROS
#include "../data_libs/data_io_macro.h"
#define input input_double
#define output output_double
#else
#include "../data_libs/data_io.h"
#endif

#ifdef DYNAMIC_LIB
#include <dlfcn.h>

typedef double (*data_process_func_t)(double *, int);
data_process_func_t normalization = NULL;

void load_library() {
    void *handle = dlopen("../build/data_process.so", RTLD_LAZY);
    if (!handle) {
        printf("Error loading library: %s\n", dlerror());
        exit(1);
    }
    normalization = (data_process_func_t)dlsym(handle, "normalization");
    if (!normalization) {
        printf("Error loading symbol 'normalization': %s\n", dlerror());
        exit(1);
    }
}
#else
#include "../data_module/data_process.h"
#endif

int main() {
    double *data;
    int n;

    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 1;
    }

    data = (double *)malloc(n * sizeof(double));

    printf("LOAD DATA...\n");
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
#ifdef DYNAMIC_LIB
    load_library();
#endif
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    bubble_sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    free(data);
    return 0;
}
