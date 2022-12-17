#ifndef Radix_hpp
#define Radix_hpp
#include "Doku.hpp"
#include "Queue.hpp"
class Kontrol;
class Doku;
class Radix
{
private:
    Queue* kuyruklar;
    int maxBasamak;
    friend Doku;
    friend Kontrol;
public:
    Radix(); 
    int* KuyruklarinUzunlugu();
    int BasamakSayisi(int sayi);
    int EnBuyukBasamak(Hucre* head,int length);
    int* Sort(Hucre* head,int length);
    ~Radix();
    //void Open(Doku* doku);
};

#endif 