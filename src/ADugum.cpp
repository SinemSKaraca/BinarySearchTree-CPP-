/**
* @file         ADugum
* @description  Bagli Liste ile olusturulan ikili arama agaci veri yapisinin dugumlerini olusturur.
* @course       1(A)
* @assignment   2.Ödev
* @date         04.08.2023
* @author       Sinem Saziye Karaca - saziye.karaca@ogr.sakarya.edu.tr
*/

#include "ADugum.hpp"

ADugum::ADugum(int _veri) {
	this->veri = _veri;
	this->sag = NULL;
	this->sol = NULL;
}

ADugum::~ADugum() {
	
}