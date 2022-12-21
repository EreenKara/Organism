/*
* @filee Organ.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

#include "Organ.hpp"
Organ::Organ()
{
    agac=new BST();
}
bool Organ::Dengelimi()  // AVL agaci mantigina gore Dengeli mi diye bakiyor.
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