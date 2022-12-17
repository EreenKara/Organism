#ifndef Sistem_hpp
#define Sistem_hpp
#include "OrganNode.hpp"
class Organizma;
class Sistem
{
private:
    OrganNode* organHead;
    int length;
    friend Organizma;
public:
    Sistem();
    void Add(Organ* organ);
    void Delete();
    ~Sistem();

};


#endif