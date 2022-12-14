#include "Organizma.hpp"
Organizma::Organizma()
{
    this->head=NULL;
    this->length=0;
}
void Organizma::MutasyonaUgra()
{
    SistemNode* temp=head;
    for (int i = 0; i < length; i++)
    {
        
    }
    
}
void Organizma::Add(Sistem* sistem)
{
    SistemNode* temp=head;
    if(head==NULL)
    {
        head=new SistemNode(sistem);
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
    SistemNode* temp=head;
    SistemNode* del;
    if(length==0) return;
    else if(length==1)
    {
        del=head;
        head=NULL;
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