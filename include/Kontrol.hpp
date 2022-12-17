#ifndef Kontrol_hpp
#define Kontrol_hpp
#include "Organizma.hpp"
#include "DosyaOkuma.hpp"
class Kontrol
{
private:
    Organizma* organizma;
    DosyaOkuma* dosya;
public:
    Kontrol(string dosyaYolu);
    void OrganizmayiOlustur();
    ~Kontrol();
};

#endif