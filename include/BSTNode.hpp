#ifndef BSTNode_hpp
#define BSTNode_hpp
#include "iostream"
class BSTNode
{
private:
    int value;
    BSTNode* left;
    BSTNode* right;
public:
    BSTNode(int value,BSTNode* left,BSTNode* right);
};

#endif