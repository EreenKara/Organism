#ifndef BST_hpp
#define BST_hpp
#include "BSTNode.hpp"

class BST
{
private:
    BSTNode* kok;
    int Yukseklik(BSTNode* subnode);
    bool Ara();
    void PostOrder(BSTNode* subnode);
    void AddPrivate(BSTNode*& subnode,Doku* doku);
    void DeletePrivate(BSTNode*& subnode,int veri);
    void DeleteReal(BSTNode*& subnode);
public:
    BST();
    void Add(Doku* doku);
    void Delete(int veri);
    void PostOrder();
    
};

#endif