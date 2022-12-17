#ifndef Organ_hpp
#define Organ_hpp
#include "Doku.hpp"
#include "BST.hpp"
class Organizma;
class Sistem;
class Organ
{
private:
    BST* agac;
    friend Organizma;
    friend Sistem;
public:
    Organ();
    void MutasyonaUgra();
    bool Dengesizmi();

};

#endif