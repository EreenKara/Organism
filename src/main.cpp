#include <iostream>
#include "Doku.hpp"
using namespace std;

int main()
{
    Doku* doku=new Doku();
    doku->Add(10);
    doku->Add(20);
    doku->Add(30);
    doku->Add(40);
    doku->Add(50,2);
    doku->Print();
}