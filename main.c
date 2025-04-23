#include <stdio.h>
#include "KelolaKota.h"

int main(){
	
	Warga warga;
	Kota A[5];	
	char namaKota[100];
    int JmlKota,i,opsi;
    printf("Masukan jumlah kota yang ingin di-input : ");
    scanf("%d",&JmlKota);
    getchar();
    
    
    for(i = 0; i < JmlKota; i++){
    	InputKota(A,i);
	}
    
    printf("1. Masukan Data Warga\n2. Delete Warga\nPilih Opsi (1/2) : ");
    scanf("%d",&opsi);
    getchar();
    
    if(opsi == 1){
//    	InputNama(A);
	}
}