#include "binarysearchtree.h"

int main()
{
    BinarySearchTree<int> A;

    TreeNode<int> test;
//    if(!test)
//        cout << "its not going to this" << endl;
    A.insert(3);
    A.insert(2);
    A.insert(5);
    A.insert(1);
    A.insert(7);
    A.insert(4);
    A.insert(8);
    A.insert(10);
    cout << "----------------------Print Tests------------------------" << endl;
    A.preOrder();
    A.inOrder();
    A.postOrder();

    //    if(A.search(10))
    //        cout << "found" << endl;
    cout << "--------------------Parent Tests-------------------------------" << endl;

    cout << A.Parent(5) << endl;
    cout << A.Parent(7) << endl;
    cout << A.Parent(4) << endl;
    cout << A.Parent(10) << endl;
    cout << A.Parent(3) << endl;
    cout << "-----------------------Find Tests---------------------------" << endl;
    cout << A.find(10)->returnItem() << endl;
    cout << A.find(4)->returnItem() << endl;
    cout << A.find(7)->returnItem() << endl;
    cout << A.find(2)->returnItem() << endl;
    //    cout << A.find(9)->returnItem() << endl;
    if(A.find(9))
        cout << "9 Exists, it shouldnt" << endl;

    cout << "----------------------Total Children Test----------------" << endl;
    cout << "Total Children of 10: " << A.TotalChildren(A.find(10)) << endl;
    cout << "Total Children of 8: " << A.TotalChildren(A.find(8)) << endl;
    cout << "Total Children of 7: " << A.TotalChildren(A.find(7)) << endl;
    cout << "Total Children of 5: " <<A.TotalChildren(A.find(5)) << endl;
    cout << "Total Children of 3: " << A.TotalChildren(A.find(3)) << endl;

    cout << "-----------------------Remove Test-----------------------" << endl;
    //A.remove(10);
    //cout << "Removing 10: ";
    A.preOrder();
    A.remove(8);
    cout << "Removing 8: ";
    A.preOrder();
    A.remove(7);
    cout << "Removing 7: ";
    A.preOrder();
    A.remove(9);
    cout << "Removing 9: ";
    A.preOrder();
    A.remove(2);
    cout << "Removing 2: ";
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

    return 0;
}
