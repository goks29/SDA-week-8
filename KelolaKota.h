#ifndef KelolaKota_H
#define KelolaKota_H
#include "SpNRSLL.H"

void InputKota(Kota A[],int index); 

<<<<<<< HEAD
void InputWarga(Kota A[]);
=======
void InputWarga(Kota *ListKota, int Index);
>>>>>>> f60730cc2dd72193531ef7fa7d6a2671b6c55964

void DeleteKota(Kota A[],int i);

void DeleteWarga(Kota A[],int i,char NamaWarga[50]);

void PrintData(Kota A[]);


#endif