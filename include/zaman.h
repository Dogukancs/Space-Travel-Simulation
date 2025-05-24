#ifndef ZAMAN_H
#define ZAMAN_H

typedef struct {
    int gun, ay, yil;
    int saat, gunluk_saat;
} Zaman;

Zaman* zaman_olustur(int gun, int ay, int yil, int gunluk_saat);
void zaman_ileri_sar(Zaman* z);
void zaman_yazdir(const Zaman* z, char* buf, int bufsize);
void zaman_yok_et(Zaman* z);

#endif