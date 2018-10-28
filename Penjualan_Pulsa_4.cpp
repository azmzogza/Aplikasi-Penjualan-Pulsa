//|*****************************************************************************|
//|							PROGRAM PENJUALAN PULSA                             |
//|				Dibuat oleh:													|
//|				Nama	: Septa Rismanto										|
//|				NIM		: 17112048												|
//|																				|
//|				Sebagai tugas UAS Mata Kuliah Algoritma dan Pemrograman			|
//|				Semester Ganjil Tahun 2017/2018									|
//|				Dibuat dengan Dev C++ 5.2.0.0									|
//|																				|
//|*****************************************************************************|
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;

int kembali,bayar,no_op,no_nom,hrg_pulsa[5],nominal_pulsa[5],i,a,pil,pendapatan,terjual;
char cs[30],lagi,semula,cetak,init;

struct beli
	{
		char nm_operator[10];
		int nom_beli,harga;
	}pulsa;

void tampil_awal()
{
	printf("                                                \n");
	printf("                                                \n");
	printf("|-----------------------------------------------|\n");
	printf("|                PENJUALAN PULSA                |\n");
	printf("|                    AZM CELL                   |\n");
	printf("|***********************************************|\n");
	printf(" Costumer Service : %s\n\n",cs);
}

void tampil_operator()
{
	system("cls");
	printf("|-----------------------------------------------|\n");
	printf("|              DAFTAR PRODUK PULSA              |\n");
	printf("|                    AZM CELL                   |\n");
	printf("|***********************************************|\n");
	printf("            1. Telkomsel\n");
	printf("            2. Indosat\n");
	printf("            3. XL\n");
	printf("            4. Smart\n");
	printf("            5. Three\n");
}

void tampil_operator2()
{
	printf("\n            DAFTAR PRODUK\n");
	printf("            1. Telkomsel\n");
	printf("            2. Indosat\n");
	printf("            3. XL\n");
	printf("            4. Smart\n");
	printf("            5. Three\n");
	printf("\n            Pilih nomor operator : ");scanf("%d",&no_op);
}

void nominal()
{
	//system("cls");
	a=1;
	printf("\n------------------------------------------------------");
	printf("\n                  DAFTAR NOMINAL PULSA                \n");
	printf("\n------------------------------------------------------\n");
	for (i=0;i<5;i++)
	{
		printf("            %d. %d		harga Rp %d,00\n",a,nominal_pulsa[i],hrg_pulsa[i]);
		a++;
	}
}

void inisialisasi()
{
	nominal_pulsa[0]=5000;
	nominal_pulsa[1]=10000;
	nominal_pulsa[2]=25000;
	nominal_pulsa[3]=50000;
	nominal_pulsa[4]=100000;
	hrg_pulsa[0]=6000;
	hrg_pulsa[1]=11000;
	hrg_pulsa[2]=26000;
	hrg_pulsa[3]=51000;
	hrg_pulsa[4]=101000;
	pendapatan=0;
	terjual=0;
}

void t_lagi()
{
	int atas_menu(),menu_awal();
	
	printf("\nApakah ada transaksi lagi ? (Y/T)\n");scanf("%s",&lagi);
	if (lagi=='Y'||lagi=='y')
	{atas_menu();
	menu_awal();}
	else if(lagi=='t'||lagi=='T')
	{system("cls");
	printf("|--------------------------------------------------------|\n");
	printf("| TERIMA KASIH TELAH MENGGUNAKAN PROGRAM PENJUALAN PULSA |\n");
	printf("|                         AZM CELL                       |\n");
	printf("|********************************************************|\n");
	printf(" Sampai ketemu lagi %s\n",cs);}
	else
	{printf("\nMohon tuliskan Y atau T saja.\nUntuk karakter lain dan atau tulisan tidak diperbolehkan");
	t_lagi();}
}

void nota()
{
	system("cls");
	printf("\n\n");
	printf("|---------------------------------------------------------|\n");
	printf("|                        AZM CELL	                  |\n");
	printf("|  Jalan Perjuangan nomor 1, Kampung Terbaik, Kota Juara  |\n");
	printf("|*********************************************************|\n");
	printf("|*********************************************************|\n");
	printf("|********************   NOTA PENJUALAN   *****************|\n");
	printf(" CS	: %s\n",cs);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|                                                         \n");
	printf("|           Nama Produk		: %s\n",pulsa.nm_operator);   
	printf("|           Besar pulsa		: %d\n",pulsa.nom_beli);
	printf("|           Harga		: Rp %d,00\n",pulsa.harga);
	printf("|           ----------------------------\n");
	printf("|           Pembayaran		: Rp %d,00\n",bayar);
	printf("|           Kembali		: Rp %d,00\n",kembali);
	printf("|           ----------------------------\n");
	printf("|___________________________________________________________\n");
	printf("        Terima kasih sudah berbelanja di AZM Cell.\n");
	printf("          Semoga Anda puas dengan pelayanan kami.\n");
	printf("____________________________________________________________\n");
	t_lagi();
}

