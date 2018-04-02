#include "node.h"
#include <iostream>
#ifndef ITERATOR_H
#define ITERATOR_H

using namespace std;

class Iterator
{
private:
    node* p;
public:
    friend class List;
    bool IsNull();
    Iterator ();
    Iterator (node *ptr);
    Iterator (const Iterator &ptr);
    int operator * ();
    bool operator == (const Iterator& ptr) const; //point to same address
    Iterator& operator ++(); //prefix ++
    Iterator operator  ++(int); //postfix ++

};

#endif // ITERATOR_H
