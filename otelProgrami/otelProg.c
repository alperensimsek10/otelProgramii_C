#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Musteri
{
	char Ad[20];
	char Soyad[20];
	int TC_Kimlik_No;
	char Gelis_Tarihi[20];
};

struct Oda
{
	int oda_no;
	struct Musteri Musteri_Bilgileri;
	int dolu;
	
}Oda_Bilgileri[10];

void ana_menu();
void yeni_kayit();
void oda_degisikligi();
void kayit_goster();
void kayit_sil();
void arama();
void odaya_gore_arama();
void soyada_gore_arama();
void gelis_tarihine_gore_arama();
void doluluk();
void doluluk_orani();
void bos_odalar();
void dolu_odalar();
int musteri_kontrol_et(int );

int main(int argc, char *argv[]) 
{
	//Odalarin Bilgileri Otomatik Dolduruluyor
	int i;
	for(i=0;i<10;i++)
	{
		Oda_Bilgileri[i].oda_no = i+1;
		Oda_Bilgileri[i].dolu = 0;
	}
	
	ana_menu();
	
	return 0;
}

void ana_menu()
{
	int secenek;
	
	printf("Otel Programina Hos Geldiniz!\n\n");
	do
	{
		printf("\nBir Islem Seciniz: \n");
		printf("1-Yeni Musteri Kayit\n");
		printf("2-Oda Degisikligi\n");
		printf("3-Kayitlari Goster\n");
		printf("4-Musteri Cikis\n");
		printf("5-Arama\n");
		printf("6-Doluluk\n");
		printf("7-Cikis\n");
		
		scanf("%d",&secenek);
		if(secenek == 1)
			yeni_kayit();
		else if (secenek == 2)
			oda_degisikligi();
		else if (secenek == 3)
			kayit_goster();
		else if (secenek == 4)
			kayit_sil();
		else if (secenek == 5)
			arama();
		else if (secenek == 6)
			doluluk();
		else if (secenek == 7)
			exit(0);
	
	}while(secenek != 7);
}

