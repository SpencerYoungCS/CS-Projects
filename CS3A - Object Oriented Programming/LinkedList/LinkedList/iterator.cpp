#include "iterator.h"

Iterator::Iterator(){
    p = NULL;
}

Iterator::Iterator(node *ptr)
{
    p = ptr;
}

Iterator::Iterator(const Iterator &ptr)
{
    p = ptr.p;
}

bool Iterator::IsNull()
{
    if(p == NULL)
        return true;
    return false;
}

int Iterator::operator *()
{
    return p->item;
}

bool Iterator::operator ==(const Iterator &ptr) const
{
    if(p == ptr.p)
        return true;
    return false;
}

Iterator &Iterator::operator ++()
{
    p = p->next;
//    return Iterator(p);/
    return *this;
}

Iterator Iterator::operator ++(int)
{
    Iterator A;
    A.p = this->p;
    p = p->next;
    return A;

}
