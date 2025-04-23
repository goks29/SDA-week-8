#include <stdio.h>
#include "KelolaKota.h"

int main(){
	
		
    Warga warga;
    char namaKota[100];
    int JmlKota,i,opsi,pilihkota;
    Kota* A = InputKota(&JmlKota);
    

    while(1) { 
        printf("Menu : \n");
        printf("1. Masukan Data Warga\n2. Delete Kota\n3. Delete Warga\n4. Print Data\nPilih Opsi (1/2) : ");
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
            for(i=0;i<JmlKota;i++){
                printf("%d. %s\n",i+1,A[i].kt);
            }
            printf("Pilih No Kota yang ingin dihapus : ");
            scanf("%d",&pilihkota);
            getchar();
            
            DeleteKota(A, pilihkota -1);
        }
    }
    
    
    
}