/* File        : bodyNRSL.c */
/* Deskripsi   : Body prototype ADT Non Restricted Single Linked/Linear list yang hanya dikenali First(L) */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 24-10-2001 */

#include <limits.h>
#include <malloc.h>
#include "spnrsll.h"

/********** BODY SUB PROGRAM ***********/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L)
/* Mengirim true jika List Kosong */
{
	 return (L.First == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (ListKota * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	(*L).First = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (char NamaWarga[50])
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (Warga));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
		strcpy(P->nm,NamaWarga);
		P->next = Nil;
	 }
	 return (P);
}

secondAddress AlokasiKota (char NamaWarga[50])
{
	 /* Kamus Lokal */
	 secondAddress P;
	 /* Algoritma */
	 P = (secondAddress) malloc (sizeof (Kota));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
		strcpy(P->kt,NamaWarga);
		P->next = Nil;
		P->nextKota = Nil;
	 }
	 return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
{
	 if (P != Nil)
	 {
		free (P);
	 }
}

address SearchPrec (List L, char NamaWarga[50])
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */
{
	 /* Kamus Lokal */
	address Prec, P;
	boolean found=false;
	 /* Algoritma */
	Prec = Nil;
	P = L.First;
	while ((P != Nil) && (!found))
	{
		 if (strcmp(P->nm,NamaWarga))
		 {	found = true;	}
		 else
		 {
			Prec = P;
			P = P->next;
		 }
	}    /* P = Nil atau Ketemu */
	if (found)
	{	return (Prec);		}
	else
	{	return (Nil);		}
}


void InsVLast (List * L, char NamaWarga[50])
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
    /* Kamus Lokal */
    address P;
    address temp;
    Warga X;

    strcpy(X.nm, NamaWarga);

    /* Algoritma */
    P = Alokasi(NamaWarga);
    if (P != Nil) {
        if ((*L).First == Nil) {
            (*L).First = P;
        } else {
            temp = (*L).First;
            while (temp->next != Nil) {
                temp = temp->next;
            }
            temp->next = P;
        }
    }
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, Warga * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = (*L).First;
	strcpy(X->nm,P->nm);
	(*L).First = P->next;
	DeAlokasi(P);
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelVLast (List * L, Warga * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	address PDel,prev = Nil;
	 /* Algoritma */
	 PDel = (*L).First;
	 if (PDel->next == Nil) {
		strcpy(X->nm,PDel->nm);
		(*L).First = Nil;
		DeAlokasi(PDel);
		return;
	 } 

	 while(PDel->next != Nil) {
		prev = PDel;
		PDel = PDel->next;
	 }
	 strcpy(X->nm,prev->nm);
	 prev->next = Nil;
	 DeAlokasi(PDel);
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	P->next = (*L).First;
	(*L).First = P;
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsertAfter (List * L, address P, address Prec)
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	if (Prec != NULL) {
		P->next = Prec->next;
		Prec->next = P; 
	}
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsertLast (ListKota * L, secondAddress P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	secondAddress Last;
	 /* Algoritma */
	 if ((*L).First == Nil) {
		(*L).First = P;
	 } else {
		Last = (*L).First;
		while (Last->nextKota != Nil) {
			Last = Last->nextKota;
		}
		Last->nextKota = P;
	 }
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
{
	if ((*L).First != Nil) {
		*P = (*L).First;
		(*L).First = (*P)->next;
		DeAlokasi(*P);
	}
	//Buatkan algoritma sesuai spesifikasi modul ini
}


void DelLast (List * L, address * P)
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
{
	 /* Kamus Lokal */
	address Prec;
	 /* Algoritma */
	 *P = (*L).First;
	 if ((*L).First->next != Nil) {

		while ((*P)->next != Nil) {
			Prec = *P;
			*P = (*P)->next;
		}
		Prec->next = Nil;
	 } else {
		(*L).First = Nil;
	 }
	 DeAlokasi(*P);
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelAfter (List * L, address * Pdel, address Prec)
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
{
	if ((*L).First != Nil) {
		*Pdel = Prec->next;
		Prec->next = (*Pdel)->next;
		DeAlokasi(*Pdel);
	}
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** PROSES SEMUA ELEMEN LIST  ****/
void PrintInfo (List L)
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */
{
	 /* Kamus Lokal */
	address P;
	int i = 1;
	 /* Algoritma */
	P = L.First;
	if (P == Nil) {
		printf("List Kosong");
	} else {
		while (P != Nil){
			printf("%d. Nama : %s\n",i,P->nm);
			P = P->next;
			i++;
		}
	}
	printf("jumlah mahasiswa : %d\n\n",i - 1);
}


void DelAll (List * L)
/* Delete semua elemen list dan alamat elemen di dealokasi */
{
	 /* Kamus Lokal */
	address PDel;
	 /* Algoritma */
	 PDel = (*L).First;
	 while(PDel != Nil) {
		(*L).First = PDel->next;
		DeAlokasi(PDel);
		PDel = (*L).First;
	 }
	 (*L).First = Nil;
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void bandingkanNama (List * L)
{
	address P;
	char temp[100];

	P = (*L).First;
	if ((*L).First != Nil ) {
		while (P->next != Nil) {
			if(strcmp(P->nm,P->next->nm) > 0) {
				strcpy(temp,P->nm);
				strcpy(P->nm,P->next->nm);
				strcpy(P->next->nm,temp);
			}
			P = P->next;
		}
	}
}


void hapusDuplikat (List *S) {
	address P,temp,After;

	P = (*S).First;

	if (P != Nil) {
		while (P->next != Nil) {
			After = P;
			while (After->next != Nil) {
				if (strcmp(P->nm,After->next->nm) == 0) {
					temp = After->next;
					After->next = After->next->next;
					DeAlokasi(temp);
				} else {
					After = After->next;
				}
			}
			P = P->next;
		}
		
	}

}
