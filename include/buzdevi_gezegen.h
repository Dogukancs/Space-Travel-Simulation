#ifndef BUZDEVI_GEZEGEN_H
#define BUZDEVI_GEZEGEN_H
#include "gezegen.h"

typedef struct { GEZEGEN base; } BUZDEVI_GEZEGEN;
BUZDEVI_GEZEGEN* buzdevi_gezegen_olustur(const char*, int, int, int, int);
void buzdevi_gezegen_yok_et(BUZDEVI_GEZEGEN* b);
#endif