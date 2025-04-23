#include "KelolaKota.h"

void InputKota(Kota *ListKota, int index) {
    printf("Masukan Nama Kota ke-%d : ",index+1);
    scanf("%s",ListKota[index].kt);
    
    ListKota[index].next = NULL;
}

void InputWarga() {

}

void DeleteKota() {

}

void DeleteWarga() {

}

void PrintData() {
    
}