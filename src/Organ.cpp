#include "Organ.hpp"
Organ::Organ()
{
    agac=new BST();
}
bool Organ::Dengesizmi()
{
    return agac->AVLmi(agac->kok);
}
void Organ::MutasyonaUgra()
{
    agac->PreOrderMutasyon(agac->kok);
    ;
}