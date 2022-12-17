#ifndef Kontrol_hpp
#define Kontrol_hpp
#include "Organizma.hpp"
#include "DosyaOkuma.hpp"
class Kontrol
{
private:
    Organizma* organizma;
    DosyaOkuma* dosya;
    int dokuSayisi;
    int organSayisi;
    int sistemSayisi;

public:
    Kontrol(string dosyaYolu);
    void OrganizmayiOlustur();
    ~Kontrol();
};

#endif