#ifndef CUCE_GEZEGEN_H
#define CUCE_GEZEGEN_H
#include "gezegen.h"

typedef struct { GEZEGEN base; } CUCE_GEZEGEN;
CUCE_GEZEGEN* cuce_gezegen_olustur(const char*, int, int, int, int);
void cuce_gezegen_yok_et(CUCE_GEZEGEN* c);
#endif