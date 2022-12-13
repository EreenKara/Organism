#ifndef Hucre_hpp
#define Hucre_hpp
#include <iostream>
class Doku;
class BST;
class Hucre
{
private:
    int value;
    Hucre* next;
    friend Doku;
    friend BST;
public:
    Hucre(int value,Hucre* next=NULL);
};

#endif