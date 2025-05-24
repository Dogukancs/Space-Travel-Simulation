#include <stdlib.h>
#include "kayac_gezegen.h"

KAYAC_GEZEGEN* kayac_gezegen_olustur(const char* i, int gs, int g, int a, int y) {
    KAYAC_GEZEGEN* k = malloc(sizeof(KAYAC_GEZEGEN));
    GEZEGEN* tmp = gezegen_olustur(i, 0, gs, g, a, y);
    k->base = *tmp;
    free(tmp);
    return k;
}

void kayac_gezegen_yok_et(KAYAC_GEZEGEN* k) { gezegen_yok_et(&k->base); free(k); }