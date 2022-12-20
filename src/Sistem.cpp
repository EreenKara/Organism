#include "Sistem.hpp"

Sistem::Sistem()
{
    this->organHead=NULL;
    this->length=0;
}
void Sistem::Add(Organ* organ)
{
    OrganNode* temp=organHead;
    if(organHead==NULL)
    {
        organHead=new OrganNode(organ);
    }
    else
    {
        for (int i = 0; i < length-1; i++)
        {
            temp=temp->next;
        }
        temp->next=new OrganNode(organ);
    }
    length++;
}
void Sistem::Delete()
{
    OrganNode* temp=organHead;
    OrganNode* del;
    if(length==0) return;
    else if(length==1)
    {
        del=organHead;
        organHead=NULL;
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
Sistem::~Sistem()
{
    for (int i = 0; i < length; i++)
    {
        Delete();
    }
    
}