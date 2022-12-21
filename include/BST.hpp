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
    int Yukseklik(BSTNode* subnode);  // Yukselik buluyor
    BSTNode* Ara(BSTNode* subnode,int veri);  // verilen bir integer degeri istenilen dugumden itibaren ariyor
    void PostOrder(BSTNode* subnode);   // PostOrder yazdirmanin Recursive'i icin yazilan fonk. 
    void AddPrivate(BSTNode*& subnode,Doku* doku);  // Ekleme islemini disaridan gizlemek ve recursive oalrak yazmak icin olusturdugum bir fonskiyon
    void DeletePrivate(BSTNode*& subnode,int veri); // Silinecek degeri ariyor.
    void DeleteReal(BSTNode*& subnode);  // silme islemindeki aradaki baglari ayarliyor.
    void DokuKopyalama(Doku*& doku1,Doku*& doku2);  // Dokuyu baska bir dokuya kopyaliyor.
    bool AVLmi(BSTNode* subnode);  // Agac'in AVL agacina uyup uymadigina bakiyor.
    void PreOrderMutasyon(BSTNode* subnode);
    void ClearPrivate(BSTNode* subnode);
    int PostOrderYedekle(Doku** dokular,BSTNode* subnode,int index);
    void PostOrderSil(BSTNode* subnode);
    void PostOrderYeniAgac();
public:
    BST();
    void Add(Doku* doku); // Disariya actigim ekleme durumu
    void Delete(int veri); // Disariya actigim silme durumu
    void PostOrder();  // PostOrder Yazdirma Islemi
    void Clear();
    ~BST();
    
};

#endif