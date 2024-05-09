/**
* @file         DosyaOku
* @description  Okudugu dosyanın bir satirindaki elemanlari bir yigina eklemeyle çalışmaya başlayan program..
*               ..okuduğu sayi cift ve yiginin tepesindeki sayidan buyukse yeni bir yigin oluturarak bu sayiyi..
*               ..o yigina ekler. Her satir tamamlandiginda olusturulmus olan yiginlardaki verileri birer ikili..
*               ..arama agacına ekler. Ardından bu agaclardan birini, senaryoya uygun olarak, secer.
*               Secilen agacın verilerinin ASCII karakter karsiligini postorder formda ekrana yazdirir.
*               Yazdirma isleminde her satir arasinda 10 milisaniye bekler.  
* @course       1(A)
* @assignment   2.Ödev
* @date         03.08.2023
* @author       Sinem Saziye Karaca - saziye.karaca@ogr.sakarya.edu.tr
*/


#include "DosyaOku.hpp"
#include <windows.h>

DosyaOku::DosyaOku() {
	yiginlar = new Yigin*[satirMaxEleman()];
	OkuVeEkle();
}

int DosyaOku::satirMaxEleman() {
	string satir;
	string str;
	ifstream dosya("Sayilar.txt");
	
	int maxEleman = 0;
	int elemanSayisi = 0;
	while(getline(dosya, satir)) {
		istringstream ss(satir);
		while(getline(ss, str, ' ')) {
			elemanSayisi++;
		}
		if(elemanSayisi > maxEleman)
			maxEleman = elemanSayisi;
	}
	return maxEleman;
}

void DosyaOku::OkuVeEkle() {
	string satir;
	string str;
	ifstream dosya("Sayilar.txt");
	
	int index = 0;
	while(getline(dosya, satir)) {
		istringstream ss(satir);
		yiginlar[index] = new Yigin();
		while(getline(ss, str, ' ')) {
			if(stoi(str) % 2 == 0 && stoi(str) > yiginlar[index]->getir()) {
				index++;
				yiginlar[index] = new Yigin();
				yiginlar[index]->ekle(stoi(str));
				//cout << "karsilastirma" << endl;
			}
			else {
				yiginlar[index]->ekle(stoi(str));
				//cout << "direkt ekleme" << endl;
			}
		}
		AgacaEkle(yiginlar, index);
		AgacSec(agaclar, index);
		// Gorevi tamamlanan satirin agaclari silindi.
		for(int i = 0; i < index + 1; i++)
			delete agaclar[i];
		delete[] agaclar;
		index = 0;
		// 10 milisaniye bekler
		Sleep(10);
	}
	dosya.close();
}

void DosyaOku::AgacaEkle(Yigin** _yiginlar, int _index) {
	agaclar = new Agac*[_index + 1];
	for(int i = 0; i < _index + 1; i++) {
		agaclar[i] = new Agac();
		int elemanSayisi = _yiginlar[i]->elemanSayisi();
		for(int j = 0; j < elemanSayisi; j++) {
			agaclar[i]->ekle(_yiginlar[i]->getir());
			_yiginlar[i]->cikar();
		} // Agac olusturuldu
		// Agaci olusan yiginin bellekteki alani serbest birakildi.
		delete yiginlar[i];
	} // Bir satirin agaclari olustu.
}

void DosyaOku::AgacSec(Agac** _agaclar, int _index) {
	int maxYukseklik = _agaclar[0]->yukseklik();
	int hangiAgac = 0;
	for(int i = 1; i < _index + 1; i++) {
		if(maxYukseklik < _agaclar[i]->yukseklik()) {
			maxYukseklik = agaclar[i]->yukseklik();
			hangiAgac = i;
		}
		else if(maxYukseklik == _agaclar[i]->yukseklik()) {
			if(agaclar[hangiAgac]->dugumlerToplami() < agaclar[i]->dugumlerToplami())
				hangiAgac = i;
			else continue;
		}
		else continue;
	}
	agaclar[hangiAgac]->postorder();
	cout << endl;
}

DosyaOku::~DosyaOku() {
	//cout << "DosyaOku Yikici Calisti." << endl;
	delete[] yiginlar;
}

