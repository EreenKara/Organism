#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"
#include "Radix.hpp"
class Kontrol;
class BST;
class Radix;
class Organ;
class Doku
{
private:
    Hucre* hucreHead;
    Radix* radix;
    int length;
    friend BST;
    friend Organ;
    friend Radix;
    friend Kontrol;
public:
    void RadixSort(); // sort by using radixsort 
    Doku();
    void YariyaDusur();
    int GetLength();
    void Add(int veri);
    void Add(int veri,int index);
    void Delete();
    void Delete(int index);
    Hucre* FindPrevious(int index);
    int Ortanca();
    void Print();
    void KonumSirala(Hucre* subnode,Hucre* subnodePrevious,Hucre* gelecegiDugumOncesi);
    // Radix Sort yaptiktan sonra siralari ayarlayabilmek icin Konumlari siraliyorum. Baglantiyi koparip olmasi gerektigi yer tasiyorum.  
    ~Doku();
    void Clear();

};




#endif