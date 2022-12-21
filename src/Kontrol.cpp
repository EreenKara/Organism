/*
* @filee Kontrol.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

#include "Kontrol.hpp"

Kontrol::Kontrol(string dosyaYolu)
{
    organizma=new Organizma();
    dosya = new DosyaOkuma(dosyaYolu); 
    dokuSayisi=dosya->satirSayisi;
    organSayisi=(dosya->satirSayisi/20)+1;  // kullanmiyorum ama dursun yine de
    sistemSayisi=(dosya->satirSayisi/2000)+1;   // kullanmiyorum ama dursun yine de
    OrganizmayiOlustur(); // kontrol olustugunda direkt olarak bagli liste, agac, yapilarina atama yapiyor 
}

void Kontrol::OrganizmayiOlustur()  // Organizma'nin lusmasi icin gerekli yapilara ekleme islemleri yapiyor.
{
    int** sayilar = dosya->Oku();
    Organ* organ=new Organ();
    Sistem* sistem=new Sistem();
    for (int k = 0; k < dokuSayisi; k++)
    {
        Doku* doku=new Doku();
        for (int m = 0; m < dosya->satirSayiSayisi[k]; m++)
        {
            doku->Add(sayilar[k][m]);
        }
        doku->RadixSort();
        organ->agac->Add(doku);
        if((k+1)%20==0)
        {
            sistem->Add(organ);
            organ=new Organ();
        }
        if((k+1)%2000==0) 
        {   
            organizma->Add(sistem);
            sistem=new Sistem();
        }
    }
    delete [] sayilar;   
}

void Kontrol::Yazdir()   // 
{
    SistemNode* tempSistem = organizma->sistemHead;
    OrganNode* tempOrgan;
    for (int i = 0; i < organizma->length; i++)  //sistemleri dolasiyor. Sistem saiysi kadar donecek
    {
        tempOrgan=tempSistem->sistem->organHead;
        for (int j = 0; j < tempSistem->sistem->length; j++)  // Organlari dolasiyor
        {
            if (tempOrgan->organ->Dengelimi())  // AVL'ye gore denge kontrol ediyor 
            {
                cout<<" ";
            }
            else
            {
                cout<<"#";
            }
            tempOrgan=tempOrgan->next;
        }
        cout<<endl;
        tempSistem=tempSistem->next;
    }
}

void Kontrol::Mutasyon()  // Kullanicinin kullancagi fonksiyonlari tek bir yerden kontrol etmek icin buraya da bir mutasyon fonk yazdim.
{
    organizma->MutasyonaUgra();
}
char Kontrol::GetKey()  // kullanicidan girilen char degeri okuyor
{
    char key;
    key=_getch();
    return key;
}
void Kontrol::Interface()  // Kullaniciya Arayuz saglamak icin yazdim
{
    char key;
    bool mutasyonOldumu=false;
    do
    {
        system("cls");
        if(mutasyonOldumu)
        {
            std::cout<<std::setw(55)<<"Organizma ( Mutasyona Ugradi ) "<<std::endl;
        }
        Yazdir();
        std::cout<<std::endl;
        if(mutasyonOldumu) break;
        else
        {
            std::cout<<"Mutasyon icin Enter tusuna bas"<<std::endl;
            std::cout<<"Cikis icin ESC tusuna bas"<<std::endl;
        }
        key=GetKey();
        switch(key)
        {
            case 13: 
                Mutasyon();
                mutasyonOldumu=true;
                break;
            default:
                break;
        }
    } while (key!=27);
    std::cout<<std::endl;
    std::cout<<"Cikis Yaptiniz";
}
Kontrol::~Kontrol()
{
    delete dosya;
    delete organizma;
}