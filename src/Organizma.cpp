/*
* @filee Organizma.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

#include "Organizma.hpp"
Organizma::Organizma()
{
    this->sistemHead=NULL;
    this->length=0;
}
void Organizma::MutasyonaUgra()  // tek tek hangi organin mutasyona ugrayacagini buluyor ve onların Mutasyona ugra Fonksiyonunu cagiriyor. 
{
    SistemNode* sistemTemp=sistemHead;
    for (int i = 0; i < length; i++) // sistem sayisi kadar donecek
    {
        OrganNode* organTemp=sistemTemp->sistem->organHead;
        for (int j = 0; j < sistemTemp->sistem->length; j++) // sistemdeki organ sayisi kadar donecek.
        {
            if(organTemp->organ->agac->kok->doku->Ortanca()%50==0) // Agacin kokundeki dokunun ortasindak deger 50'ye tam bolunuyoras Mutasyon gerceklesecek.
            {
                organTemp->organ->MutasyonaUgra();
                organTemp->organ->YeniAgac();
            }
            organTemp=organTemp->next;
        }
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