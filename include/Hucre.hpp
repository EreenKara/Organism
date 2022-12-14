#ifndef Hucre_hpp
#define Hucre_hpp
#include <iostream>
class Doku;
class BST;
class Queue;
class Hucre
{
private:
    int value;
    Hucre* next;
    friend Doku;
    friend BST;
    friend Queue;
public:
    Hucre(int value,Hucre* next=NULL);
};

#endif