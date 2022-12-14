Genel: Derle Bagla Calistir
Derle:
	g++ -I ./include/ -c ./src/Hucre.cpp -o ./lib/Hucre.o
	g++ -I ./include/ -c ./src/Doku.cpp -o ./lib/Doku.o
	g++ -I ./include/ -c ./src/BSTNode.cpp -o ./lib/BSTNode.o
	g++ -I ./include/ -c ./src/BST.cpp -o ./lib/BST.o
	g++ -I ./include/ -c ./src/Organ.cpp -o ./lib/Organ.o
	g++ -I ./include/ -c ./src/Kontrol.cpp -o ./lib/Kontrol.o
	g++ -I ./include/ -c ./src/Sistem.cpp -o ./lib/Sistem.o
	g++ -I ./include/ -c ./src/SistemNode.cpp -o ./lib/SistemNode.o
	g++ -I ./include/ -c ./src/Organizma.cpp -o ./lib/Organizma.o
	g++ -I ./include/ -c ./src/OrganNode.cpp -o ./lib/OrganNode.o
	g++ -I ./include/ -c ./src/main.cpp -o ./lib/main.o
	
Bagla:
	g++ ./lib/Hucre.o ./lib/Doku.o ./lib/Kontrol.o ./lib/BST.o ./lib/BSTNode.o ./lib/Organ.o ./lib/Sistem.o ./lib/SistemNode.o ./lib/Organizma.o ./lib/OrganNode.o ./lib/main.o -o ./bin/program.exe
Calistir:
	./bin/program.exe
	