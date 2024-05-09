#ifndef ADUGUM_HPP
#define ADUGUM_HPP

#include <iostream>
using namespace std;

class ADugum {
private:
public:
	int veri;
	ADugum* sag;
	ADugum* sol;
	ADugum(int);
	~ADugum();
};

#endif