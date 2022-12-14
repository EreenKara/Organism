Genel: Derle Bagla Calistir
Derle:
	g++ -I ./include/ -c ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -I ./include/ -c ./src/Doku.cpp -o ./lib/Doku.o
	g++ -I ./include/ -c ./src/BSTNode.cpp -o ./lib/BSTNode.o
	g++ -I ./include/ -c ./src/BST.cpp -o ./lib/BST.o
	g++ -I ./include/ -c ./src/Organ.cpp -o ./lib/Organ.o
	g++ -I ./include/ -c ./src/Kontrol.cpp -o ./lib/Kontrol.o
	g++ -I ./include/ -c ./src/main.cpp -o ./lib/main.o
	
Bagla:
	g++ ./lib/Hucre.o ./lib/Doku.o ./lib/Kontrol.o ./lib/BST.o ./lib/BSTNode.o ./lib/Organ.o ./lib/main.o -o ./bin/program.exe
Calistir:
	./bin/program.exe
	