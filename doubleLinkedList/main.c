#include <stdio.h>
#include "KelolaKota.h"

int main(){
    
    Kota A;
    ListKota LKota;
    Warga warga;
    char namaKota[50],NamaDihapus[50];
    int JmlKota, i, opsi, pilihkota, KotaDihapus;
    
    CreateList(&LKota);
    
    while(1) {
        printf("\n1. Masukan Kota\n2. Masukan Data Warga\n3. Delete Warga\n4. Delete Kota\n5. Print Data\nPilih Opsi (1/2/3/4) : ");
        scanf("%d",&opsi);
        printf("\n");
        getchar();
        
        if(opsi == 1){
            InputKota(&LKota);

        }else if(opsi == 2){
            InputWarga(&LKota);

        }else if(opsi == 3){
            DeleteWarga(&LKota);

        }else if(opsi == 4){
            DeleteKota(&LKota);

        }else if(opsi == 5){
            PrintData(LKota);

        }else{
            printf("Pilihan yang anda masukan tidak valid");
            
        }
        }
    
}