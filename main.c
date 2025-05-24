#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dosya_okuma.h"
#include "simulasyon.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include <locale.h>


int main(){
    setlocale(LC_ALL, "Turkish");
    #ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    #endif
    int gn, an, kn;
    GEZEGEN** gz=gezegenleri_oku("data/Gezegenler.txt",&gn);
    UZAYARACI** ar=araclari_oku("data/Araclar.txt",&an);
    KISI** ks=kisileri_oku("data/Kisiler.txt",&kn);
    for(int i=0;i<kn;i++)
      for(int j=0;j<an;j++)
        if(strcmp(ks[i]->arac_adi,ar[j]->isim)==0)
          uzayaraci_kisi_ekle(ar[j], ks[i]);
    simulasyonu_baslat(gz,gn,ar,an);
    // cleanup
    for(int i=0;i<gn;i++) gezegen_yok_et(gz[i]);
    for(int i=0;i<an;i++) uzayaraci_yok_et(ar[i]);
    free(gz); free(ar); free(ks);
    return 0;
}
