#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

class Queue : public List
{
public:
    Queue();
    Queue(List A);
    void EnQueue(int num);
    void DeQueue();
    bool IsEmpty();

};
//A standard Queue class with EnQueue, DeQueue, IsEmpty functions
#endif // QUEUE_H
