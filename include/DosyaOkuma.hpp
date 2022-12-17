#ifndef DosyaOkuma_hpp
#define DosyaOkuma_hpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Kontrol;
class DosyaOkuma  // verilerin üzerinde yapacağım değişiklikler bu sınıf aracılığıyla olacak
{
private:
    ifstream Read;
    ofstream Write;
    string dosyaYolu;
    int satirSayisi;
    friend Kontrol;
public:
    DosyaOkuma(string dosyaYolu);
    int* BelirliBirSatir(int index);
    int** Oku();
};
#endif