void yeni_kayit()
{
	int oda_no,i,TC_no,secenek;
	
	do
	{
		printf("\nMusterinin TC Kimlik Numarasini Giriniz: ");
		scanf("%d",&TC_no);
		
		int yanit = musteri_kontrol_et(TC_no);
		if(yanit == 1)
		{
			printf("Boyle Bir Musteri Su An Otelde Kalmaktadir!\n");
			printf("1-Yeni Bir Giris Yapmak Istiyorum \n");
			printf("2-Ana Menuye Don \n");
			scanf("%d",&secenek);
			
			if(secenek == 2)
				return;
		}
		else
			secenek = 0;
	
	}while(secenek == 1);
	
	
	do
	{
		printf("\nOda Numarasi Giriniz: ");
		scanf("%d",&oda_no);
		
		if(Oda_Bilgileri[oda_no-1].dolu == 1)
		{
			printf("Oda Dolu!\n");
			printf("1-Yeni Bir Giris Yapmak Istiyorum \n");
			printf("2-Ana Menuye Don \n");
			scanf("%d",&secenek);
				
			if(secenek == 2)
				return;
		}
		else
			secenek = 0;
			
	}while(secenek == 1);
	
	Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.TC_Kimlik_No = TC_no;
	Oda_Bilgileri[oda_no-1].dolu = 1;
	
	printf("\nMusterinin Adini Giriniz: ");
	scanf("%s",Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.Ad);
	printf("Musterinin Soyadini Giriniz: ");
	scanf("%s",Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.Soyad);
	printf("Gelis Tarihini Giriniz (Gun.Ay.Yil): ");
	scanf("%s",Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.Gelis_Tarihi);
	
	printf("Kayit Islemi Basarili!\n Ana Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}

void oda_degisikligi()
{
	int TC_no,oda_no,secenek,i,eski_oda_no;
	
	do
	{
		printf("\nOda Degisikligi Yapilacak Musterinin TC Kimlik Numarasini Giriniz: ");
		scanf("%d",&TC_no);
		
		int yanit = musteri_kontrol_et(TC_no);
		if(yanit == 0)
		{
			printf("Boyle Bir Musteri Su An Otelde Kalmamaktadir!\n");
			printf("1-Yeni Bir Giris Yapmak Istiyorum \n");
			printf("2-Ana Menuye Don \n");
			scanf("%d",&secenek);
			
			if(secenek == 2)
				return;
		}
		else
			secenek = 0;
	
	}while(secenek == 1);
	
	do
	{
		printf("\nGecmek Istedigi Oda Numarasini Giriniz: ");
		scanf("%d",&oda_no);
		
		if(Oda_Bilgileri[oda_no-1].dolu == 1)
		{
			printf("Oda Dolu!\n");
			printf("1-Yeni Bir Giris Yapmak Istiyorum \n");
			printf("2-Ana Menuye Don \n");
			scanf("%d",&secenek);
				
			if(secenek == 2)
				return;
		}
		else
			secenek = 0;
			
	}while(secenek == 1);
	
	
	for(i=0;i<10;i++)
	{
		if(Oda_Bilgileri[i].dolu == 1)
			if(Oda_Bilgileri[i].Musteri_Bilgileri.TC_Kimlik_No == TC_no)
			{
				eski_oda_no = i+1;
				break;
			}
	}
	
	Oda_Bilgileri[oda_no-1].dolu = 1;
	Oda_Bilgileri[eski_oda_no-1].dolu = 0;
	
	Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.TC_Kimlik_No = TC_no;
	Oda_Bilgileri[eski_oda_no-1].Musteri_Bilgileri.TC_Kimlik_No = 0;
	
	strcpy(Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.Ad, Oda_Bilgileri[eski_oda_no-1].Musteri_Bilgileri.Ad);
	strcpy(Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.Soyad, Oda_Bilgileri[eski_oda_no-1].Musteri_Bilgileri.Soyad);
	strcpy(Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.Gelis_Tarihi, Oda_Bilgileri[eski_oda_no-1].Musteri_Bilgileri.Gelis_Tarihi);
	strcpy(Oda_Bilgileri[eski_oda_no-1].Musteri_Bilgileri.Ad,"");
	strcpy(Oda_Bilgileri[eski_oda_no-1].Musteri_Bilgileri.Soyad,"");
	strcpy(Oda_Bilgileri[eski_oda_no-1].Musteri_Bilgileri.Gelis_Tarihi,"");
	
	printf("Oda Degistirme Islemi Basarili! Ana Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}

void kayit_goster()
{
	int i,bos_mu = 0;
	printf("\nDolu Olan Odalarin Bilgileri Gosterilmekte: \n\n");
	for(i=0;i<10;i++)
	{
		if(Oda_Bilgileri[i].dolu == 1)
		{
			printf("Oda No: %d\n",Oda_Bilgileri[i].oda_no);
			printf("Musteri TC No: %d\n",Oda_Bilgileri[i].Musteri_Bilgileri.TC_Kimlik_No);
			printf("Musteri Adi = %s\n",Oda_Bilgileri[i].Musteri_Bilgileri.Ad);
			printf("Musteri Soyadi = %s\n",Oda_Bilgileri[i].Musteri_Bilgileri.Soyad);
			printf("Gelis Tarihi = %s\n\n",Oda_Bilgileri[i].Musteri_Bilgileri.Gelis_Tarihi);
			bos_mu = 1;
		}
	}
	
	if(bos_mu == 0)
		printf("Tum Odalar Bos!\n");
	
	printf("Ana Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}

void kayit_sil()
{
	int TC_no,i,secenek;
	
	do
	{
		printf("\nCikacak Musterinin TC Kimlik Numarasini Giriniz: ");
		scanf("%d",&TC_no);
		
		int yanit = musteri_kontrol_et(TC_no);
		if(yanit == 0)
		{
			printf("Boyle Bir Musteri Su An Otelde Kalmamaktadir!\n");
			printf("1-Yeni Bir Giris Yapmak Istiyorum \n");
			printf("2-Ana Menuye Don \n");
			scanf("%d",&secenek);
			
			if(secenek == 2)
				return;
		}
		else
			secenek = 0;
	
	}while(secenek == 1);
	
	for(i=0;i<10;i++)
	{
		if(Oda_Bilgileri[i].dolu == 1 && Oda_Bilgileri[i].Musteri_Bilgileri.TC_Kimlik_No == TC_no)
		{
			Oda_Bilgileri[i].dolu = 0;
			Oda_Bilgileri[i].Musteri_Bilgileri.TC_Kimlik_No = 0;
			strcpy(Oda_Bilgileri[i].Musteri_Bilgileri.Ad,"");
			strcpy(Oda_Bilgileri[i].Musteri_Bilgileri.Soyad,"");
			strcpy(Oda_Bilgileri[i].Musteri_Bilgileri.Gelis_Tarihi,"");
		}
	}
	
	printf("Musteri Cikis Islemi Basarili!\n Ana Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}

void arama()
{
	int secenek;
	do
	{
		printf("\nHangi Bilgiye Gore Arama Yapacaksiniz? \n");
		printf("1-Oda Numarasina Gore\n");
		printf("2-Soyada Gore\n");
		printf("3-Gelis Tarihine Gore\n");
		printf("4-Ana Menuye Donmek Istiyorum\n");
		scanf("%d",&secenek);
		
		if(secenek == 1)
			odaya_gore_arama();
		else if(secenek == 2)
			soyada_gore_arama();
		else if(secenek == 3)
			gelis_tarihine_gore_arama();
		
	}while(secenek != 4);
}

void odaya_gore_arama()
{
	int oda_no;
	printf("\nOda Numarasini Giriniz: ");
	scanf("%d",&oda_no);
	
	if(Oda_Bilgileri[oda_no-1].dolu == 1)
	{
		printf("Oda No: %d\n",Oda_Bilgileri[oda_no-1].oda_no);
		printf("Musteri TC No: %d\n",Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.TC_Kimlik_No);
		printf("Musteri Adi = %s\n",Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.Ad);
		printf("Musteri Soyadi = %s\n",Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.Soyad);
		printf("Gelis Tarihi = %s\n",Oda_Bilgileri[oda_no-1].Musteri_Bilgileri.Gelis_Tarihi);
	}
	else
	{
		printf("Bu Odada Kalan Musteri Yok!\n");
	}
	
	printf("Bir Ust Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}

void soyada_gore_arama()
{
	int i,kayit_var_mi = 0;
	char soyad[20];
	printf("\nMusterinin Soyadini Giriniz: ");
	scanf("%s",soyad);
	
	for(i=0;i<10;i++)
	{
		if(Oda_Bilgileri[i].dolu == 1)
		{
			if(strcmp(Oda_Bilgileri[i].Musteri_Bilgileri.Soyad,soyad) == 0)
			{
				printf("Oda No: %d\n",Oda_Bilgileri[i].oda_no);
				printf("Musteri TC No: %d\n",Oda_Bilgileri[i].Musteri_Bilgileri.TC_Kimlik_No);
				printf("Musteri Adi = %s\n",Oda_Bilgileri[i].Musteri_Bilgileri.Ad);
				printf("Musteri Soyadi = %s\n",Oda_Bilgileri[i].Musteri_Bilgileri.Soyad);
				printf("Gelis Tarihi = %s\n\n",Oda_Bilgileri[i].Musteri_Bilgileri.Gelis_Tarihi);
				
				kayit_var_mi = 1;
			}
		}
	}
	
	if(kayit_var_mi == 0)
	{
		printf("Bu Soyad ile Kayitli Kimse Yoktur!\n");
	}
	
	printf("Bir Ust Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}

void gelis_tarihine_gore_arama()
{
	int i,kayit_var_mi = 0;
	char tarih[20];
	printf("\nMusterinin Gelis Tarihini Giriniz (Gun.Ay.Yil): ");
	scanf("%s",tarih);
	
	for(i=0;i<10;i++)
	{
		if(Oda_Bilgileri[i].dolu == 1)
		{
			if(strcmp(Oda_Bilgileri[i].Musteri_Bilgileri.Gelis_Tarihi,tarih) == 0)
			{
				printf("Oda No: %d\n",Oda_Bilgileri[i].oda_no);
				printf("Musteri TC No: %d\n",Oda_Bilgileri[i].Musteri_Bilgileri.TC_Kimlik_No);
				printf("Musteri Adi = %s\n",Oda_Bilgileri[i].Musteri_Bilgileri.Ad);
				printf("Musteri Soyadi = %s\n",Oda_Bilgileri[i].Musteri_Bilgileri.Soyad);
				printf("Gelis Tarihi = %s\n\n",Oda_Bilgileri[i].Musteri_Bilgileri.Gelis_Tarihi);
				
				kayit_var_mi = 1;
			}
		}
	}
	
	if(kayit_var_mi == 0)
	{
		printf("Bu Tarihte Gelen Hic Musteri Yoktur!\n");
	}
	
	printf("Bir Ust Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}

void doluluk()
{
	int secenek;
	
	do
	{
		printf("\nHangi Islemi Yapmak Istersiniz? \n");
		printf("1-Doluluk Orani: \n");
		printf("2-Bos Oda Numaralari \n");
		printf("3-Dolu Oda Numaralari \n");
		printf("4-Ana Menuye Donmek Istiyorum\n");
		scanf("%d",&secenek);
		
		if(secenek == 1)
			doluluk_orani();
		else if(secenek == 2)
			bos_odalar();
		else if(secenek == 3)
			dolu_odalar();
		
	}while(secenek != 4);
}
void doluluk_orani()
{
	int i,dolu_sayisi = 0;
	for(i=0;i<10;i++)
	{
		if(Oda_Bilgileri[i].dolu == 1)
			dolu_sayisi++;
	}
	
	printf("\nDoluluk Orani: %% %.2f\n",((float)dolu_sayisi/10)*100);
	
	printf("Bir Ust Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}
void bos_odalar()
{
	int i,bos_oda=0;
	printf("\nBos Odalar: \n");
	for(i=0;i<10;i++)
	{
		if(Oda_Bilgileri[i].dolu == 0)
		{
			printf("Oda No: %d\n",Oda_Bilgileri[i].oda_no);
			bos_oda = 1;
		}
	}
	
	if(bos_oda == 0)
		printf("Bos Oda Yok!\n");
	
	printf("Bir Ust Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}
void dolu_odalar()
{
	int i,dolu_oda=0;
	printf("\nDolu Odalar: \n");
	for(i=0;i<10;i++)
	{
		if(Oda_Bilgileri[i].dolu == 1)
		{
			printf("Oda No: %d\n",Oda_Bilgileri[i].oda_no);
			dolu_oda = 1;
		}
	}
	
	if(dolu_oda == 0)
		printf("Dolu Oda Yok!\n");
	
	printf("Bir Ust Menuye Donmek Icin Enter Tusuna Basiniz..\n");
	
	getche();
}

int musteri_kontrol_et(int TC_no)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(Oda_Bilgileri[i].dolu == 1)
			if(Oda_Bilgileri[i].Musteri_Bilgileri.TC_Kimlik_No == TC_no)
				return 1;
	}
	return 0;
}

