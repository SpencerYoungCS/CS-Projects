#ifndef TREENODE
#define TREENODE
#include <iostream>
using namespace std;

template<typename T>
class TreeNode{
private:
    T item;
    TreeNode<T> * left;
    TreeNode<T> * right;
    int OffsetCounter;
public:
    TreeNode();
    TreeNode<T>(T Item);
    TreeNode<T> *&Left();
    TreeNode<T> *&Right();
    void SetItem(const T& Item);
    void SetOffset(const int& newCounter);
    T returnItem();
    int returnOffset();
    ~TreeNode();
};
template<typename T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    item = T();
    OffsetCounter = 1;
}

template<typename T>
TreeNode<T>::TreeNode(T Item){
    item = Item;
    left = NULL;
    right = NULL;
    OffsetCounter = 1;
}

template<typename T>
void TreeNode<T>::SetOffset(const int &newCounter){
    OffsetCounter = newCounter;
}


template<typename T>
TreeNode<T>*& TreeNode<T>::Left()
{
    return left;

}

template<typename T>
TreeNode<T>*& TreeNode<T>::Right()
{
    return right;
}
template<typename T>
void TreeNode<T>::SetItem(const T &Item)
{
    item = Item;
}

template<typename T>
int TreeNode<T>::returnOffset(){
   return OffsetCounter;
}
template<typename T>
T TreeNode<T>::returnItem()
{
    return item;
}

template<typename T>
TreeNode<T>::~TreeNode()
{
    left = NULL;
    right = NULL;
}
#endif // TREENODE

