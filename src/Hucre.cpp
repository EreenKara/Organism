/*
* @filee Hucre.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

#include "Hucre.hpp"
Hucre::Hucre(int value,Hucre* hucre)
{
    this->value=value;
    this->next=hucre;
}