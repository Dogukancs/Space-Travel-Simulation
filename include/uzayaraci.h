#ifndef UZAYARACI_H
#define UZAYARACI_H
#include "kisi.h"

typedef struct UZAYARACI {
    char* isim;
    char* cikis;
    char* varis;
    int cikis_gun, cikis_ay, cikis_yil;
    int mesafe;
    int hedefe_kalan;
    int yolculukta;
    int imha;
    int kisi_sayisi;
    KISI** kisiler;
    void (*ilerlet)(struct UZAYARACI*);
    void (*yok_et)(struct UZAYARACI*);
} UZAYARACI;

UZAYARACI* uzayaraci_olustur(const char*, const char*, const char*, int, int, int, int);
void uzayaraci_ilerlet(UZAYARACI*);
void uzayaraci_kisi_ekle(UZAYARACI*, KISI*);
void uzayaraci_yok_et(UZAYARACI*);
#endif