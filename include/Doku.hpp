#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"
class Hucre;
class Doku
{
private:
    Hucre* head;
    int length;
public:
    void RadixSort(); // sort by using radixsort 
    Doku();
    void Add(int veri);
    void Add(int veri,int index);
    void Delete();
    void Delete(int index);
    Hucre* FindPrevious(int index);
    int Ortanca();
    void Print();
    ~Doku();
    void Clear();

};




#endif