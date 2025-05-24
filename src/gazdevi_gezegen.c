#include <stdlib.h>
#include "gazdevi_gezegen.h"

GAZDEVI_GEZEGEN* gazdevi_gezegen_olustur(const char* i, int gs, int g, int a, int y) {
    GAZDEVI_GEZEGEN* gd = malloc(sizeof(GAZDEVI_GEZEGEN));
    GEZEGEN* tmp = gezegen_olustur(i, 1, gs, g, a, y);
    gd->base = *tmp;
    free(tmp);
    return gd;
}

void gazdevi_gezegen_yok_et(GAZDEVI_GEZEGEN* gd) { gezegen_yok_et(&gd->base); free(gd); }