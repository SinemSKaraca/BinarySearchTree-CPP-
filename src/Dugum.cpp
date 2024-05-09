/**
* @file         Dugum
* @description  Bagli Liste ile olusturulan yigin veri yapisinin dugumlerini olusturur.
* @course       1(A)
* @assignment   2.Ödev
* @date         04.08.2023
* @author       Sinem Saziye Karaca - saziye.karaca@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

Dugum::Dugum(int _veri) {
	this->veri = _veri;
	this->sonraki = NULL;
}