void cek_bayar()
{
	int kembalian();
	if (bayar<pulsa.harga)
	{
		system("cls");
		printf("\nMaaf Anda membayar Rp %d,00.\nPembayaran anda kurang dari harga pulsa Rp %d,00.\n\n",bayar,pulsa.harga);
		kembali=0;
		printf("\nUntuk mengingatkan,\nAnda telah membeli pulsa %s dengan nominal pulsa %d seharga %d",pulsa.nm_operator,pulsa.nom_beli,pulsa.harga);
		printf("\n\nSilahkan masukkan nominal pembayaran: ");scanf("%d",&bayar);
		cek_bayar();}
	else
	{
	kembalian();
	pendapatan=pendapatan+pulsa.harga;
	terjual=terjual+1;
	printf("\n\nTransaksi berhasil.\nPendapatan sudah bertambah.\nApakah akan cetak nota ? (Y/T)\n");scanf("%s",&cetak);
	if (cetak=='Y'||cetak=='y')
		nota();
	else if(cetak=='T'||cetak=='t')
		t_lagi();
	else
		printf("Maaf hanya boleh memasukkan karakter y atau t")	;
	}
}

void kembalian()
{
	kembali=0;
	kembali = bayar-pulsa.harga;
}

void rekap_pilih()
{
	printf("\nAnda membeli pulsa %s dengan nominal pulsa %d seharga Rp %d,00",pulsa.nm_operator,pulsa.nom_beli,pulsa.harga);
	printf("\n\nSilahkan masukkan nominal pembayaran: Rp ");scanf("%d",&bayar);
	kembalian();
	cek_bayar();
}

void pilihan_nom()
{
	if (no_nom==1)
	{pulsa.nom_beli=5000;
	pulsa.harga=hrg_pulsa[0];
	rekap_pilih();}
	else if(no_nom==2)
	{pulsa.nom_beli=10000;
	pulsa.harga=hrg_pulsa[1];
	rekap_pilih();}
	else if(no_nom==3)
	{pulsa.nom_beli=25000;
	pulsa.harga=hrg_pulsa[2];
	rekap_pilih();}
	else if(no_nom==4)
	{pulsa.nom_beli=50000;
	pulsa.harga=hrg_pulsa[3];
	rekap_pilih();}
	else if(no_nom==5)
	{pulsa.nom_beli=100000;			
	pulsa.harga=hrg_pulsa[4];
	rekap_pilih();}
	else
	{printf("Maaf silahkan tuliskan nomor pulsanya(1 angka),\nbukan nominal pulsanya atau lainnya\n");
	nominal();
	printf("\nMasukkan nomor nominal untuk operator %s: ",pulsa.nm_operator);scanf("%d",&no_nom);
	pilihan_nom();}
}

void hasil_pilih()
{
	switch (no_op)
	{
	case 1:
		{
			system("cls");
			nominal();
			strcpy(pulsa.nm_operator,"Telkomsel");
			printf("\nMasukkan nomor nominal untuk operator %s: ",pulsa.nm_operator);scanf("%d",&no_nom);
			pilihan_nom();	
			break;
		}
	case 2:
		{
			system("cls");
			nominal();
			strcpy(pulsa.nm_operator,"Indosat");
			printf("\nMasukkan nomor nominal untuk operator %s: ",pulsa.nm_operator);scanf("%d",&no_nom);
			pilihan_nom();
			break;
		}
	case 3:
		{
			system("cls");
			nominal();
			strcpy(pulsa.nm_operator,"XL");
			printf("\nMasukkan nomor nominal untuk operator %s: ",pulsa.nm_operator);scanf("%d",&no_nom);
			pilihan_nom();
			break;
		}
	case 4:
		{
			system("cls");
			nominal();
			strcpy(pulsa.nm_operator,"Smart");
			printf("\nMasukkan nomor nominal untuk operator %s: ",pulsa.nm_operator);scanf("%d",&no_nom);
			pilihan_nom();
			break;
		}
	case 5:
		{
			system("cls");
			nominal();
			strcpy(pulsa.nm_operator,"Three");
			printf("\nMasukkan nomor nominal untuk operator %s: ",pulsa.nm_operator);scanf("%d",&no_nom);
			pilihan_nom();
			break;
		}
	default : 
		{
			system("cls");
			printf("Nomor yang anda masukkan salah\n");
			tampil_operator2();
			hasil_pilih();
		break;
		}
	}
}

