#ifndef MAT_H
#define MAT_H
#include <math.h>
#include <stdlib.h>

#include "monads.h"

double max(double *a, int n);
double min(double *a, int n);
Maybe sumM(void *a, void *b);
Maybe sinM(void *a);
void normalize(double *a, int n);
Maybe cosM(void *a);
Maybe tgM(void *a);
Maybe ctgM(void *a);
Maybe lnM(void *a);
Maybe sqrtM(void *a);

Maybe mulM(void *a, void *b);
Maybe difM(void *a, void *b);
Maybe divM(void *a, void *b);
#endif
