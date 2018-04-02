#include "node.h"
#include <iostream>
#ifndef ITERATOR_H
#define ITERATOR_H

using namespace std;

template <class T>
class Iterator
{
private:
    node<T>* p;
public:
    friend class List<T>;
    bool IsNull();
    Iterator ();
    Iterator (node<T> *ptr);
    Iterator (const Iterator<T> &ptr);
    int operator * ();
    bool operator == (const Iterator<T>& ptr) const; //point to same address
    Iterator& operator ++(); //prefix ++
    Iterator operator  ++(int); //postfix ++

};

#endif // ITERATOR_H
