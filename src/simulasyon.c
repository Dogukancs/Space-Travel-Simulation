#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simulasyon.h"

//Ekranı temizleme
static void temizle() {
    system("cls");
}

static int tarih_esit(Zaman* z, int gun, int ay, int yil) {
    return z->gun == gun && z->ay == ay && z->yil == yil;
}

void simulasyonu_baslat(GEZEGEN** gz, int gn, UZAYARACI** ar, int an) {
    int tamam = 0;
    while (!tamam) {
        temizle();

        //Gezegen Başlıkları
        printf("Gezegenler:\n          ");
        for (int i = 0; i < gn; i++) printf("--- %s --- ", gz[i]->isim);
        printf("\nTarih     ");
        for (int i = 0; i < gn; i++) {
            char b[32];
            zaman_yazdir(gz[i]->zaman, b, sizeof(b));
            printf("%12s ", b);
        }
        printf("\nNufus     ");
        int* nufuslar = calloc(gn, sizeof(int));
        for (int i = 0; i < an; i++) {
            if (!ar[i]->yolculukta && !ar[i]->imha) {
                for (int g = 0; g < gn; g++) {
                    if (strcmp(ar[i]->cikis, gz[g]->isim) == 0) {
                        for (int k = 0; k < ar[i]->kisi_sayisi; k++)
                            if (ar[i]->kisiler[k]->hayatta_mi)
                                nufuslar[g]++;
                    }
                }
            }
        }
        for (int i = 0; i < gn; i++) printf("%12d ", nufuslar[i]);
        free(nufuslar);
        printf("\n\nUzay Araclari:\n");
        printf("%-10s %-10s %-10s %-10s %-20s %s\n",
               "Arac Adi", "Durum", "Cikis", "Varis",
               "Hedefe Kalan Saat", "Hedefe Varis Tarihi");

        for (int i = 0; i < an; i++) {
            UZAYARACI* a = ar[i];
            char durum[10] = "", varisT[16] = "";

            if (a->imha) {
                strcpy(durum, "IMHA");
                strcpy(varisT, "--");
            } else if (a->yolculukta) {
                strcpy(durum, "Yolda");
                snprintf(varisT, sizeof(varisT), "??.??.????");
            } else {
                strcpy(durum, "Bekliyor");
                snprintf(varisT, sizeof(varisT), "%02d.%02d.%04d",
                         a->cikis_gun, a->cikis_ay, a->cikis_yil);
            }

            printf("%-10s %-10s %-10s %-10s %-20d %s\n",
                   a->isim, durum, a->cikis, a->varis,
                   a->hedefe_kalan, varisT);
        }

        //Simülasyonu ilerlet
        for (int i = 0; i < gn; i++) gz[i]->ileri_sar(gz[i]);

        for (int i = 0; i < an; i++) {
            UZAYARACI* a = ar[i];

            //Çıkış zamanı kontrolü
            for (int g = 0; g < gn; g++) {
                if (strcmp(a->cikis, gz[g]->isim) == 0 && tarih_esit(gz[g]->zaman, a->cikis_gun, a->cikis_ay, a->cikis_yil)) {
                    a->yolculukta = 1;
                }
            }

            if (a->yolculukta && !a->imha) a->ilerlet(a);

            for (int k = 0; k < a->kisi_sayisi; k++) {
                if (!a->yolculukta) {
                    for (int g = 0; g < gn; g++) {
                        if (strcmp(a->cikis, gz[g]->isim) == 0) {
                            kisi_yaslandir(a->kisiler[k], gz[g]->yas_carpani);
                        }
                    }
                } else {
                    kisi_yaslandir(a->kisiler[k], 1.0f);
                }
            }

            int hayatta = 0;
            for (int k = 0; k < a->kisi_sayisi; k++)
                if (a->kisiler[k]->hayatta_mi) hayatta++;
            if (hayatta == 0) a->imha = 1;
        }

        //Araçlar vardımı kontolü ,tüm araçlar vardı mı?
        tamam = 1;
        for (int i = 0; i < an; i++) {
            if (!ar[i]->imha && ar[i]->hedefe_kalan > 0) {
                tamam = 0;
                break;
            }
        }
        
    }
    printf("\nSimulasyon tamamlandi.\n");
}