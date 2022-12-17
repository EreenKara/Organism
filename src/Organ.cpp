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
    agac->CiftseYariyaDusur(agac->kok);
}