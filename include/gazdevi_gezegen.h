#ifndef GAZDEVI_GEZEGEN_H
#define GAZDEVI_GEZEGEN_H
#include "gezegen.h"

typedef struct { GEZEGEN base; } GAZDEVI_GEZEGEN;
GAZDEVI_GEZEGEN* gazdevi_gezegen_olustur(const char*, int, int, int, int);
void gazdevi_gezegen_yok_et(GAZDEVI_GEZEGEN* g);
#endif