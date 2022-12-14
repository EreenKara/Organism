#ifndef Radix_hpp
#define Radix_hpp
#include "Doku.hpp"
#include "Queue.hpp"
class Radix
{
private:
    Doku* doku;
    Queue* kuyruklar;
    int maxBasamak;
public:
    Radix(Doku* doku); 
    int* KuyruklarinUzunlugu();
    int BasamakSayisi(int sayi);
    int EnBuyukBasamak();
    void Sort();
    ~Radix();
    //void Open(Doku* doku);
};

#endif 