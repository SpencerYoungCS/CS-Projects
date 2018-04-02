#include "linkedlist.h"

//------------------------INSERTION SORT ALGORHITIM NOW TAKES A LINKED LIST!!!!!!!!!!!!!---------------------------
template<typename T>
void insertionSort(LinkedList<T>& item){
    for (int i = 1; i < item.length(); i++)    {
        int index = item[i]->item;
        int j = i;
        while(j > 0 && item[j-1]->item > index)
        {
            item[j]->item= item[j-1]->item;
            j--;
        }
        item[j]->item = index;
    }
}


int main()
{

    //-----------------------------BARKESHILI!!! LOOK HERE!!! MY TESTS!!!! HERE!!!!!!!!----------------------------------
    LinkedList<int> A;
    A.inserthead(3);
    A.inserthead(5);
    A.inserthead(1);
    A.inserthead(9);
    A.inserthead(12);
    A.inserthead(45);

    cout << "length: " << A.length() << endl;

    cout << "A[0]: " <<  A[0]->item << endl; //making sure my bracket operators work so that they will work in the original insertion sort

    A[1]->item = 3;

    cout << "Before: "; A.printlist(); cout << endl;

    insertionSort(A);

    cout << "After : "; A.printlist(); cout << endl;

    return 0;
}

