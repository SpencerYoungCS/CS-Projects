#include <iostream>
#include "linkedlist.h"

using namespace std;
//---------------initializations----------------------------
void mergesort(int *a, int low, int high);
void merge(int *,int, int , int );
//----------------------------------------------------------

template<typename T>
void mergesort(LinkedList<T> &A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,low,high,mid);
    }
    return;
}

template<typename T>
void merge(LinkedList<T> &A, int low, int high, int mid) //for simplicity sake, i make an operator for linked lists to take brackets, so
//that the original merge algorhitim would still work. only difference is that i have to call the item in the linked list
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (A[i]->item < A[j]->item)
        {
            c[k] = A[i]->item;
            k++;
            i++;
        }
        else
        {
            c[k] = A[j]->item;
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = A[i]->item;
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = A[j]->item;
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        A[i]->item = c[i];
    }
}


int main()
{

    //--------------------------MERGESORT TEST!!!-------------------------------------
//    int test[5];
//    test[0] = 2;
//    test[1] = 9;
//    test[2] = 4;
//    test[3] = 7;
//    test[4] = 6;
//    test[5] = 1;

//    mergesort(test, 0,5);

//    cout << test[0] << endl;
//    cout << test[1] << endl;
//    cout << test[2] << endl;
//    cout << test[3] << endl;
//    cout << test[4] << endl;
    //----------------------------------------------------------------------------------
    // Basic Merge Sort works now... now attemping linked list implementation---------------

    LinkedList<int> test;

    test.inserthead(5);
    test.inserthead(10);
    test.inserthead(34);
    test.inserthead(23);
    test.inserthead(90);
    test.inserthead(17);
    test.inserthead(12);
    test.inserthead(9);

    cout << "Before Sorted: "; test.printlist(); cout << endl; // before sorting....

    mergesort(test,0, test.length()-1);

    cout << "After Sorted: "; test.printlist(); cout << endl;

    //-----------------------IT NOW TAKES A LINKED LIST AND MERGE SORTS IT----------------------

    return 0;
}
