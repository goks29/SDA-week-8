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
            }//else if(opsi == 2){
    //         for(i=0;i<JmlKota;i++){
    //             printf("%d. %s\n",i+1,A[i].kt);
    //         }
    //         printf("Pilih No Kota yang ingin Ditambahkan : ");
    //         scanf("%d",&pilihkota);
    //         getchar();
            
    //         InputWarga(A, pilihkota -1);

    //     }else if(opsi == 3){
    //         for(i=0;i<JmlKota;i++){
    //             printf("%d. %s\n",i+1,A[i].kt);
    //         }
    //         printf("Pilih No Kota warga yang ingin dihapus : ");
    //         scanf("%d",&pilihkota);
    //         getchar();
            
    //         printf("\nData Nama yang akan dihapus : ");
    //         scanf("%s",NamaDihapus);
            
    //         DeleteWarga(A, pilihkota - 1, NamaDihapus);

    //     }else if(opsi == 4){
    //         for(i=0;i<JmlKota;i++){
    //             printf("%d. %s\n",i+1,A[i].kt);
    //         }
    //         printf("Masukan Kota yang akan dihapus : ");
    //         scanf("%d",&KotaDihapus);
            
    //         DeleteKota(A, KotaDihapus - 1);

        else if(opsi == 5){
            PrintData(LKota);
        }else{
            printf("Pilihan yang anda masukan tidak valid");
            
        }
        }
    
}