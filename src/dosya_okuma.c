#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dosya_okuma.h"
#include "kayac_gezegen.h"
#include "gazdevi_gezegen.h"
#include "buzdevi_gezegen.h"
#include "cuce_gezegen.h"

#define MAX 128

GEZEGEN** gezegenleri_oku(const char* dosya, int* adet) {
    FILE* f = fopen(dosya, "r");
    if (!f) return NULL;
    GEZEGEN** arr = malloc(sizeof(GEZEGEN*)*MAX);
    char satir[MAX];
    *adet = 0;
    while (fgets(satir, MAX, f)) {
        char* isim = strtok(satir,"#");
        int tur=atoi(strtok(NULL,"#"));
        int gs=atoi(strtok(NULL,"#"));
        char* tr= strtok(NULL,"#");
        int g,a,y; sscanf(tr,"%d.%d.%d",&g,&a,&y);
        GEZEGEN* g0 = NULL;
        switch(tur) {
            case 0: g0=(GEZEGEN*)kayac_gezegen_olustur(isim,gs,g,a,y); break;
            case 1: g0=(GEZEGEN*)gazdevi_gezegen_olustur(isim,gs,g,a,y); break;
            case 2: g0=(GEZEGEN*)buzdevi_gezegen_olustur(isim,gs,g,a,y); break;
            case 3: g0=(GEZEGEN*)cuce_gezegen_olustur(isim,gs,g,a,y); break;
        }
        arr[(*adet)++] = g0;
    }
    fclose(f);
    return arr;
}

UZAYARACI** araclari_oku(const char* dosya, int* adet) {
    FILE* f = fopen(dosya,"r");
    if (!f) return NULL;
    UZAYARACI** arr = malloc(sizeof(UZAYARACI*)*MAX);
    char satir[MAX];
    *adet=0;
    while(fgets(satir,MAX,f)) {
        char* isim=strtok(satir,"#");
        char* cik=strtok(NULL,"#");
        char* var=strtok(NULL,"#");
        char* tr=strtok(NULL,"#");
        int g,a,y; sscanf(tr,"%d.%d.%d",&g,&a,&y);
        int ms=atoi(strtok(NULL,"#\n"));
        arr[(*adet)++] = uzayaraci_olustur(isim,cik,var,g,a,y,ms);
    }
    fclose(f);
    return arr;
}

KISI** kisileri_oku(const char* dosya, int* adet) {
    FILE* f = fopen(dosya,"r");
    if (!f) return NULL;
    KISI** arr = malloc(sizeof(KISI*)*MAX);
    char satir[MAX];
    *adet=0;
    while(fgets(satir,MAX,f)) {
        char* isim=strtok(satir,"#");
        int ys=atoi(strtok(NULL,"#"));
        float ko=atof(strtok(NULL,"#"));
        char* ar=strtok(NULL,"#\n");
        arr[(*adet)++] = kisi_olustur(isim,ys,ko,ar);
    }
    fclose(f);
    return arr;
}