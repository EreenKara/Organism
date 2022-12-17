#ifndef Queue_hpp
#define Queue_hpp
#include "Hucre.hpp"
class Kontrol;
class Radix;
class Queue
{
private:
    Hucre* front;
    Hucre* back;
    int length;
    friend Radix;
    friend Kontrol;
public:
    Queue();
    int Peek();
    void Enqueue(int veri);
    void Dequeue();

    ~Queue();
};
#endif