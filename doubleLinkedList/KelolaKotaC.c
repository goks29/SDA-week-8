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

void InputWarga(Kota *ListKota, int index) {
    char warga[50];
    printf("Masukan Nama Warga: ");
    scanf("%s", warga);

    address newNode = Alokasi(warga);
    if (newNode == NULL) {
        printf("Alokasi gagal\n");
        return;
    }
    if (ListKota[index].next == NULL) {
        ListKota[index].next = newNode;
    } else {
        address temp = ListKota[index].next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void DeleteKota(Kota A[], int i) {
    strcpy(A[i].kt, "");
    A[i].next = NULL;
}

void DeleteWarga(Kota A[], int i, char NamaWarga[50]) {
    address Prec, PDel;
    List L;
    L.First = A[i].next;
    Prec = SearchPrec(L, NamaWarga);

    if (Prec == Nil) {
        PDel = L.First;
        if (PDel != NULL && strcmp(PDel->nm, NamaWarga) == 0) {
            A[i].next = PDel->next;
            DeAlokasi(PDel);
        }
    } else {
        PDel = Prec->next;
        if (PDel != NULL && strcmp(PDel->nm, NamaWarga) == 0) {
            Prec->next = PDel->next;
            PDel->next = NULL;
            DeAlokasi(PDel);
        }
    }
}

void PrintData(ListKota LKota) {
    secondAddress P;
    int i = 1;

    P = LKota.First;

    if (P == Nil) {
        printf("Tidak ada Kota yang dimasukan\n");
    } else {
        while (P != Nil) {
            printf("Kota ke -%d : %s\n",i, P->kt);
    
            if (P->next != Nil) {
                while (P->next->next != Nil) {
                    printf("%s ->",P->next->nm);
                    P->next = P->next->next;
                }
            } else {
                printf("Warga di kota ini kosong\n\n");
            }
    
            P = P->nextKota;
            i++;
        }
    
    }
    
}
