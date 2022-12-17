#ifndef SistemNode_hpp
#define SistemNode_hpp
#include "Sistem.hpp"
class Kontrol;
class Organizma;
class SistemNode
{
private:
    Sistem* sistem;
    SistemNode* next;
    friend Organizma;
    friend Kontrol;
public:
    SistemNode(Sistem* sistem,SistemNode* next=NULL);
    ~SistemNode();
};

#endif