
#include "heap.h"
int main()
{
    //-----------------------------------HEAP TESTING~!!!!---------------------------
    Heap * test = new Heap(100); //here we can dynamically set the array

    test->Insert(2);
    test->Insert(5);
    test->Insert(3);
    test->Insert(9);
    test->Insert(7);
    test->Insert(3);
    test->Insert(1);
    test->Insert(13);
    test->Insert(71);
    test->Insert(4);
    test->Insert(17);
    test->Insert(22);

    test->print();
    test->printArray();

    //--------------------------DELETE TESTING------------------------------

    test->DeleteFirst();
    test->DeleteFirst();
    test->DeleteFirst();
    cout << "Deleting First 3 Items..." << endl; // should delete the largest 3

    test->print();

    return 0;
}

