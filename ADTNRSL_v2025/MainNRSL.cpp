/* File        : mainNRSL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha*/
/* Tanggal     : 25-10-2001 */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar */
/* Diupdate oleh : WW & AM, 8-3-2025, penyesuaian area body & main untuk latihan Diploma 3 */

#include "spnrsll.h"
#include <stdio.h>

int main()
{
	/* Kamus Lokal */
		List MyList;
		infotype isi;
		address P, Prec;

	/* Program */
	CreateList (&MyList);	//List sudah terbentuk, digunakan untuk memanipulasi elemen
	
	int choice;
	Prec = NULL;
	
	P = NULL;
	while(true){
		//aksi mahasiswa untuk implementasi studi kasus
		printf("Pilih lah pilihan opsi list ini\n");
		printf("1. Tampilkan semua list\n");
		printf("2. Insert First\n");
		printf("3. Insert After\n");
		printf("4. Insert Last\n");
		printf("5. Delete First\n");
		printf("6. Delete After\n");
		printf("7. Delete Last\n");
		printf("8 Menghapus semuanya\n");
		printf("Pilih Nomor Berapa :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			PrintInfo(MyList);
			break;
		case 2:
			printf("Masukan Nilai yang di Awal\n");
			scanf("%d", &isi);
			InsVFirst(&MyList, isi);
			InsertFirst(&MyList, P);
			break;
		case 3: 
		int node;
		printf("Masukkan nilai yang ingin disisipkan di tengah: ");
		scanf("%d", &isi);
		
		printf("Masukkan angka yang ingin disisipkan di depannya: ");
		PrintInfo(MyList);
		scanf("%d", &node);
		
		Prec = First(MyList);
		while (Prec != NULL && Info(Prec) != node) {
			Prec = Next(Prec);
		}
		
		if (Prec != NULL) {
			P = Alokasi(isi);
			if (P != NULL) {  
				InsertAfter(&MyList, P, Prec);
				printf("List setelah penyisipan:\n");
				PrintInfo(MyList);
			} else {
				printf("Gagal mengalokasi memori!\n");
			}
		} else {
			printf("Elemen dengan nilai %d tidak ditemukan dalam list!\n", node);
		}
		
		break;
		case 4:
			printf("Masukan Nilai yang di Akhir \n");
			scanf("%d", &isi);
			InsVLast(&MyList, isi);
			InsertLast(&MyList, P);
		break;
		case 5: 
			DelFirst(&MyList, &P);
			break;
		case 6:
		printf("Masukkan nilai yang ingin dihapus di depannya:\n");
		PrintInfo(MyList);
		scanf("%d", &isi);
		
		
		Prec = First(MyList);
		while (Prec != NULL && Info(Prec) != isi) {
			Prec = Next(Prec);
		}
		
		if (Prec != NULL && Next(Prec) != NULL) {
			DelAfter(&MyList, &P, Prec);
			printf("List setelah penghapusan:\n");
			PrintInfo(MyList);
		} else {
			printf("Penghapusan gagal: Elemen %d tidak ditemukan atau tidak ada elemen setelahnya!\n", isi);
		}
		
			break;
		case 7:
			DelLast(&MyList, &P);
			break;	
		default:
			break;
		}
		
		
	}
	/* Finishing */
	
	//Pastikan List di Dealokasi setelah manipulasi elemen selesai
	
	return 0;
}

