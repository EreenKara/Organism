#ifndef Doku_hpp
#define Doku_hpp
#include "Hucre.hpp"
class BST;
class Doku
{
private:
    Hucre* head;
    int length;
    friend BST;
public:
    void RadixSort(); // sort by using radixsort 
    Doku();
    int GetLength();
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