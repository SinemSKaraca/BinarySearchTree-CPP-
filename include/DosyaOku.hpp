#ifndef DOSYAOKU_HPP
#define DOSYAOKU_HPP

#include "Yigin.hpp"
#include "Agac.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class DosyaOku {
private:
    Yigin** yiginlar;
	Agac** agaclar;
	int satirMaxEleman();
public:
	DosyaOku();
	void OkuVeEkle();
	void AgacaEkle(Yigin**, int);
	void AgacSec(Agac**, int);
	~DosyaOku();
};



#endif