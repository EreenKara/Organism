#ifndef BST_hpp
#define BST_hpp
#include "BSTNode.hpp"
class Kontrol;
class Organ;
class Organizma;
class BST
{
private:
    BSTNode* kok;
    friend Organ;
    friend Organizma;
    friend Kontrol;
    int Yukseklik(BSTNode* subnode);
    BSTNode* Ara(BSTNode* subnode,int veri);
    void PostOrder(BSTNode* subnode);
    void AddPrivate(BSTNode*& subnode,Doku* doku);
    void DeletePrivate(BSTNode*& subnode,int veri);
    void DeleteReal(BSTNode*& subnode);
    void DokuKopyalama(Doku*& doku1,Doku*& doku2);
    bool AVLmi(BSTNode* subnode);
    void PreOrderMutasyon(BSTNode* subnode);
    void ClearPrivate(BSTNode* subnode);
    void PostOrderYedekle(Doku** dokular,BSTNode* subnode);
    void PostOrderSil(BSTNode* subnode);
    void PostOrderYeniAgac();
public:
    BST();
    void Add(Doku* doku);
    void Delete(int veri);
    void PostOrder();
    void Clear();
    
};

#endif