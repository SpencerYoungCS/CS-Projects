#ifndef HEAP
#define HEAP
#include <iostream>
#include "heapnode.h"

using namespace std;

class Heap{
private:
    HeapNode* node;

    int TotalItems;              // items in the heap
    int HeapLength;               // Size of the array
    bool PrivateInsert(HeapNode *item);  //The function user will not touch

public:
    Heap(int size);
    ~Heap();
    void ReheapDown(int root, int bottom);   // recursive heap downwards
    void ReheapUp(int root, int bottom);     // recursive heap upward
    bool Insert(int item);
    HeapNode *DeleteFirst();                     // Deletes the first item
    int getTotalItems();
    //--------------------------print functions------------------
    void print();
    void printArray();
    //-----------------------------------------------------
};

Heap::Heap(int size)
{

//    int size = 10;
    // Create heap of given size
    node = new HeapNode[size];
    TotalItems = 0;
    HeapLength = size;
}

Heap::~Heap()
{
    delete[] node;
}

void Heap::ReheapDown(int root, int bottom)
{
    int maxChild;
    int rightChild;
    int leftChild;
    HeapNode temp;

    leftChild = root * 2 + 1;          // location of root's left child
    rightChild = root * 2 + 2;          // location of root's right child

    //here i will use recursion to check the index and repeat if index is smaller.
    if(leftChild <= bottom)
    {
        if(leftChild == bottom)
        {
            maxChild = leftChild;//leftChild must hold largest item
        }
        else
        {     // Get the one lowest in the tree
            if(node[leftChild].getItem() <= node[rightChild].getItem())
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if(node[root].getItem() < node[maxChild].getItem())
        {
            temp = node[root];
            node[root] = node[maxChild];
            node[maxChild] = temp;
            ReheapDown(maxChild, bottom);//Recursion
        }
    }
}

void Heap::ReheapUp(int root, int bottom)
{
    int parent;
    HeapNode temp;

    if(bottom > root)
    {
        parent = (bottom -1) / 2;
        if(node[parent].getItem() < node[bottom].getItem())
        {
            temp = node[parent];
            node[parent] = node[bottom];
            node[bottom] = temp;
            ReheapUp(root, parent);//Recursion
        }
    }
}

bool Heap::PrivateInsert(HeapNode *item)
{
    if(TotalItems < HeapLength)
    {
        node[TotalItems] = *item; // Copy item into array
        ReheapUp(0, TotalItems);
        TotalItems++;
        return true;
    }
    return false;
}

bool Heap::Insert(int item)
{
    bool retVal;
    HeapNode *temp = new HeapNode(item);
    retVal = PrivateInsert(temp);
    delete temp;
    return retVal;
}

HeapNode *Heap::DeleteFirst()
{
    HeapNode *temp = new HeapNode(node[0].getItem());
    TotalItems--;
    // Copy last item into root
    node[0] = node[TotalItems];
    ReheapDown(0, TotalItems - 1);
    if(TotalItems == 0)
        return NULL;
    else
        return temp;
}


int Heap::getTotalItems()//return number of items in the heap
{
    return TotalItems;
}

void Heap::print()//this will print each individual item
{
    for(int i=0; i < TotalItems; i++)
    {
        cout << "Item[" << i << "] = " << node[i].getItem() << endl;
    }
}

void Heap::printArray(){

    cout << "Heap array: [ ";
    for(int i = 0; i < TotalItems; i++){
        cout << node[i].getItem() << " ";
    }
    cout << "]" << endl;


}


#endif // HEAP

