hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.cpp
	g++ -I ./include/ -o ./lib/Yigin.o -c ./src/Yigin.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/ADugum.o -c ./src/ADugum.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/DosyaOku.o ./lib/Agac.o ./lib/ADugum.o ./lib/Yigin.o ./lib/Dugum.o ./src/Test.cpp

calistir:
	./bin/Test