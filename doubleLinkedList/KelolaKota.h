#ifndef KelolaKota_H
#define KelolaKota_H
#include "SpNRSLL.H"
 
void InputKota(ListKota *LKota);

void InputWarga(Kota A[], int index);

void DeleteKota(Kota A[],int i);

void DeleteWarga(Kota A[],int i,char NamaWarga[50]);

void PrintData(ListKota LKota);


#endif