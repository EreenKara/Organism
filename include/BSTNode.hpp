#ifndef BSTNode_hpp
#define BSTNode_hpp
#include <iostream>
#include "Doku.hpp"
// DokuNode olarakta düşünülebilir.
class Kontrol;
class BST;
class Organizma;
class Organ;


class BSTNode
{
private:
    Doku* doku;
    BSTNode* left;
    BSTNode* right;
    int length;
    friend BST;
    friend Organ;
    friend Organizma;
    friend Kontrol;
    
public:
    BSTNode(Doku* doku,BSTNode* left=NULL,BSTNode* right=NULL);
    ~BSTNode();
    
};

#endif