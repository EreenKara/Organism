/*
* @filee BST.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

#include "BST.hpp"
BST::BST()
{
    this->kok=NULL;
}
int BST::Yukseklik(BSTNode* subnode)
{
    if(subnode) return 1+std::max(Yukseklik(subnode->left), Yukseklik(subnode->right));
    return -1;
}
bool BST::AVLmi(BSTNode* subnode)  // yuksekligi 2 den fazla olan bir node buldugunda false donuyor. Her bir dugumu kontrol ediyor.
{
    if(subnode)
    {
        if(abs(Yukseklik(subnode->left)-Yukseklik(subnode->right))>=2)
        {
            return false;
        }
        else
        {
            if(AVLmi(subnode->left)==false) return false;  // Herhangi bir tanesinin false olmasi bozmak icin yeterli ancak
                                                           // Herhangi bir tanesinin true olmasi AVL agaci yapmiyor bunu. 
            if(AVLmi(subnode->right)==false) return false;
        }
    }
    return true;
}
BSTNode* BST::Ara(BSTNode* subnode,int veri)
{
    if(!subnode) return NULL;
    else if(subnode->doku->Ortanca()==veri) return subnode;
    else if(veri<subnode->doku->Ortanca()) Ara(subnode->left,veri);
    else if (veri>subnode->doku->Ortanca()) Ara(subnode->right,veri);
}
void BST::PostOrder()
{
    PostOrder(kok);
}
void BST::PostOrder(BSTNode* subnode)
{  
    if(subnode)
    {
        PostOrder(subnode->left);
        PostOrder(subnode->right);
        std::cout<<subnode->doku->Ortanca()<<" ";  
    }
}
void BST::Add(Doku* doku)
{
    AddPrivate(kok,doku);
}
void BST::AddPrivate(BSTNode*& subnode,Doku* doku)
{
    if(!subnode) subnode=new BSTNode(doku); 
    else if(doku->Ortanca()<subnode->doku->Ortanca())
    {
        AddPrivate(subnode->left,doku);
    }
    else if(doku->Ortanca()>subnode->doku->Ortanca())
    {
        AddPrivate(subnode->right,doku);
    }
    else // eşit olma durumunda sola eklenecek
    {
        subnode->left=new BSTNode(doku,subnode->left);
    }
}
void BST::DokuKopyalama(Doku*& doku1,Doku*& doku2)
{
    Hucre* temp=doku1->hucreHead;
    doku2->Clear();
    for (int i = 0; i < doku1->GetLength(); i++)
    {
        doku2->Add(temp->value);
        temp=temp->next;
    }
}
void BST::Delete(int veri)
{
    DeletePrivate(kok,veri);
}
void BST::DeleteReal(BSTNode*& subnode)
{
    BSTNode* del;
    if(subnode->left!=0 && subnode->right!=0)  // hem solu hem sağı varsa
    {
        del=subnode->right;
        BSTNode* parent=subnode;
        while(del->left)
        {
            parent=del;
            del=del->left;
        }
        DokuKopyalama(del->doku,subnode->doku);
        // subnode->doku=del->doku; bir ifade ancak bunu yazmamın nedeni 
        // BSTNode silindiğinde destructor onun dokusunu da siliyor
        if(parent==subnode)    subnode->right=parent->right;
        else
            parent->left=del->right;
       
    }
    else
    {
        if(subnode->left==0)  
        {
            del=subnode;
            subnode=subnode->right;
        }
        else if(subnode->right==0) // solu varsa
        {
            del=subnode;
            subnode=subnode->left;
        }
        else  // sagi ve solu yoksa 
        {
            del=subnode;
            subnode=0;
        }
    }
    delete del;
}
void BST::DeletePrivate(BSTNode*& subnode,int veri)
{
    if(!subnode) return;
    else if(subnode->doku->Ortanca()==veri) DeleteReal(subnode);
    else if(veri<subnode->doku->Ortanca()) DeletePrivate(subnode->left,veri);
    else if (veri>subnode->doku->Ortanca()) DeletePrivate(subnode->right,veri);
}
void BST::PreOrderMutasyon(BSTNode* subnode)
{
    if(subnode)
    {
        subnode->doku->YariyaDusur();
        PreOrderMutasyon(subnode->left);
        PreOrderMutasyon(subnode->right);
    }
}
void BST::PostOrderYeniAgac()
{
    BSTNode* yeniKok=NULL;
    Doku** dokular=new Doku*[20];

    PostOrderYedekle(dokular,kok,0);

    for (int i = 0; i < 20; i++)
    {
        AddPrivate(yeniKok,dokular[i]);
    }

    PostOrderSil(kok);
    kok=yeniKok;
}
int BST::PostOrderYedekle(Doku** dokular,BSTNode* subnode,int index)
{
    if(subnode)
    {   
        index =PostOrderYedekle(dokular,subnode->left,index);
        index =PostOrderYedekle(dokular,subnode->right,index);
        Hucre* temp=subnode->doku->hucreHead;
        dokular[index]=new Doku();
        for (int i = 0; i < subnode->doku->length; i++)
        {
            dokular[index]->Add(temp->value);
            temp=temp->next;
        }
        index++;
    }
    return index;
}
void BST::PostOrderSil(BSTNode* subnode)
{
    if(subnode)
    {   
        PostOrderSil(subnode->left);
        PostOrderSil(subnode->right);
        DeleteReal(subnode);
    }
}

BST::~BST()
{
    Clear();
}
void BST::Clear()
{
    ClearPrivate(kok);
}
void BST::ClearPrivate(BSTNode* subnode)
{
    if(subnode)
    {
        ClearPrivate(subnode->left);
        ClearPrivate(subnode->right);
        DeleteReal(subnode);
    }
}