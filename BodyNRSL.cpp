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
	 return (First(L) == Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L)
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
{
	 First(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (Mahasiswa X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (ElmtList));
	 if (P != Nil)		/* Alokasi berhasil */
	 {
		strcpy(Nama(P),X.Nama);
		Nilai(P) = X.Nilai; 
		Next(P) = Nil;
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

/**** Pencarian sebuah elemen List ****/
address Search (List L, Mahasiswa X)
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
/* Menggunakan variabel bertype boolean */
{
	 /* Kamus Lokal */
	 address P;
	 boolean found =  false;
	 /* algoritma */
	 P = First(L);
	 while ((P != Nil) && (!found))
	 {
		if (Nama(P) == X.Nama)
		{	found = true; 	}
		else
		{	P = Next(P);	}
	 }	/* P = Nil atau Ketemu */
	
	 return (P);
}

boolean FSearch (List L, address P)
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
{
	 /* Kamus Lokal */
	 boolean found=false;
	 address PSearch;
	 /* Algortima */
	 PSearch = First(L);
	 while ((PSearch != Nil) && (!found))
	 {
		if (PSearch == P)
		{	found = true; 	}
		else
		{	PSearch = Next(PSearch);	}
	 }	/* PSearch = Nil atau Ketemu */
	 
	 return (found);
}

address SearchPrec (List L, Mahasiswa X)
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
	P = First(L);
	while ((P != Nil) && (!found))
	{
		 if (Nama(P) == X.Nama)
		 {	found = true;	}
		 else
		 {
			Prec = P;
			P = Next(P);
		 }
	}    /* P = Nil atau Ketemu */
	if (found)
	{	return (Prec);		}
	else
	{	return (Nil);		}
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, const char *Nama, int Nilai)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	 /* Kamus Lokal */
	address P;
	Mahasiswa X;
	 /* Algoritma */
	strcpy(X.Nama,Nama);
	X.Nilai = Nilai;

	P = Alokasi(X);
	
	if (P != Nil) {
		Next(P) = First(*L);
		First(*L) = P; 
	}
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsVLast (List * L, const char *Nama, int Nilai)
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */
{
	 /* Kamus Lokal */
	address P;
	address temp;
	Mahasiswa X;

	strcpy(X.Nama,Nama);
	X.Nilai = Nilai;

	 /* Algoritma */
	 P = Alokasi(X);
	 if (P != Nil) {
		if (First(*L) == Nil) {
			First(*L) = P;
		 } else {
			temp = First(*L);
			while(Next(temp) != NULL) {
				temp = Next(temp);
			}
			Next(temp) = P;
		 }
	 }
	 
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, Mahasiswa * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
{
	 /* Kamus Lokal */
	address P;
	 /* Algoritma */
	P = First(*L);
	strcpy(X->Nama,Nama(P));
	First(*L) = Next(P);
	DeAlokasi(P);
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelVLast (List * L, Mahasiswa * X)
/* IS : L TIDAK Kosong */
/* FS : Elemen terakhir list dihapus : nilai info disimpan pada X */
/* 	dan alamat elemen terakhir di dealokasi */
{
	 /* Kamus Lokal */
	address PDel,prev = Nil;
	 /* Algoritma */
	 PDel = First(*L);
	 if (Next(PDel) == Nil) {
		strcpy(X->Nama,Nama(PDel));
		First(*L) = Nil;
		DeAlokasi(PDel);
		return;
	 } 

	 while(Next(PDel) != Nil) {
		prev = PDel;
		PDel = Next(PDel);
	 }
	 strcpy(X->Nama,Nama(prev));
	 Next(prev) = Nil;
	 DeAlokasi(PDel);
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsertAfter (List * L, address P, address Prec)
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	if (Prec != NULL) {
		Next(P) = Next(Prec);
		Next(Prec) = P; 
	}
	//Buatkan algoritma sesuai spesifikasi modul ini
}

void InsertLast (List * L, address P)
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */
{
	 /* Kamus Lokal */
	address Last;
	 /* Algoritma */
	 if (First(*L) == Nil) {
		First(*L) = P;
	 } else {
		Last = First(*L);
		while (Next(Last) != Nil) {
			Last = Next(Last);
		}
		Next(Last) = P;
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
	if (First(*L) != Nil) {
		*P = First(*L);
		First(*L) = Next(*P);
		DeAlokasi(*P);
	}
	//Buatkan algoritma sesuai spesifikasi modul ini
}


void DelP (List * L, Mahasiswa X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	address P, Prec;
	boolean found=false;
	 
	 /* Algoritma */
	 Prec = SearchPrec(*L,X);
	 P = Search(*L,X);

	 if (Prec == Nil) {
		P = First(*L);
		Next(First(*L)) = Next(P);
		DeAlokasi(P);
	 } else {
		Next(Prec) = Next(P);
		DeAlokasi(P);
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
	 *P = First(*L);
	 if (Next(First(*L)) != Nil) {

		while (Next(*P) != Nil) {
			Prec = *P;
			*P = Next(*P);
		}
		Next(Prec) = Nil;
	 } else {
		First(*L) = Nil;
	 }
	 DeAlokasi(*P);
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void DelAfter (List * L, address * Pdel, address Prec)
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
{
	if (First(*L) != Nil) {
		*Pdel = Next(Prec);
		Next(Prec) = Next(*Pdel);
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
	P = First(L);
	if (P == Nil) {
		printf("List Kosong");
	} else {
		while (P != Nil){
			printf("%d. Nama : %s\n",i,Nama(P));
			printf("   Nilai : %d\n\n",Nilai(P));
			P = Next(P);
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
	 PDel = First(*L);
	 while(PDel != Nil) {
		First(*L) = Next(PDel);
		DeAlokasi(PDel);
		PDel = First(*L);
	 }
	 First(*L) = Nil;
	 //Buatkan algoritma sesuai spesifikasi modul ini
}

void bandingkanNama (List * L)
{
	address P;
	char temp[100];

	P = First(*L);
	if (First(*L) != Nil ) {
		while (P->next != Nil) {
			if(strcmp(Nama(P),Next(P)->info.Nama) > 0) {
				strcpy(temp,Nama(P));
				strcpy(Nama(P),Next(P)->info.Nama);
				strcpy(Next(P)->info.Nama,temp);
			}
			P = Next(P);
		}
	}
}

void bandingkanNilai (List *L)
{
	address P,After;
	int temp;

	P = First(*L);
	if (First(*L ) != Nil) {
		while (P != Nil) {
			After = P;
			while (Next(After) != Nil) {
				if (Nilai(P) < Next(After)->info.Nilai) {
					temp = Nilai(P);
					Nilai(P) = Next(After)->info.Nilai;
					Next(After)->info.Nilai = temp;
				} else {
					After = Next(After);
				}
			}
			P = P->next;
		}
	}
}

void copyNilai (List *L, List *S) {
	address P,temp;

	P = First(*L);
	temp = Nil;

	while (P != Nil) {
		if (Nilai(P) > 70) {
			address New = Alokasi(P->info);
			if (New != Nil) {
				New->next = Nil;

				if (First(*S) == Nil) {
					First(*S) = New;
				} else {
					temp->next = New;
				}
			}
			temp = New;
		}
		P = P->next;
	}
}

void hapusDuplikat (List *S) {
	address P,temp,After;

	P = First(*S);

	if (P != Nil) {
		while (P->next != Nil) {
			After = P;
			while (Next(After) != Nil) {
				if (strcmp(Nama(P),Nama(Next(After))) == 0) {
					temp = Next(After);
					Next(After) = Next(After)->next;
					DeAlokasi(temp);
				} else {
					After = Next(After);
				}
			}
			P = P->next;
		}
		
	}

}
