#include "Kontrol.hpp"

Kontrol::Kontrol(string dosyaYolu)
{
    organizma=new Organizma();
    dosya = new DosyaOkuma(dosyaYolu);
    dokuSayisi=dosya->satirSayisi;
    organSayisi=(dosya->satirSayisi/20)+1;
    sistemSayisi=(organSayisi/100)+1;
}
void Kontrol::OrganizmayiOlustur()
{
    int** sayilar = dosya->Oku();
    Doku** doku=new Doku*[dosya->satirSayisi];
    Organ** organ=new Organ*[organSayisi];
    Sistem** sistem=new Sistem*[sistemSayisi];
    
    int organsayi=0;
    int sistemsayi=0;
    for (int k = 0; k < dokuSayisi; k++)
    {
        for (int m = 0; m < dosya->satirdakiSayiSayisi[k]; m++)
        {
            doku[k]->Add(sayilar[k][m]);
        }
        organ[organsayi]->agac->Add(doku[k]);
        if(k+1%20==0) 
        {
            sistem[sistemsayi]->Add(organ[organsayi]);
            organsayi++;
        }
        if(k%100==0) 
        {
            organizma->Add(sistem[sistemsayi]);
            sistemsayi++;
        }
    }
    
}