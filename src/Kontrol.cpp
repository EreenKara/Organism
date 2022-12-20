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

Kontrol::~Kontrol()
{
    delete dosya;
    delete organizma;
}

// void Kontrol::Yazdir()
// {
//     SistemNode* tempSistem=organizma->sistemHead;
//     OrganNode* tempOrgan=tempSistem->sistem->organHead;
//     Doku* doku=tempOrgan->organ->agac->kok->doku;

//     tempOrgan->organ->agac->PostOrder();
    
// }

// void Kontrol::OrganizmayiOlustur()
// {
//     int** sayilar = dosya->Oku();
//     Doku** doku=new Doku*[dosya->satirSayisi];
//     Organ** organ=new Organ*[organSayisi];
//     Sistem** sistem=new Sistem*[sistemSayisi];
//     int organsayi=0;
//     int sistemsayi=0;
//     doku[0]=new Doku();
//     for (int m = 0; m < dosya->satirSayiSayisi[0]; m++)
//     {
//         doku[0]->Add(sayilar[0][m]);
//     }
//     doku[0]->RadixSort();
//     for (int k = 1; k <= dokuSayisi; k++)
//     {
//         doku[k]=new Doku();
//         for (int m = 0; m < dosya->satirSayiSayisi[k]; m++)
//         {
//             doku[k]->Add(sayilar[k][m]);
//         }
//         if(k%20==0||k==1)
//         {
//             if(k!=1)
//             {
//                 sistem[sistemsayi]->Add(organ[organsayi]);
//                 organsayi++;
//             }
//             organ[organsayi]=new Organ();
//         }
        
//         if(k==1)
//         {
//             organ[organsayi]->agac->Add(doku[0]);
//         }
//         doku[k]->RadixSort();
//         organ[organsayi]->agac->Add(doku[k]); // hata burda
        
//         if(k%2000==0||k==1) 
//         { 
//             if(k!=1)
//             {
//                 organizma->Add(sistem[sistemsayi]);
//                 sistemsayi++;
//             }
//             sistem[sistemsayi]=new Sistem();
//         }
//     }
//     delete [] sayilar;   
// }