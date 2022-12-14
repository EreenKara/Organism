#ifndef Queue_hpp
#define Queue_hpp
#include "Hucre.hpp"
class Queue
{
private:
    Hucre* front;
    Hucre* back;
    int length;
public:
    Queue();
    int Peek();
    void Enqueue(int veri);
    void Dequeue();

    ~Queue();
};
#endif