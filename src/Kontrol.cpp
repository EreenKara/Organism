#include "Kontrol.hpp"

Kontrol::Kontrol(string dosyaYolu)
{
    organizma=new Organizma();
    dosya = new DosyaOkuma(dosyaYolu);
    dokuSayisi=dosya->satirSayisi;
    organSayisi=(dosya->satirSayisi/20)+1;
    sistemSayisi=(dosya->satirSayisi/2000)+1;
    OrganizmayiOlustur();
}

void Kontrol::OrganizmayiOlustur()
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

void Kontrol::Yazdir()
{
    SistemNode* tempSistem = organizma->sistemHead;
    OrganNode* tempOrgan;
    for (int i = 0; i < organizma->length; i++)
    {
        tempOrgan=tempSistem->sistem->organHead;
        for (int j = 0; j < tempSistem->sistem->length; j++)
        {
            if (tempOrgan->organ->Dengelimi())
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

void Kontrol::Mutasyon()
{
    organizma->MutasyonaUgra();
}
char Kontrol::GetKey()
{
    char key;
    key=_getch();
    return key;
}
void Kontrol::Interface()
{
    char key;
    bool mutasyonOldumu=false;
    do
    {
        system("cls");
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