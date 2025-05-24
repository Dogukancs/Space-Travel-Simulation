#include <stdlib.h>
#include <string.h>
#include "uzayaraci.h"

#define MAX_KISI 100

static void ilerlet_impl(UZAYARACI* a) {
    if (!a || !a->yolculukta || a->imha) return;
    a->hedefe_kalan--;
    if (a->hedefe_kalan <= 0) {
        a->hedefe_kalan = 0;
        a->yolculukta = 0;
    }
    int hay = 0;
    for (int i = 0; i < a->kisi_sayisi; i++)
        if (a->kisiler[i]->hayatta_mi) hay++;
    if (hay == 0) a->imha = 1;
}

static void yok_impl(UZAYARACI* a) {
    free(a->isim);
    free(a->cikis);
    free(a->varis);
    for (int i = 0; i < a->kisi_sayisi; i++)
        kisi_yok_et(a->kisiler[i]);
    free(a->kisiler);
    free(a);
}

UZAYARACI* uzayaraci_olustur(const char* isim, const char* cikis, const char* varis,
                              int gun, int ay, int yil, int mesafe) {
    UZAYARACI* a = malloc(sizeof(UZAYARACI));
    a->isim = strdup(isim);
    a->cikis = strdup(cikis);
    a->varis = strdup(varis);
    a->cikis_gun = gun;
    a->cikis_ay = ay;
    a->cikis_yil = yil;
    a->mesafe = mesafe;
    a->hedefe_kalan = mesafe;
    a->yolculukta = 0;
    a->imha = 0;
    a->kisi_sayisi = 0;
    a->kisiler = malloc(sizeof(KISI*) * MAX_KISI);
    a->ilerlet = ilerlet_impl;
    a->yok_et = yok_impl;
    return a;
}

void uzayaraci_ilerlet(UZAYARACI* a) {
    if (a && a->ilerlet) a->ilerlet(a);
}

void uzayaraci_kisi_ekle(UZAYARACI* a, KISI* k) {
    if (!a || a->kisi_sayisi >= MAX_KISI) return;
    a->kisiler[a->kisi_sayisi++] = k;
}

void uzayaraci_yok_et(UZAYARACI* a) {
    if (a && a->yok_et) a->yok_et(a);
}