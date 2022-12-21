/*
* @filee main.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

#include <iostream>
#include "Kontrol.hpp"
using namespace std;

int main()
{
    Kontrol* kontrol=new Kontrol("Veriler.txt"); 
    kontrol->Interface();
    delete kontrol;
    
}