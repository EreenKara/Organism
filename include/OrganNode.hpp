#ifndef OrganNode_hpp
#define OrganNode_hpp
#include "Organ.hpp"
class Sistem;
class OrganNode
{
private:
    Organ* organ;
    OrganNode* next;
    friend Sistem;
public:
    OrganNode(Organ* organ,OrganNode* next=NULL);
    ~OrganNode();
};

#endif