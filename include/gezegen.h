#ifndef GEZEGEN_H
#define GEZEGEN_H
#include "zaman.h"

typedef struct GEZEGEN {
    char* isim;
    int tur;
    int gunluk_saat;
    Zaman* zaman;
    int populasyon;
    float yas_carpani;
    void (*ileri_sar)(struct GEZEGEN*);
    void (*yok_et)(struct GEZEGEN*);
} GEZEGEN;

GEZEGEN* gezegen_olustur(const char* isim, int tur, int gunluk_saat, int gun, int ay, int yil);
void gezegen_ileri_sar(GEZEGEN* g);
void gezegen_yok_et(GEZEGEN* g);

#endif