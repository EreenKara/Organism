#include "Queue.hpp"
Queue::Queue()
{
    this->front=NULL;
    this->back=NULL;
    this->length=0;
}
int Queue::Peek()
{
    if(length==0) return -1;
    return front->value;
}
void Queue::Enqueue(int veri)
{
    if(length==0) front=back=new Hucre(veri);
    else
    {
        back->next=new Hucre(veri);
        back=back->next;
    }
    length++;
}
void Queue::Dequeue()
{
    if(length==0) return;
    Hucre* del=front;
    if(length==1)
    {
        back=front->next; // zaten front'un next'i NULL olacağından NULL yazmadım. front->next dedim
    }
    front=front->next;
    delete del;
    length--;
}
Queue::~Queue()
{

}