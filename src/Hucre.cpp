#include "Hucre.hpp"
Hucre::Hucre(int value,Hucre* hucre)
{
    this->value=value;
    this->next=hucre;
}