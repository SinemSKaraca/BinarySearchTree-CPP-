#ifndef YIGIN_HPP
#define YIGIN_HPP

#include "Dugum.hpp"
#include <iostream>
using namespace std;

class Yigin {
private:
	Dugum* tepe;
public:
	Yigin();
	void ekle(int);
	int getir();
	void cikar();
	void yazdir();
	int elemanSayisi();
	~Yigin();
};

#endif