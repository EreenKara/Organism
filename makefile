Genel: Derle Bagla Calistir
Derle:
	g++ -I ./include/ -c ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -I ./include/ -c ./src/Doku.cpp -o ./lib/Doku.o
	g++ -I ./include/ -c ./src/main.cpp -o ./lib/main.o
Bagla:
	g++ ./lib/Hucre.o ./lib/Doku.o ./lib/main.o -o ./bin/program.exe
Calistir:
	./bin/program.exe
	