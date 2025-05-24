#include <stdlib.h>
#include <string.h>
#include "kisi.h"

static void yaslandir_impl(KISI* k, float carpan) {
    if (!k || !k->hayatta_mi) return;
    k->kalan_omur -= carpan;
    if (k->kalan_omur <= 0) { k->kalan_omur = 0; k->hayatta_mi = 0; }
}

static void yok_impl(KISI* k) {
    free(k->isim);
    free(k->arac_adi);
    free(k);
}

KISI* kisi_olustur(const char* isim, int yas, float kalom, const char* arac) {
    KISI* k = malloc(sizeof(KISI));
    k->isim = strdup(isim);
    k->yas = yas;
    k->kalan_omur = kalom;
    k->hayatta_mi = 1;
    k->arac_adi = strdup(arac);
    k->yaslandir = yaslandir_impl;
    k->yok_et = yok_impl;
    return k;
}

void kisi_yaslandir(KISI* k, float c) { if(k && k->yaslandir) k->yaslandir(k, c); }
void kisi_yok_et(KISI* k) { if(k && k->yok_et) k->yok_et(k); }