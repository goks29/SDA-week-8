#include "KelolaKota.h"

void InputKota() {
    
}

void InputWarga() {

}

void DeleteKota(Kota A[],int i) {
    strcpy(A[i].kt,"");
    A[i].next = Nil;
}

void DeleteWarga(Kota A[],int i,char NamaWarga[50]) {
    address Prec, PDel;
    List *L = &(A[i].next);
    Prec = SearchPrec(*L,NamaWarga);

    if (Prec == Nil) {
        PDel = L->First;
        L->First = PDel->next;
        DeAlokasi(PDel);
    } else {
        PDel = Prec->next;
        if (PDel != Nil && strcmp(PDel,NamaWarga)) {
            Prec->next = PDel->next;
            PDel->next = Nil;
            free(PDel);
        }
    }
}

void PrintData() {

}