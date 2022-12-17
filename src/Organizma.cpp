#include "Organizma.hpp"
Organizma::Organizma()
{
    this->sistemHead=NULL;
    this->length=0;
}
void Organizma::MutasyonaUgra()
{
    SistemNode* sistemTemp=sistemHead;
    for (int i = 0; i < length; i++)
    {
        OrganNode* organTemp=sistemTemp->sistem->organHead;
        for (int j = 0; j < sistemTemp->sistem->length; j++)
        {
            //organ
            if(organTemp->organ->agac->kok->doku->Ortanca()%50==0)
            {
                organTemp->organ->MutasyonaUgra();
            }
            organTemp=organTemp->next;
        }
        //sistem
        sistemTemp=sistemTemp->next;
    }
    
}
void Organizma::Add(Sistem* sistem)
{
    SistemNode* temp=sistemHead;
    if(sistemHead==NULL)
    {
        sistemHead=new SistemNode(sistem);
    }
    else
    {
        for (int i = 0; i < length-1; i++)
        {
            temp=temp->next;
        }
        temp->next=new SistemNode(sistem);
    }
    length++;
}
void Organizma::Delete()
{
    SistemNode* temp=sistemHead;
    SistemNode* del;
    if(length==0) return;
    else if(length==1)
    {
        del=sistemHead;
        sistemHead=NULL;
    }
    else 
    {
        for (size_t i = 0; i < length-2; i++)
        {
            temp=temp->next;
        }
        del=temp->next;
        temp->next=NULL;
    }
    delete del;
    length--;
}
Organizma::~Organizma()
{
    for (int i = 0; i < length; i++)
    {
        Delete();
    }
    
}