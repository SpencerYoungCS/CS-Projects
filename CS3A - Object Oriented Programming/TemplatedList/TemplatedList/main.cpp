#include <iostream>
#include "list.h"

using namespace std;

int main(){

    List<int> A;
    A.inserthead(3);
    A.inserthead(6);
    A.insertAfter(A.search(6), 1);
    A.inserthead(2);
    A.inserthead(9);
    A.inserthead(7);
    A.printlist();

    List<string> As;
    As.inserthead("First");
    As.inserthead("Second");
    As.printlist();

    return 0;
}

