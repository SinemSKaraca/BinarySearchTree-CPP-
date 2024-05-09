/**
* @file         Test
* @description  DosyaOku sinifinin nesnesini olusturur. Program tamamlanmadan hemen once..
*               ..nesneyi serbest birakir.
* @course       1(A)
* @assignment   2.Ödev
* @date         03.08.2023
* @author       Sinem Saziye Karaca - saziye.karaca@ogr.sakarya.edu.tr
*/

#include "DosyaOku.hpp"
#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main() {
	// Yorum satırında bulunan kodlar programin calisma süresini saniye cinsinden verir.
	//auto start = high_resolution_clock::now();
	DosyaOku* d = new DosyaOku; 
	
	//auto stop = high_resolution_clock::now();
	//auto duration = duration_cast<seconds>(stop - start);
	//cout << duration.count() << endl;
	
	delete d;
	return 0;
}