/*
* @filee Radix.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

#include "Radix.hpp"
Radix::Radix()
{
    this->kuyruklar=new Queue[10];
    this->maxBasamak=0;
}
int* Radix::KuyruklarinUzunlugu()  // cagıtrdıgın yerde bu uzunluk ile işin bittiyse onu sil
{
    int* lengths=new int[10];
    for (int i = 0; i < 10; i++)
    {
        lengths[i]=kuyruklar[i].length;
    }
    return lengths;
}
int Radix::BasamakSayisi(int sayi)
{
    int basamak=0;
    while (sayi!=0)
    {
        sayi=sayi/10;
        basamak++;
    }
    return basamak;
}
int Radix::EnBuyukBasamak(Hucre* head,int length)
{
    int enBuyukBasamak=0;
    Hucre* temp=head;
    for (int i = 0; i < length; i++)
    {
        if(enBuyukBasamak<BasamakSayisi(temp->value))
        {
            enBuyukBasamak=BasamakSayisi(temp->value);
        }
    }
    maxBasamak=enBuyukBasamak;  // sinifin bir degiskeni olan max basamagi guncelliyor.
    return enBuyukBasamak;
}
int* Radix::Sort(Hucre* head,int length)
{
    EnBuyukBasamak(head,length);
    int basamakDegeri=0;
    Hucre* temp=head;
    for (int i = 0; i < length; i++) // Kuyruklara ilk ekelemeyi yapiyor.
    {
        basamakDegeri=temp->value%10;
        kuyruklar[basamakDegeri].Enqueue(temp->value);
        temp=temp->next;
    }
    int* kuyruklarinSuankiDolulugu;
    for (int i = 1; i < maxBasamak; i++)  // kuyruklara 1. disindaki eklemeyi yapiyor
    {
        kuyruklarinSuankiDolulugu =KuyruklarinUzunlugu();
        for (int j = 0; j < 10; j++)  // 10 tane basmak degeri kuyrugunun icini bosaltiyor ve bosaltirken ekleme yapiyor.
        {
            int uzunluk=kuyruklarinSuankiDolulugu[j];
            int sayi=0;
            for (; uzunluk>0; uzunluk--)
            {
                sayi=kuyruklar[j].Peek();
                kuyruklar[j].Dequeue();
                basamakDegeri= int(sayi/pow(10,i)) % 10;
                kuyruklar[basamakDegeri].Enqueue(sayi);
            }    
        }   
    }
    delete [] kuyruklarinSuankiDolulugu;
    int* siralanmisSayilar=new int[length]; 
    int index=0;
    for (int i = 0; i < 10; i++)
    {
        while(kuyruklar[i].length!=0)
        {
            siralanmisSayilar[index++]=kuyruklar[i].Peek();
            kuyruklar[i].Dequeue();
        }
    }
    return siralanmisSayilar;
}
Radix::~Radix()
{
    delete [] kuyruklar;
}