void penjualan()
{
	system("cls");
	tampil_awal();
	tampil_operator2();
	hasil_pilih();
}

void update_data()
{
	system("cls");
	printf("|-----------------------------------------------|\n");
	printf("|      PROSES UPDATING HARGA PRODUK PULSA       |\n");
	printf("|                    AZM CELL                   |\n");
	printf("|***********************************************|\n");
	printf("                                                \n");
	int menu_awal();
	i=0;
	a=1;
	while (i<5)
	{
		printf("%d. Harga pulsa %d tadinya Rp %d,00, dirubah menjadi : ",a,nominal_pulsa[i],hrg_pulsa[i]);scanf("%d",&hrg_pulsa[i]);
		printf("   Harga pulsa %d sudah menjadi Rp %d,00\n\n",nominal_pulsa[i],hrg_pulsa[i]);
		i++;
		a++;
	}
	system("cls");
	printf("|---------------------------------------------------|\n");
	printf("|                     TERIMA KASIH                  |\n");
	printf("|       HARGA PRODUK SUDAH BERHASIL DIUPDATE!       |\n");
	printf("|---------------------------------------------------|\n");
	nominal();
	menu_awal();
}

void atas_menu()
{
	system("cls");
	printf("                                                \n");
	printf("                                                \n");
	printf("|-----------------------------------------------|\n");
	printf("|   SELAMAT DATANG DI PROGRAM PENJUALAN PULSA   |\n");
	printf("|                    AZM CELL                   |\n");
	printf("|***********************************************|\n");
	printf(" Costumer Service/Pemakai program : %s\n",cs);
}

void t_init()
{
	int menu_awal();
	printf("\nYakin akan mengembalikan data seperti semula?\n(semua data akan menjadi 0, termasuk pendapatan dan item terjual)\n(Y/T) --> ");scanf("%s",&init);
	if (init=='Y'||init=='y')
		{inisialisasi();
		system("cls");
		printf("Semua data sudah dikembalikan ke data semula...\n\n");
		system("pause");
		atas_menu();
		menu_awal();}
	else if(init=='T'||init=='t')
		{system("cls");
		printf("\nPengembalian data dibatalkan. Silahkan dilanjutkan transaksi lainnya\n\n");
		system("pause");
		atas_menu();
		menu_awal();}
	else
		{printf("\nMaaf hanya boleh memasukkan karakter y atau t\n");
		t_init();}
}

void menu_awal()
{
	printf("                                                \n");
	printf("|***********************************************|\n");
	printf("            1. Lihat produk\n"); // --> ke tampil_operator()
	printf("            2. Lihat harga produk\n"); // --> ke nominal()
	printf("            3. Penjualan\n"); //--> ke penjualan()
	printf("            4. Update harga produk\n");//--> ke update_data()
	printf("            5. Kembalikan data seperti semula\n");//--> ke inisialisasi()
	printf("            6. Lihat pendapatan\n");//--> tampilkan pendapatan
	printf("            0. Keluar\n");//--> keluar
	printf("\n      Anda akan(masukkan nomor menu) : ");scanf("%d",&pil);
	switch (pil)
	{
	case 1:
		{
			tampil_operator();
			menu_awal();
		}break;
	case 2:
		{
			system("cls");
			nominal();
			menu_awal();
		}break;
	case 3: penjualan();break;
	case 4: update_data();break;
	case 5: t_init();break;
	case 6:
		{
			system("cls");
		printf("                                                \n");
		printf("                                                \n");
		printf("|-----------------------------------------------|\n");
		printf("|   		HASIL PENJUALAN PULSA   	|\n");
		printf("|                    AZM CELL                   |\n");
		printf("|***********************************************|\n");
			printf("\n  Pendapatan sampai saat ini: Rp %d,00",pendapatan);
			printf("\n  Jumlah produk terjual sampai saat ini: %d item\n\n",terjual);
			system("pause");
			atas_menu();
			menu_awal();
		}break;
	case 0:
		{
			system("cls");
			printf("|--------------------------------------------------------|\n");
			printf("| TERIMA KASIH TELAH MENGGUNAKAN PROGRAM PENJUALAN PULSA |\n");
			printf("|                         AZM CELL                       |\n");
			printf("|********************************************************|\n");
			printf(" Sampai ketemu lagi %s\n",cs);
			system("pause");
		}break;
	default:
		{
			system("cls");
			printf("            Masukkan angka dari 1-5 dan 0\n");
			menu_awal();
		}break;
	}
}

main()
{
	inisialisasi();
	printf("Nama CS	: ");gets(cs);
	printf("\n\n");
	atas_menu();
	menu_awal();
}
