#include "Doku.hpp"
#include <iostream>

void Doku::RadixSort()
{

}
Doku::Doku()
{
    head=NULL;
    length=0;
}
void Doku::Add(int veri)
{
    Add(veri,length);
}
void Doku::Add(int veri,int index)
{
    if(index<0||index>length) return;
    Hucre* temp=FindPrevious(index);
    if(head==0)
    {
        head=new Hucre(veri);
        length++;
    }
    else if(index==0)
    {
        temp=new Hucre(veri,head);
        head=temp;
        length++;
    }
    else
    {
        temp->next=new Hucre(veri,temp->next);
        length++;
    }
}
void Doku::Delete()
{
    Delete(length);
}
void Doku::Delete(int index)
{
    if(index<0||index>=length) return;
    Hucre* del=FindPrevious(index+1);
    if(index==0)
    {
        head=del->next;
    }
    else
    {
        Hucre* temp= FindPrevious(index);
        temp->next=del->next;
    }
    
    delete del;
    length--;
}
Hucre* Doku::FindPrevious(int index)
{
    if(index<=0||index>length) return NULL;
    Hucre* temp=head;
    for (int i = 0; i < index-1; i++)
    {
        temp=temp->next;
    }
    return temp;
}
int Doku::Ortanca()
{
    Hucre* temp=head;
    for (size_t i = 0; i < (length/2); i++)
    {
        temp=temp->next;
    }
    return temp->value;
}
void Doku::Print()
{
    Hucre* temp=head;
    for (int i = 0; i < length; i++)
    {
        std::cout<<temp->value<<"  ";
        temp=temp->next;
    }
}
void Doku::Clear()
{
    Hucre* temp=head;
    Hucre* del;
    for (int i = 0; i < length; i++)
    {
        del=temp;
        temp=temp->next;
        delete del;
    }
    head=0;
    length=0;
}
Doku::~Doku()
{
    Clear();
}
