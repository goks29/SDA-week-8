#include "KelolaKota.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void InputKota(ListKota *LKota) {
    secondAddress Last,P;
    char NamaKota[50];

    printf("Masukan Nama Kota : ");
    scanf("%s", NamaKota);
    P = AlokasiKota(NamaKota);
    if (P != Nil) {
        if (LKota->First != Nil) {
            InsertLast(LKota,P);
        } else {
            LKota->First = P;
        }
    } else {
        printf("Alokasi gagal");
    }
}

void InputWarga(ListKota *LKota) {
    secondAddress tujuan;
    address NodeW;
    char NamaKota[50];
    char warga[50];

    printf("Masukan Nama Kota: ");
    scanf("%s", NamaKota);

    printf("Masukan Nama Warga: ");
    scanf("%s", warga);

    NodeW = Alokasi(warga);
    if (NodeW != Nil) {
        if ((*LKota).First == Nil) {
            printf("Kota Tidak ada");
            return;
        }

        tujuan = (*LKota).First;
        while (tujuan != Nil && strcmp((*tujuan).kt,NamaKota) != 0) {
            tujuan = (*tujuan).nextKota;
        }

        if (tujuan == Nil) {
            printf("Kota tidak ditemukan");
        }

        if ((*tujuan).next == Nil) {
            (*tujuan).next = NodeW;
        } else {
            InsertLastW(tujuan,NodeW);
        }
    } else {
        printf("Alokasi gagal");
    }
}

void DeleteKota(ListKota * LKota) {
    secondAddress Pdel,Prec;
    address PWarga, tempWarga;
    char NamaKota[50];

    printf("Masukan nama kota yang ingin dihapus :");
    scanf("%s",NamaKota);
    
    if ((strcmp(LKota->First->kt,NamaKota) == 0)) {
        Pdel = LKota->First;
        PWarga = LKota->First->next;
        while (PWarga != NULL) {
            tempWarga = PWarga;
            PWarga = PWarga->next;
            free(tempWarga);
        }
        LKota->First = Pdel->nextKota;
        Pdel->nextKota = Nil;
        free(Pdel);
        return;
    }

    Prec = LKota->First;
    while ((strcmp(Prec->nextKota->kt,NamaKota) != 0) && Prec->nextKota != Nil) {
        Prec = Prec->nextKota;
    }

    if (Prec->nextKota == Nil) {
        printf("Kota tidak ada");
        return;
    }

    Pdel = Prec->nextKota;
    PWarga = Pdel->next;
    while (PWarga != NULL) {
        tempWarga = PWarga;
        PWarga = PWarga->next;
        free(tempWarga);
    }
    Prec->nextKota = Pdel->nextKota;
    Pdel->nextKota = Nil;
    free(Pdel);
}

void DeleteWarga(ListKota *LKota) {
    secondAddress tujuanKota;
    address Pdel,Prec;
    char NamaKota[50];
    char NamaWarga[50];

    printf("Masukan nama kota yang warganya ingin dihapus :");
    scanf("%s",NamaKota);

    printf("Masukan nama warga yang ingin dihapus :");
    scanf("%s",NamaWarga);

    tujuanKota = LKota->First;
    while ((strcmp(tujuanKota->kt,NamaKota) != 0) && tujuanKota != Nil) {
        tujuanKota = tujuanKota->nextKota;
    }

    if (tujuanKota == Nil) {
        printf("Kota tidak ada\n");
    }

    if ((strcmp(tujuanKota->next->nm,NamaWarga) == 0) && tujuanKota->next != Nil) {
        Pdel = tujuanKota->next;
        tujuanKota->next = Pdel->next;
        Pdel->next = Nil;
        free(Pdel);
        return;
    }

    Prec = tujuanKota->next;
    while ((strcmp(Prec->next->nm,NamaWarga) != 0) && Prec->next != Nil) {
        Prec = Prec->next;
    }
    
    if (Prec->next == Nil) {
        printf("Warga tidak ditemukan\n");
    }
        Pdel = Prec->next;
        Prec->next = Pdel->next;
        Pdel->next = Nil;
        free(Pdel);

    
}

void PrintData(ListKota LKota) {
    secondAddress P;
    address PWarga;
    int i = 1;

    P = LKota.First;

    if (P == Nil) {
        printf("Tidak ada Kota yang dimasukan\n");
    } else {
        while (P != Nil) {
            printf("\n\nKota ke -%d : %s\n",i, P->kt);
            PWarga = P->next;
            if (P->next != Nil) {
                while (PWarga != Nil) {
                    printf("%s -> ",PWarga->nm);
                    PWarga = PWarga->next;
                }
            } else {
                printf("Warga di kota ini kosong\n\n");
            }
    
            P = P->nextKota;
            i++;
        }
    
    }
    
}
