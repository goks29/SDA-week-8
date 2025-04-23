#include "KelolaKota.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Kota* InputKota(int* jumlahKota) {
    
	int i;
	printf("Masukkan jumlah kota: ");
    scanf("%d", jumlahKota);
    getchar();

    Kota* ListKota = (Kota*) malloc((*jumlahKota) * sizeof(Kota));
    if (ListKota == NULL) {
        printf("Alokasi gagal.\n");
        exit(1);
    }

    for (i = 0; i < *jumlahKota; i++) {
        printf("Masukkan nama kota ke-%d: ", i + 1);
        scanf("%s", ListKota[i].kt);
        ListKota[i].next = NULL;
    }

    return ListKota;
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

void PrintData(Kota A[]) {
    address P;
    for (int i = 0; i < 5; i++) {
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
