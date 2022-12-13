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
bool BST::Ara()
{

}
void BST::PostOrder()
{
    PostOrder(kok);
}
void BST::PostOrder(BSTNode* subnode)
{  
    PostOrder(subnode->left);
    PostOrder(subnode->right);
    std::cout<<subnode->doku->Ortanca()<<" ";  
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
void BST::Delete(int veri)
{
    DeletePrivate(kok);
}
void BST::DeletePrivate(BSTNode*& subnode,int veri)
{
    if(!subnode) return;
    else if(subnode->doku->Ortanca()==veri) DeleteReal();
    else if(veri<subnode->doku->Ortanca()) DeletePrivate(subnode->left,veri);
    else if (veri>subnode->doku->Ortanca()) DeletePrivate(subnode->right,veri);
}

