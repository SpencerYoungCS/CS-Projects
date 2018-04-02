#include "queue.h"

Queue::Queue():List(){

}

Queue::Queue(List A):List(A){

}

void Queue::EnQueue(int num)
{
    insertAfter(getlast(), num);
}

void Queue::DeQueue()
{
    Remove(getlast());
}

bool Queue::IsEmpty()
{
    if(gethead() == NULL)
        return true;
    else
        return false;
}
