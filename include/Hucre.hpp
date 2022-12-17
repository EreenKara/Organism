#ifndef Hucre_hpp
#define Hucre_hpp
#include <iostream>
class Kontrol;
class Doku;
class BST;
class Queue;
class Radix;
class Hucre
{
private:
    int value;
    Hucre* next;
    friend Doku;
    friend BST;
    friend Queue;
    friend Radix;
    friend Kontrol;
public:
    Hucre(int value,Hucre* next=NULL);
};

#endif