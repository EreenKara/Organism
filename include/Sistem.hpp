#ifndef Sistem_hpp
#define Sistem_hpp
#include "OrganNode.hpp"
class Sistem
{
private:
    OrganNode* head;
    int length;
public:
    Sistem();
    void Add(Organ* organ);
    void Delete();
    ~Sistem();

};


#endif