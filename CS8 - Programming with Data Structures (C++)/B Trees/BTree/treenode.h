#ifndef TREENODE
#define TREENODE
#include <iostream>
using namespace std;

template<typename T>
class TreeNode{
private:
    T item;
    T item2;
    T overflow;
    TreeNode<T> * left;
    TreeNode<T> * middle;
    TreeNode<T> * right;
public:
    TreeNode();
    TreeNode<T>(T Item);
    TreeNode<T>(T Item, T Item2);
    TreeNode<T>(T Item, T Item2, T Overflow);
    TreeNode<T> *&Left();
    TreeNode<T> *&Middle();
    TreeNode<T> *&Right();
    void SetItem(const T& Item);
    void SetItem2(const T& Item);
    void SetOverflowItem(const T& Item);
    T returnItem1();
    T returnItem2();
    T returnOverflow();
    ~TreeNode();

};
template<typename T>
TreeNode<T>::TreeNode(){
    left = NULL;
    middle = NULL;
    right = NULL;
    item = T();
    item2 = T();
    overflow =T();
}

template<typename T>
TreeNode<T>::TreeNode(T Item){
    item = Item;
    item2 = T();
    overflow = T();
    left = NULL;
    middle = NULL;
    right = NULL;
}

template<typename T>
TreeNode<T>::TreeNode(T Item, T Item2){
    item = Item;
    item2 = Item2;
    overflow = T();
    left = NULL;
    middle = NULL;
    right = NULL;
}

template<typename T>
TreeNode<T>::TreeNode(T Item, T Item2, T Overflow){
    item = Item;
    item2 = Item2;
    overflow = Overflow;
    left = NULL;
    middle = NULL;
    right = NULL;
}

template<typename T>
TreeNode<T>*& TreeNode<T>::Left()
{
    return left;
}

template<typename T>
TreeNode<T>*& TreeNode<T>::Middle()
{
    return middle;
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
void TreeNode<T>::SetItem2(const T &Item)
{
    item2 = Item;
}

template<typename T>
void TreeNode<T>::SetOverflowItem(const T &Item)
{
    overflow = Item;
}

template<typename T>
T TreeNode<T>::returnItem1()
{
    return item;
}

template<typename T>
T TreeNode<T>::returnItem2()
{
    return item2;
}

template<typename T>
T TreeNode<T>::returnOverflow(){
    return overflow;
}

template<typename T>
TreeNode<T>::~TreeNode()
{
    left = NULL;
    middle = NULL;
    right = NULL;
}
#endif // TREENODE
