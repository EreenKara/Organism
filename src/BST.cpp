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
// void BST::DokuKopyalama(Doku*& doku1,Doku*& doku2)
// {
//     Hucre* temp=doku1->head;
//     doku2->Clear();
//     for (int i = 0; i < doku1->GetLength(); i++)
//     {
//         doku2->Add(temp->value);
//         temp=temp->next;
//     }
// }
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
        parent->left=del->right;
        // DokuKopyalama(del->doku,subnode->doku); // subnode->doku=del->doku; bir ifade ancak bunu yazmamın nedeni 
        // BSTNode silindiğinde destructor onun dokusunu da siliyor.

    }
    else
    {
        if(subnode->left!=0)  //solu varsa
        {
            del=subnode;
            subnode=subnode->left;
        }
        else if(subnode->right!=0) // sağı varsa
        {
            del=subnode;
            subnode=subnode->right;
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

