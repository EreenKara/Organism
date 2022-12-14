#include "Radix.hpp"
Radix::Radix(Doku* doku)
{
    this->doku=doku;
    this->kuyruklar=new Queue[10];
    this->maxBasamak=EnBuyukBasamak();
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
int Radix::EnBuyukBasamak()
{
    int enBuyukBasamak=0;
    Hucre* temp=doku->head;
    for (int i = 0; i < doku->length; i++)
    {
        if(enBuyukBasamak<BasamakSayisi(temp->value))
        {
            enBuyukBasamak=BasamakSayisi(temp->value);
        }
    }
    return enBuyukBasamak;
}
void Radix::Sort()
{
    int basamakDegeri=0;
    Hucre* temp=doku->head;
    for (int i = 0; i < doku->length; i++)
    {
        basamakDegeri=temp->value%10;
        kuyruklar[basamakDegeri].Enqueue(temp->value);
        temp=temp->next;
    }
    int* kuyruklarinSuankiDolulugu=KuyruklarinUzunlugu();
    for (int i = 1; i < maxBasamak; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int uzunluk=kuyruklarinSuankiDolulugu[j];
            int sayi=0;
            for (; uzunluk>0; uzunluk--)
            {
                sayi=kuyruklar[j].Peek();
                kuyruklar[j].Dequeue();
                basamakDegeri= (sayi/(int)pow(10,i)) % 10;
                kuyruklar[basamakDegeri].Enqueue(sayi);
            }   
        }        
    }
    delete [] kuyruklarinSuankiDolulugu;
    int* siralanmisSayilar=new int[doku->length]; 
    int index=0;
    for (int i = 0; i < 10; i++)
    {
        while(kuyruklar[i].length!=0)
        {
            siralanmisSayilar[index++]=kuyruklar[i].Peek();
            kuyruklar[i].Dequeue();
        }
        
    }
    temp=doku->head;
    Hucre* gelecegiDugum=doku->head;
    for (int i = 0; i < doku->length; i++)
    {
        temp=doku->head;
        for (int j = 0; j < doku->length; j++)
        {
            if(temp->value==siralanmisSayilar[i])
            {
                break;
            }
            temp=temp->next;
        }
        
    }
    


}
Radix::~Radix()
{
    delete [] kuyruklar;
}