#include "Doku.hpp"
#include <iostream>

void Doku::RadixSort()
{
    std::cout<<"Basladi"<<std::endl;
    int* siralanmisSayilar=radix->Sort(hucreHead,length);
    Hucre* temp=hucreHead;  // gezip uyuşan elemanı bulmak için
    Hucre* tempPrevious=NULL;  // Konumunu değiştirmek için bir öncesindeki düğüme ihtiyacım var
    Hucre* gelecegiDugumOncesi=NULL;  // hangi konuma geleceğini ben beliriliyorum çünkü bunlar sıralanmış sayılar 1 2  3 şeklinde gidecek
    std::cout<<"Hata Bulmaca 1"<<std::endl;
    for (int i = 0; i < length; i++)
    {
        if(gelecegiDugumOncesi!=NULL) temp=gelecegiDugumOncesi->next;

        tempPrevious=NULL;
        for (int j = 0; j < length; j++)  // listeden eşleşeni bulma
        {
            if(temp->value==siralanmisSayilar[i])
            {
                break;
            }
            tempPrevious=temp;
            temp=temp->next;
        }
        KonumSirala(temp,tempPrevious,gelecegiDugumOncesi); // hata var
        if(gelecegiDugumOncesi==NULL)
        {
            gelecegiDugumOncesi=hucreHead; 
        }
        else
        {
            gelecegiDugumOncesi=gelecegiDugumOncesi->next;
        }
    }
    delete[] siralanmisSayilar;
}
void Doku::YariyaDusur()
{
    Hucre* temp=hucreHead;
    for (int i = 0; i < length; i++)
    {
        if (temp->value%2==0)
        {
            temp->value=temp->value/2;
        }
        temp=temp->next;
    }
}
Doku::Doku()
{
    radix=new Radix();
    hucreHead=NULL;
    length=0;
}
int Doku::GetLength()
{
    return length;
}
void Doku::Add(int veri)
{
    Add(veri,length);
}
void Doku::Add(int veri,int index)
{
    if(index<0||index>length) return;
    Hucre* temp=FindPrevious(index);
    if(hucreHead==0)
    {
        hucreHead=new Hucre(veri);
        length++;
    }
    else if(index==0)
    {
        temp=new Hucre(veri,hucreHead);
        hucreHead=temp;
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
        hucreHead=del->next;
    }
    else
    {
        Hucre* temp= FindPrevious(index);
        temp->next=del->next;
    }
    
    delete del;
    length--;
}
void Doku::KonumSirala(Hucre* subnode,Hucre* subnodePrevious,Hucre* gelecegiDugumOncesi)
{
    if(subnodePrevious!=NULL)
    {
        subnode->next=NULL;
    }
    else
    {
        subnodePrevious->next=subnode->next;
        subnode->next=NULL;
    }
    // Bağalntıyı koparmak için 

    if(gelecegiDugumOncesi==NULL)
    {
        subnode->next=hucreHead;
        hucreHead=subnode;
    }
    else
    {
        subnode->next=gelecegiDugumOncesi->next;
        gelecegiDugumOncesi->next=subnode;
    }

}
Hucre* Doku::FindPrevious(int index)
{
    if(index<=0||index>length) return NULL;
    Hucre* temp=hucreHead;
    for (int i = 0; i < index-1; i++)
    {
        temp=temp->next;
    }
    return temp;
}
int Doku::Ortanca()
{
    Hucre* temp=hucreHead;
    for (size_t i = 0; i < (length/2); i++)
    {
        temp=temp->next;
    }
    return temp->value;
}
void Doku::Print()
{
    Hucre* temp=hucreHead;
    for (int i = 0; i < length; i++)
    {
        std::cout<<temp->value<<"  ";
        temp=temp->next;
    }
}
void Doku::Clear()
{
    Hucre* temp=hucreHead;
    Hucre* del;
    for (int i = 0; i < length; i++)
    {
        del=temp;
        temp=temp->next;
        delete del;
    }
    hucreHead=0;
    length=0;
}
Doku::~Doku()
{
    Clear();
    delete radix;
}
