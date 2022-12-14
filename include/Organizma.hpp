#ifndef Organizma_hpp
#define Organizma_hpp
#include "SistemNode.hpp"
class Organizma
{
private:
    SistemNode* head;
    int length;
public:
    Organizma();
    void MutasyonaUgra(); // Buradada organdaki mutasyonu ugra fonksiyonunu çağır.
    void Add(Sistem* sistem);
    void Delete();
    ~Organizma();
};


#endif