#include "Organ.hpp"
Organ::Organ()
{
    agac=new BST();
}
bool Organ::Dengelimi()
{
    return agac->AVLmi(agac->kok);
}
void Organ::MutasyonaUgra()
{
    agac->PreOrderMutasyon(agac->kok);
}
Organ::~Organ()
{
    delete agac;
}