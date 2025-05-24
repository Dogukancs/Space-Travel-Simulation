#ifndef KAYAC_GEZEGEN_H
#define KAYAC_GEZEGEN_H
#include "gezegen.h"

typedef struct { GEZEGEN base; } KAYAC_GEZEGEN;
KAYAC_GEZEGEN* kayac_gezegen_olustur(const char*, int, int, int, int);
void kayac_gezegen_yok_et(KAYAC_GEZEGEN* k);
#endif