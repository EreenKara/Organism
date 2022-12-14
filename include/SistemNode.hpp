#ifndef SistemNode_hpp
#define SistemNode_hpp
#include "Sistem.hpp"
class Organizma;
class SistemNode
{
private:
    Sistem* sistem;
    SistemNode* next;
    friend Organizma;
public:
    SistemNode(Sistem* sistem,SistemNode* next=NULL);
    ~SistemNode();
};

#endif