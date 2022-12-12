#ifndef Hucre_hpp
#define Hucre_hpp
#include "Doku.hpp"
#include <iostream>
class Doku;
class Hucre
{
private:
    int value;
    Hucre* next;
public:
    Hucre(int value,Hucre* next=NULL);
    friend Doku;
    
};

#endif