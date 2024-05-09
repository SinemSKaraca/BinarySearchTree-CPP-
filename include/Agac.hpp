#ifndef AGAC_HPP
#define AGAC_HPP

#include "ADugum.hpp"
#include <iostream>
using namespace std;

class Agac {
private:
	ADugum* kok;
	bool varMi(int, ADugum*);
	void ekle(int, ADugum*);
	void postorder(ADugum*);
	int yukseklik(ADugum*);
	int dugumlerToplami(ADugum*);
	bool DugumSil(ADugum*&);
public:
	Agac();
	bool varMi(int);
	void ekle(int);
	void postorder();
	int yukseklik();
	int dugumlerToplami();
	void sil();
	~Agac();
};

#endif