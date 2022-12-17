#ifndef Sistem_hpp
#define Sistem_hpp
#include "OrganNode.hpp"
class Kontrol;
class Organizma;
class Sistem
{
private:
    OrganNode* organHead;
    int length;
    friend Organizma;
    friend Kontrol;
public:
    Sistem();
    void Add(Organ* organ);
    void Delete();
    ~Sistem();

};


#endif