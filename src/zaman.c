#include <stdio.h>
#include <stdlib.h>
#include "zaman.h"

static int ay_gun_sayisi(int ay, int yil) {
    switch (ay) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return ((yil%4==0 && yil%100!=0) || (yil%400==0)) ? 29 : 28;
        default: return 31;
    }
}

Zaman* zaman_olustur(int gun, int ay, int yil, int gunluk_saat) {
    Zaman* z = malloc(sizeof(Zaman));
    z->gun = gun; z->ay = ay; z->yil = yil;
    z->saat = 0; z->gunluk_saat = gunluk_saat;
    return z;
}

void zaman_ileri_sar(Zaman* z) {
    if (!z) return;
    z->saat++;
    if (z->saat >= z->gunluk_saat) {
        z->saat = 0;
        z->gun++;
        if (z->gun > ay_gun_sayisi(z->ay, z->yil)) {
            z->gun = 1;
            z->ay++;
            if (z->ay > 12) { z->ay = 1; z->yil++; }
        }
    }
}

void zaman_yazdir(const Zaman* z, char* buf, int bufsize) {
    snprintf(buf, bufsize, "%02d.%02d.%04d %02d:00", z->gun, z->ay, z->yil, z->saat);
}

void zaman_yok_et(Zaman* z) { free(z); }