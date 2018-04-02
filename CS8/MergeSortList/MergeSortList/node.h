#ifndef NODE
#define NODE
#include <iostream>
using namespace std;

template<typename T>
struct node{
    T item;
    node<T>* next;
};

#endif // NODE
