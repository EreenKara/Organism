#ifndef Hucre_hpp
#define Hucre_hpp
#include <iostream>
class Doku;
class Hucre
{
private:
    int value;
    Hucre* next;
    friend Doku;
public:
    Hucre(int value,Hucre* next=NULL);
};

#endif