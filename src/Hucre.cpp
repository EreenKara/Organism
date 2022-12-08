#include "Hucre.hpp"
#include <iostream>
Hucre::Hucre(int value,Hucre* hucre=NULL)
{
    this->value=value;
    this->next=hucre;
}