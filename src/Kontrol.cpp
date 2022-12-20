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
    Doku** doku=new Doku*[dosya->satirSayisi];
    Organ** organ=new Organ*[organSayisi];
    Sistem** sistem=new Sistem*[sistemSayisi];
    int organsayi=0;
    int sistemsayi=0;
    for (int k = 1; k <= dokuSayisi; k++)
    {
        doku[k-1]=new Doku();
        for (int m = 0; m < dosya->satirSayiSayisi[k-1]; m++)
        {
            doku[k-1]->Add(sayilar[k-1][m]);
        }
        if(k%20==0||k==1)
        {
            if(k!=1)
            {
                sistem[sistemsayi]->Add(organ[organsayi]);
                organsayi++;
            }
            organ[organsayi]=new Organ();
        }
        doku[k-1]->RadixSort();
        organ[organsayi]->agac->Add(doku[k-1]);
        if(k%2000==0||k==1) 
        { 
            if(k!=1)
            {
                organizma->Add(sistem[sistemsayi]);
                sistemsayi++;
            }
            sistem[sistemsayi]=new Sistem();
        }
    }
    delete [] sayilar;   
}

// void Kontrol::Yazdir()
// {
//     SistemNode* tempSistem = organizma->sistemHead;
//     OrganNode* tempOrgan;
//     for (int i = 0; i < organizma->length; i++)
//     {
//         tempOrgan=tempSistem->sistem->organHead;
//         for (int j = 0; j < tempSistem->sistem->length; j++)
//         {
//             if (tempOrgan->organ->Dengelimi())
//             {
//                 cout<<" ";
//             }
//             else
//             {
//                 cout<<"#";
//             }
//             tempOrgan=tempOrgan->next;
//         }
//         cout<<endl;
//         tempSistem=tempSistem->next;
//     }
// }



void Kontrol::Yazdir()
{
    SistemNode* tempSistem=organizma->sistemHead;
    OrganNode* tempOrgan=tempSistem->sistem->organHead;

    for (int i = 0; i < tempSistem->sistem->length; i++)
    {
        cout<<tempOrgan->organ->agac->kok->doku->Ortanca();
        cout<<endl;
        tempOrgan=tempOrgan->next;

    }
    

}

