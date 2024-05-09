/**
* @file         Agac
* @description  İkili Arama agaci veri yapisi olusturmaya yarayan bu program, olusturulan agaca yeni bir veri eklemeden once..
*               ..o verinin agacta olup olmadşgini kontrol ediyor. Eger yoksa yeni veriyi agacın uygun konumuna ekliyor..
*               ..eger varsa yeni veriyi agaca eklemeden eklenecek bir sonraki veriye geciyor. Ayrica olusturulan..
*               ..agacların yuksekligini ve tüm dügümlerindeki verilerin toplamini hesaplayan fonksiyonlar bulunmakta.
*               Olusturulan agaclarin verilerinin ASCII karakter karsiliklarini, ihtiyac oldugunda, postorder formatta ekrana..
*               ..yazdirabilir ve agacin dugumlerini silebilir. Yikici fonksiyonu ile agacin bellekte kapladigi alani serbest birakilir.
* @course       1(A)
* @assignment   2.Ödev
* @date         04.08.2023
* @author       Sinem Saziye Karaca - saziye.karaca@ogr.sakarya.edu.tr
*/

#include "Agac.hpp"

Agac::Agac() {
	this->kok = NULL; 
}

bool Agac::varMi(int aranan, ADugum* aktifDugum) {
	if(aktifDugum == NULL) return false;
	else if(aranan < aktifDugum->veri) {
		if(aktifDugum->sol != NULL)
			return varMi(aranan, aktifDugum->sol);
		return false;
	}
	else if(aranan > aktifDugum->veri) {
		if(aktifDugum->sag != NULL) 
			return varMi(aranan, aktifDugum->sag);
	}
	// aranan eleman agacta varsa
	else
		return true;
}

void Agac::ekle(int _veri, ADugum* aktifDugum) {
	if(_veri > aktifDugum->veri) {
		if(aktifDugum->sag != NULL)
			ekle(_veri, aktifDugum->sag);
		else
			aktifDugum->sag = new ADugum(_veri);
	}
	else if(_veri < aktifDugum->veri) {
		if(aktifDugum->sol != NULL)
			ekle(_veri, aktifDugum->sol);
		else
			aktifDugum->sol = new ADugum(_veri);
	}
	// Eklenecek dugum agacta zaten varsa ekleme;
	else
		return;
}

void Agac::postorder(ADugum* aktifDugum) {
	if(aktifDugum != NULL) {
		postorder(aktifDugum->sol);
		postorder(aktifDugum->sag);
		cout << static_cast<char>(aktifDugum->veri) << " ";
	}	
}

int Agac::yukseklik(ADugum* aktifDugum) {
	if(aktifDugum != NULL) 
		return 1 + max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
	return -1;
}

int Agac::dugumlerToplami(ADugum* aktifDugum) {
	if(aktifDugum != NULL)
		return (aktifDugum->veri + dugumlerToplami(aktifDugum->sol) + dugumlerToplami(aktifDugum->sag));
	return 0;
}

bool Agac::DugumSil(ADugum*& aktifDugum) {
	ADugum* silinecekDugum = aktifDugum;
	if(aktifDugum->sol == NULL) 
		aktifDugum = aktifDugum->sag;
	else if(aktifDugum->sag == NULL) 
		aktifDugum = aktifDugum->sol;
	else {
		silinecekDugum = aktifDugum->sol;
		ADugum* ebeveyn = aktifDugum;
		while(silinecekDugum->sag != NULL) {
			ebeveyn = silinecekDugum;
			silinecekDugum = silinecekDugum->sag;
		}
		aktifDugum->veri = silinecekDugum->veri;
		if(ebeveyn == aktifDugum)
			aktifDugum->sol = silinecekDugum->sol;
		else
			ebeveyn->sag = silinecekDugum->sol;
	}
	delete silinecekDugum;
	return true;
}

// ---------------------------------

bool Agac::varMi(int _veri) {
	return varMi(_veri, kok);
}

void Agac::ekle(int _veri) {
	if(kok == NULL)
		kok = new ADugum(_veri);
	else if(varMi(_veri))
		return;
	else
		ekle(_veri, kok);
}

void Agac::postorder() {
	postorder(kok);
}

int Agac::yukseklik() {
	return yukseklik(kok);
}

int Agac::dugumlerToplami() {
	return dugumlerToplami(kok);
}

void Agac::sil() {
	while(kok != NULL) 
		DugumSil(kok);
}

Agac::~Agac() {
	//cout << "Agac Yikici Calisti." << endl;
	sil();
}
