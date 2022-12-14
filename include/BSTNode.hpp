#ifndef BSTNode_hpp
#define BSTNode_hpp
#include <iostream>
#include "Doku.hpp"
// DokuNode olarakta düşünülebilir.
class BST;
class BSTNode
{
private:
    Doku* doku;
    BSTNode* left;
    BSTNode* right;
    int length;
    friend BST;
public:
    BSTNode(Doku* doku,BSTNode* left=NULL,BSTNode* right=NULL);
    ~BSTNode();
    
};

#endif