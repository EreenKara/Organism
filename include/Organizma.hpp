#ifndef Organizma_hpp
#define Organizma_hpp
#include "SistemNode.hpp"
class Kontrol;
class Organizma
{
private:
    SistemNode* sistemHead;
    int length;
    friend Kontrol;
public:
    Organizma();
    void MutasyonaUgra(); // Buradada organdaki mutasyonu ugra fonksiyonunu çağır.
    void Add(Sistem* sistem);
    void Delete();
    ~Organizma();
};


#endif