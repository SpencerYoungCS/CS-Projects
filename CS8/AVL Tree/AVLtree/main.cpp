#include <iostream>
#include "avltree.h"

using namespace std;

int main()
{
AVLtree<int> A;

    A.insert(3);
    A.preOrder();
//    A.insert(4);
    A.insert(2);
    A.preOrder();
//    A.insert(5);
    A.preOrder();

    A.insert(1);
    A.preOrder();
    A.insert(8);
    A.preOrder();
    A.insert(10);
    cout << "----------------------Print Tests------------------------" << endl;
    A.preOrder();
    cout << "--------------------Smallest Test----------------------------------" << endl;
    cout << "Smallest is: " <<  A.Smallest() << endl;
    cout << "Removing Smallest... " << endl;
    A.remove(A.Smallest());
    cout << "Smallest is: " << A.Smallest() << endl;
    cout << "Removing Smallest... " << endl;
    A.remove(A.Smallest());
    cout << "Smallest is: " << A.Smallest() << endl;
    cout << "Removing Smallest... " << endl;
    A.remove(A.Smallest());
    cout << "Smallest is: " << A.Smallest() << endl;
    A.remove(A.Smallest());
    A.remove(A.Smallest());
    A.remove(A.Smallest());
    A.remove(A.Smallest());
    cout << "Smallest is: " << A.Smallest() << endl; //making sure it doesnt collapse on itself

    cout << "--------------------Two Child remove test----------------------------------" << endl;
    A.preOrder();
    cout << "Removing 5...." << endl;
    A.remove(5);
    A.preOrder();
    cout << endl;
    cout << "-----------------------Final Testing!----------------------------------------" << endl;
    A.EraseAll();
    A.insert(25);
    A.insert(17);
    A.insert(16);
    A.insert(20);
    A.insert(19);
    A.insert(21);
    A.insert(29);
    A.insert(28);
    A.insert(32);
    A.insert(31);
    A.insert(33);
    A.preOrder();
    A.remove(25);
    A.preOrder();
    A.remove(17);
    A.remove(33);
    A.remove(8);
    A.preOrder();

}

