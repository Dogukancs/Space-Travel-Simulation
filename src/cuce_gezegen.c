#include <stdlib.h>
#include "cuce_gezegen.h"

CUCE_GEZEGEN* cuce_gezegen_olustur(const char* i, int gs, int g, int a, int y) {
    CUCE_GEZEGEN* cd = malloc(sizeof(CUCE_GEZEGEN));
    GEZEGEN* tmp = gezegen_olustur(i, 3, gs, g, a, y);
    cd->base = *tmp;
    free(tmp);
    return cd;
}

void cuce_gezegen_yok_et(CUCE_GEZEGEN* cd) { gezegen_yok_et(&cd->base); free(cd); }