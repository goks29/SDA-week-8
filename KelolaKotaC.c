#include "KelolaKota.h"

void InputKota(Kota *ListKota, int index) {
    printf("Masukan Nama Kota ke-%d : ",index+1);
    scanf("%s",ListKota[index].kt);
    
    ListKota[index].next = NULL;
}

void InputWarga(Kota *ListKota, int Index) {
	Warga warga;
	char namaorang[100];
	printf("Masukan Data Nama : ");
	scanf("%s",warga.nm);
	
	address Listbaru = Alokasi(warga);
	if(Listbaru==NULL){
		printf("alokasi gagal");
		return;
	}
	
}

void DeleteKota(Kota A[],int i) {
    strcpy(A[i].kt,"");
    A[i].next = Nil;
}

void DeleteWarga(Kota A[],int i,char NamaWarga[50]) {
    address Prec, PDel;
    List L;
    L.First = A[i].next;
    Prec = SearchPrec(L,NamaWarga);

    if (Prec == Nil) {
        PDel = L.First;
        L.First = PDel->next;
        DeAlokasi(PDel);
    } else {
        PDel = Prec->next;
        if (PDel != Nil && strcmp(PDel->nm,NamaWarga) == 0) {
            Prec->next = PDel->next;
            PDel->next = Nil;
            free(PDel);
        }
    }
}

void PrintData(Kota A[]) {
    address P;
    int i = 0;

    while (i != 5) {
        if (A[i].next != NULL) {
            printf("kota: %s\n",A[i].kt);
            P = A[i].next;
            while (P != NULL) {
                printf("->%s",P->nm);
                P = P->next;
            }
            printf("\n\n");
        } else {
            if (strcmp(A[i].kt,"") == 0) {
                printf("Kota: Kosong/Dihapus\n\n");
            } else {
                printf("kota: %s \nkosong\n\n",A[i].kt);
            }
        }
        i++;
    }
}