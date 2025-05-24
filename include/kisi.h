#ifndef KISI_H
#define KISI_H

typedef struct KISI {
    char* isim;
    int yas;
    float kalan_omur;
    int hayatta_mi;
    char* arac_adi;
    void (*yaslandir)(struct KISI*, float);
    void (*yok_et)(struct KISI*);
} KISI;

KISI* kisi_olustur(const char*, int, float, const char*);
void kisi_yaslandir(KISI*, float);
void kisi_yok_et(KISI*);
#endif