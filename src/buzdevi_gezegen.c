#include <stdlib.h>
#include "buzdevi_gezegen.h"

BUZDEVI_GEZEGEN* buzdevi_gezegen_olustur(const char* i, int gs, int g, int a, int y) {
    BUZDEVI_GEZEGEN* bd = malloc(sizeof(BUZDEVI_GEZEGEN));
    GEZEGEN* tmp = gezegen_olustur(i, 2, gs, g, a, y);
    bd->base = *tmp;
    free(tmp);
    return bd;
}

void buzdevi_gezegen_yok_et(BUZDEVI_GEZEGEN* bd) { gezegen_yok_et(&bd->base); free(bd); }