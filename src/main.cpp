#include <iostream>
#include "Kontrol.hpp"
using namespace std;

int main()
{
    Kontrol* kontrol=new Kontrol("Veriler.txt"); 
    kontrol->Interface();
    delete kontrol;
 
}