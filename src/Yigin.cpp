/**
* @file         Yigin
* @description  Bagli Liste veri yapisi kullanilarak yigin olusturan bu program Sayilar.txt dosyasindan aldigi..
*               ..verileri yiginin tepesine ekleme, yigin tepesinden eleman cikarma ve tepede bulunan..
*               ..elemani getirme islemleri yapar. Ayrica bir yiginin eleman sayisini hesaplayabilir ve..
*               ..gerektiginde yikici fonksiyonu ile yiginin bellekte kapladigi alani serbest birakir.
* @course       1(A)
* @assignment   2.Ödev
* @date         04.08.2023
* @author       Sinem Saziye Karaca - saziye.karaca@ogr.sakarya.edu.tr
*/

#include "Yigin.hpp"
#include "Dugum.hpp"

Yigin::Yigin() {
	tepe = NULL;
}

// Liste basina ekleme yapiliyor.
void Yigin::ekle(int _veri) {
	Dugum* yeniDugum = new Dugum(_veri);
	// Liste bossa dugumu direkt ekler.
	if(tepe == NULL) {
		tepe = yeniDugum;
	}
	else {
		yeniDugum->sonraki = tepe;
		tepe = yeniDugum;
	}
}

int Yigin::getir() {
	if(tepe != NULL) {
		return tepe->veri;
	}
	return -1;
}

// Yiginin tepe verisini çikarir.
void Yigin::cikar() {
	if(tepe != NULL) {
		Dugum* silinecek;
		silinecek = tepe;
		tepe = tepe->sonraki;
		delete silinecek;
	}
	else 
		cout << "Yigindan Cikarilacak Eleman Bulunmamaktadir!" << endl;
}

void Yigin::yazdir() {
	Dugum* gecici = tepe;
	//if(tepe == NULL) cout << "yigin bos" << endl;
	while(gecici != NULL) {
		cout << gecici->veri << " ";
		gecici = gecici->sonraki;
	}
}

int Yigin::elemanSayisi() {
	int elemanSayisi = 0;
	Dugum* gecici = tepe;
	while(gecici != NULL) {
		elemanSayisi++;
		gecici = gecici->sonraki;
	}
	return elemanSayisi;
}

Yigin::~Yigin() { 
	//cout << "Yigin Yikici Calisti." << endl;
	while(tepe != NULL)
		cikar();
}

