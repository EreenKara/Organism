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
void Organ::YeniAgac()
{
    agac->PostOrderYeniAgac();
}
Organ::~Organ()
{
    delete agac;
}