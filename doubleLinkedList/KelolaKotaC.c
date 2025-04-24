#include "KelolaKota.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void InputKota(Kota *ListKota, int index) {
    Kota *P;
    char NamaWarga[50];
    printf("Masukan Nama Kota ke-%d : ", index + 1);
    scanf("%s", NamaWarga);
    P =(Kota *)malloc(sizeof(Kota));
    if (P != Nil)
    {
       strcpy(P->kt,NamaWarga);
       P->next = Nil;
    }
    ListKota[index] = *P;
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

void PrintData(Kota A[],int jmlhKota) {
    address P;
    for (int i = 0; i < jmlhKota; i++) {
        if (strlen(A[i].kt) == 0) {
            printf("Kota %d: Kosong/Dihapus\n\n", i + 1);
            continue;
        }

        printf("Kota %d: %s\n", i + 1, A[i].kt);

        if (A[i].next == NULL) {
            printf("-> Tidak ada warga\n\n");
        } else {
            P = A[i].next;
            while (P != NULL) {
                printf("-> %s ", P->nm);
                P = P->next;
            }
            printf("\n\n");
        }
    }
}
