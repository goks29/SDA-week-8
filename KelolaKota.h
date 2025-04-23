#ifndef KelolaKota_H
#define KelolaKota_H
#include "SpNRSLL.H"

Kota* InputKota(int* jumlahKota); 

void InputWarga(Kota A[]);

void DeleteKota(Kota A[],int i);

void DeleteWarga(Kota A[],int i,char NamaWarga[50]);

void PrintData(Kota A[]);


#endif