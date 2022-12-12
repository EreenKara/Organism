#ifndef BSTNode_hpp
#define BSTNode_hpp
#include <iostream>
#include "Doku.hpp"
class BSTNode
{
private:
    Doku* value;
    BSTNode* left;
    BSTNode* right;
public:
    BSTNode(Doku* value,BSTNode* left=NULL,BSTNode* right=NULL);
};

#endif