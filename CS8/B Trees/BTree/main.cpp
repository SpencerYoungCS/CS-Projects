#include "btree.h"

int main()
{
    //----------------------TESTS!!!!!!!!!!!!!!!!!!!!!!!!!!!!----------------------------------------
    BTree<int> A;
    cout << "inserting 5, 10, 1..." << endl;
    A.insert(5);
    A.insert(10);
    A.insert(1);
    A.preOrder();
    cout << "inserting 3.... " << endl;
    A.insert(3);
    A.preOrder();
    cout << "inserting 4.... " << endl;
    A.insert(4);
    A.preOrder();

    cout << A.find(3)->Middle()->returnItem1() << endl;

    cout << "inserting 7.... " << endl;
    A.insert(7);
    A.preOrder();
    cout << A.TotalChildren(A.find(5)) << endl;
    cout << A.find(5)->Right()->returnItem1() << endl;


//    A.remove(5);
    cout << "Parent of 7 is: " << A.Parent(7) << endl;
    A.preOrder();

//    cout << "inserting 8.... " << endl;
//    A.insert(8);
//    cout << A.find(5)->Right()->Right()->returnItem1() << endl;
    A.preOrder();
//   cout << A.find(5)->Left()->Right()->returnItem1() << endl;

BTree<int> B;
B.insert(5);




//    cout << A.TotalChildren(A.find(3)) << endl;

    return 0;
}

