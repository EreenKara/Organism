/*
* @filee DosyaOkuma.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

#include "DosyaOkuma.hpp"
DosyaOkuma::DosyaOkuma(string dosyaYolu)  // dosyayolunda bir dosya var mı yok mu kontrol et
{
    this->dosyaYolu=dosyaYolu;
    satirSayisi=0;
    string yazi="";
    Read.open(dosyaYolu,ios::in);
    while(!Read.eof())
    {
        getline(Read,yazi);
        satirSayisi++;
    }
    Read.close();
    satirSayiSayisi=new int[satirSayisi];
}
int* DosyaOkuma::BelirliBirSatir(int satirNumarasi)
{
    string yazi="";
    int satirdakiSayiSayisi=0;
    Read.open(dosyaYolu,ios::in);
    for (int i = 0; i < satirNumarasi; i++)
    {
        getline(Read,yazi);
    }
    for (int i = 0; i < yazi.length(); i++)
    {
        if (yazi==" ")
        {
            satirdakiSayiSayisi++;
        }
    }
    int* sayilar=new int[satirdakiSayiSayisi];
    for (int i = 0; i < satirdakiSayiSayisi; i++)
    {
        sayilar[i] = stoi(yazi.substr(0, yazi.find(" ")));    // stoi fonksiyonu stringi integer'a çeviriyor.
        yazi = yazi.substr(yazi.find(" ")+1, yazi.length());  // substr belirli bir noktadan baslayarak verilen sayi kadar ilerliyor ve onu donduruyor.
    }
    Read.close();
    return sayilar;
}

int** DosyaOkuma::Oku()  //döndürdüğü adresin alanını geri bırakmıyor bu yüzden eğer bunu kullandıktan sonra işin biterse bunu sil
{
    string yazi="";
    int satirdakiSayiSayisi=0;
    int** sayilar=new int*[satirSayisi];
    Read.open(dosyaYolu,ios::in);
    for (int i = 0; i < satirSayisi; i++)
    {
        satirdakiSayiSayisi=0;
        getline(Read,yazi);
        istringstream iss(yazi);
        istringstream isss(yazi);
        string sayi="";
        for(int j=0;getline(iss,sayi,' ');j++)
        {
            satirdakiSayiSayisi++;
        }
        sayilar[i]=new int[satirdakiSayiSayisi];
        this->satirSayiSayisi[i]=satirdakiSayiSayisi;  //
        
        for(int j=0;getline(isss,sayi,' ');j++)
        {
            sayilar[i][j]=stoi(sayi);
        }
    }
    Read.close();
    return sayilar;
}

DosyaOkuma::~DosyaOkuma()
{
    delete[] satirSayiSayisi;
}


