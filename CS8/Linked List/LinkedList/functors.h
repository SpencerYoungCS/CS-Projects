#ifndef FUNCTORS
#define FUNCTORS
#include "pair.h"

//This is used for Frequency's Insert.
template<typename T>
class Inc{
public:
    bool operator()(node<T>* P){P->item.inc(); return true;}
};

template<typename T>
class DoNothing{
public:
    bool operator()(node<T>* P){return true;}
};
//this will make print function easy to use------------------------
template<typename T>
class PrintPair{
public:
    ostream& operator()(node<T>* P){return
                        cout <<"[" << P->item.item << "|" << P->item.UniqueValue << "] ";}
};
template<typename T>
class GetItem{
public:
    ostream& operator()(node<T>* P){return
                        cout <<"[" << P->item << "] ";}
};

//-------------------------------------------
#endif // FUNCTORS

