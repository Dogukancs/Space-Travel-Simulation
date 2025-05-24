#ifndef DOSYA_OKUMA_H
#define DOSYA_OKUMA_H
#include "gezegen.h"
#include "uzayaraci.h"
#include "kisi.h"

GEZEGEN** gezegenleri_oku(const char* dosya, int* adet);
UZAYARACI** araclari_oku(const char* dosya, int* adet);
KISI** kisileri_oku(const char* dosya, int* adet);

#endif