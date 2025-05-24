#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gezegen.h"

static float tur_carpani(int tur) {
    switch (tur) {
        case 1: return 0.1f;
        case 2: return 0.5f;
        case 3: return 0.01f;
        default: return 1.0f;
    }
}

static void ileri_impl(GEZEGEN* g) { zaman_ileri_sar(g->zaman); }
static void yok_impl(GEZEGEN* g) {
    free(g->isim);
    zaman_yok_et(g->zaman);
    free(g);
}

GEZEGEN* gezegen_olustur(const char* isim, int tur, int gunluk_saat, int gun, int ay, int yil) {
    GEZEGEN* g = malloc(sizeof(GEZEGEN));
    g->isim = strdup(isim);
    g->tur = tur;
    g->gunluk_saat = gunluk_saat;
    g->zaman = zaman_olustur(gun, ay, yil, gunluk_saat);
    g->populasyon = 0;
    g->yas_carpani = tur_carpani(tur);
    g->ileri_sar = ileri_impl;
    g->yok_et = yok_impl;
    return g;
}

void gezegen_ileri_sar(GEZEGEN* g) { if (g && g->ileri_sar) g->ileri_sar(g); }
void gezegen_yok_et(GEZEGEN* g) { if (g && g->yok_et) g->yok_et(g); }