#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Kontrol  // verilerin üzerinde yapacağım değişiklikler bu sınıf aracılığıyla olacak
{
private:
    ifstream Read;
    ofstream Write;
    string dosyaYolu;
    int satirSayisi;
public:
    Kontrol(string dosyaYolu);
    int* BelirliBirSatir(int index);
    int** Oku();
};