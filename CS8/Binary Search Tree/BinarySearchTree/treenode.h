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
public:
    TreeNode();
    TreeNode<T>(T Item);
    TreeNode<T> *&Left();
    TreeNode<T> *&Right();
    void SetItem(const T& Item);
    T returnItem();
    ~TreeNode();
};
template<typename T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    item = T();
}

template<typename T>
TreeNode<T>::TreeNode(T Item){
    item = Item;
    left = NULL;
    right = NULL;
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
