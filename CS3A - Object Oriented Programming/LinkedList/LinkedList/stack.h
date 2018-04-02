#include "list.h"
#ifndef STACK_H
#define STACK_H

class Stack : public List{
public:
    Stack();
    Stack(List A);
    void Push(int i);
    void Pop();
    int Top();
    bool IsEmpty();
private:

};

#endif // STACK_H
