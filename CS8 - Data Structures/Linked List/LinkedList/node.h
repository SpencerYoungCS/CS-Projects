#ifndef NODE
#define NODE

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template<typename T>
class node{
public:
    T item;
    node<T>* next;

};

#endif // NODE
