#include "mat.h"

double max(double *a, int n) {
    double m = a[0];
    for (int i = 1; i < n; i++) m = a[i] > m ? a[i] : m;
    return m;
}

double min(double *a, int n) {
    double m = a[0];
    for (int i = 1; i < n; i++) m = a[i] < m ? a[i] : m;
    return m;
}

Maybe mulM(void *a, void *b) {
    double da = *(double *)a;
    double db = *(double *)b;
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    *result = da * db;
    return just(result);
}

Maybe difM(void *a, void *b) {
    double da = *(double *)a;
    double db = *(double *)b;
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    *result = da - db;
    return just(result);
}

Maybe divM(void *a, void *b) {
    double da = *(double *)a;
    double db = *(double *)b;
    if (db == 0.0) return nothing();  // avoid division by zero
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    *result = da / db;
    return just(result);
}

Maybe sumM(void *a, void *b) {
    double da = *(double *)a;
    double db = *(double *)b;
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    *result = da + db;
    /* printf("SUM\n\tresult=%lf\n", *result); */
    return just(result);
}

Maybe sinM(void *a) {
    double da = *(double *)a;
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    *result = sin(da);
    /* printf("SIN\n\tresult=%lf\n", *result); */
    return just(result);
}

Maybe cosM(void *a) {
    double da = *(double *)a;
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    *result = cos(da);
    return just(result);
}

Maybe tgM(void *a) {
    double da = *(double *)a;
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    *result = tan(da);  // tan is the standard C function for tangent
    return just(result);
}

Maybe ctgM(void *a) {
    double da = *(double *)a;
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    double tan_val = tan(da);
    if (tan_val == 0.0) {  // Avoid division by zero
        free(result);
        return nothing();
    }
    *result = 1.0 / tan_val;
    return just(result);
}

Maybe lnM(void *a) {
    double da = *(double *)a;
    if (da <= 0.0) return nothing();  // ln undefined for non-positive values
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    *result = log(da);  // natural logarithm
    return just(result);
}

Maybe sqrtM(void *a) {
    double da = *(double *)a;
    if (da < 0.0) return nothing();  // sqrt undefined for negative values
    double *result = malloc(sizeof(double));
    if (!result) return nothing();
    *result = sqrt(da);
    return just(result);
}

void normalize(double *a, int n) {
    double mx = max(a, n);
    double mn = min(a, n);
    for (int j = 0; j < n; j++) a[j] = (a[j] - mn) / (mx - mn + 1e-6);
    /* matrix[(int)round(ys[j] * 24)][j] = 1; */
}
