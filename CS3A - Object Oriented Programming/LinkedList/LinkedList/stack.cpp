#include "stack.h"

Stack::Stack():List(){
}

Stack::Stack(List A):List(A){

}
void Stack::Push(int i){
    inserthead(i);
}

void Stack::Pop(){
    Remove(gethead());
}

int Stack::Top(){
    return getitem();
}

bool Stack::IsEmpty(){
    if(gethead() == NULL){
        return true;
    }
    return false;
}
