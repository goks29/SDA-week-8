#include <stdio.h>
#include "KelolaKota.h"

int main(){
	
	Warga warga;
	Kota A[5];	
	char namaKota[100];
    int JmlKota,i,opsi,pilihkota;

    printf("Masukan jumlah kota yang ingin di-input : ");
    scanf("%d",&JmlKota);
    getchar();
    for(i = 0; i < JmlKota; i++){
        InputKota(A,i);
    }

    while(1) { 
        printf("Menu : \n");
        printf("1. Masukan Data Warga\n2. Delete Warga\n3. Print Warga\nPilih Opsi (1/2) : ");
        scanf("%d",&opsi);
        getchar();
        
        if(opsi == 1){
            for(i=0;i<JmlKota;i++){
                printf("%d. %s\n",i+1,A[i].kt);
            }
            printf("Pilih No Kota yang ingin Ditambahkan : ");
            scanf("%d",&pilihkota);
            getchar();
            
            InputWarga(A, pilihkota -1);
        }
        
        if (opsi == 2){
            
        }
    }
    
    
    
}