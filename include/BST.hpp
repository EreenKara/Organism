#ifndef BST_hpp
#define BST_hpp
#include "BSTNode.hpp"
class BST
{
private:
    BSTNode* kok;
    int Yukseklik(BSTNode* subnode);
    BSTNode* Ara(BSTNode* subnode,int veri);
    void PostOrder(BSTNode* subnode);
    void AddPrivate(BSTNode*& subnode,Doku* doku);
    void DeletePrivate(BSTNode*& subnode,int veri);
    void DeleteReal(BSTNode*& subnode);
    // void DokuKopyalama(Doku*& doku1,Doku*& doku2);
public:
    BST();
    
    void Add(Doku* doku);
    void Delete(int veri);
    void PostOrder();
    
};

#endif