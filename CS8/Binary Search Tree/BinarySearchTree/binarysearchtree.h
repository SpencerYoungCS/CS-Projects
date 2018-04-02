#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
#include "treenode.h"

template<typename T>
class BinarySearchTree{
private:
    TreeNode<T>* root;
    //-------------THESE ARE PRIVATE FUNCTIONS TO MAKE IT EASIER FOR THE USER------------
    void PrivatePreOrder(TreeNode<T> *node);
    void PrivatePostOrder(TreeNode<T> *node);
    void PrivateInOrder(TreeNode<T> *node);
    void PrivateInsert(T item, TreeNode<T> *&node);
    void PrivateRemove(TreeNode<T> *&node);
    bool PrivateSearch(T item, TreeNode<T> *node);
    TreeNode<T> *&PrivateFind(T item, TreeNode<T> *&node);
    T PrivateParent(T item, TreeNode<T>* node); //this will help my remove function as i need to know the parent
    T PrivateSmallest(TreeNode<T>*& node);
    void RemoveSmallestRightChild(TreeNode<T>*& node);


    //----------------------------------------------------------------------------
public:
    //     void PrivateDelete(TreeNode<T>*& node);
    void EraseAll();
    BinarySearchTree();
    BinarySearchTree(TreeNode<T> StartingRoot);
    void insert(T item);
    void remove(T item);


    //-------------------------------MY OWN FUNCTIONS TO MAKE THINGS EASIER-------------------
    TreeNode<T> *&find(T item);
    T Parent(T item);
    T TotalChildren(TreeNode<T> *node);
    T Smallest();

    //------------THESE ARE MY PRINT FUNCTIONS!!------------------------------------
    void inOrder();
    void postOrder();
    void preOrder();
    bool search(T item);
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(TreeNode<T> StartingRoot)
{
    root = StartingRoot;
}

template<typename T>
void BinarySearchTree<T>::insert(T item)
{
    PrivateInsert(item, root);
}

template<typename T>
void BinarySearchTree<T>::remove(T item)
{
    if(search(item)){
        PrivateRemove(find(item));// here i will use my find function to find what the user
    }
    else
        cout << "Item does not exist!" << endl;
}
template<typename T>
bool BinarySearchTree<T>::search(T item){
    return PrivateSearch(item, root);
}

template<typename T>
TreeNode<T> *&BinarySearchTree<T>::find(T item){
    return PrivateFind(item, root);
}
template<typename T>
T BinarySearchTree<T>::Parent(T item){
    return PrivateParent(item, root);
}
template<typename T>
T BinarySearchTree<T>::TotalChildren(TreeNode<T> *node){
    if(!node){
        return 0;
    }

    if(node->Left() && node->Right())
        return 2;
    else if(!node->Left() && !node->Right())
        return 0;
    return 1;
}

template<typename T>
T BinarySearchTree<T>::Smallest(){
    return PrivateSmallest(root);
}

template<typename T>
void BinarySearchTree<T>::preOrder(){
    cout << "PreOrder: ";
    PrivatePreOrder(root);
    cout << endl;
}
template<typename T>
void BinarySearchTree<T>::inOrder(){
    cout << "In Order: ";
    PrivateInOrder(root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::postOrder(){
    cout << "Post Order: ";
    PrivatePostOrder(root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::PrivateInsert(T item, TreeNode<T>*& node)
{
    if(!node){
        node = new TreeNode<T>(item);
    }
    else{
        if(item < node->returnItem())
            PrivateInsert(item, node->Left());
        else
            PrivateInsert(item, node->Right());
    }
}

template<typename T>
T BinarySearchTree<T>::PrivateParent(T item, TreeNode<T> *node){

    //returns 0 when there is no parent or it doesnt exist
    if(PrivateSearch(item, node)){
        if(!node){}
        if(node->returnItem() == item)
            return 0;
        else if(!node->Right() && !node->Left())//MAKE SURE AT LEAST 1 CHILD EXIST---------------
            return 0;
        //-----THESE WILL MAKE SURE IT DOESNT TRY TO EVALUATE A NULL------------
        else if(!node->Right()){
            if(node->Left()->returnItem() == item)
                return node->returnItem();
            else if(item < node->returnItem()){
                return PrivateParent(item, node->Left());
            }
        }
        else if(!node->Left())
        {
            if(node->Right()->returnItem() == item)
                return node->returnItem();
            else if(item > node->returnItem()){
                return PrivateParent(item,node->Right());
            }
        }
        //------------------NORMAL EVALUATION ASSUMING BOTH CHILDREN EXIST--------------------------

        else if(node->Left()->returnItem() == item)
            return node->returnItem();
        else if(node->Right()->returnItem() == item){
            return node->returnItem();
        }

        //------------------ACTUAL RECURSION HERE---------------------------------
        if(PrivateParent(item,node->Left()))
            return PrivateParent(item,node->Left());
        if(PrivateParent(item,node->Right()))
            return PrivateParent(item,node->Right());
    }
    else{
        //        cout << "item does not exist" << endl;
        return 0;
    }
    return 0;
}

template<typename T>
void BinarySearchTree<T>::PrivateRemove(TreeNode<T> *&node){
    if(!TotalChildren(node)){
        //        cout << "This has no children, just kill it" << endl;
        //        cout  << "Parent: " << find(Parent(node->returnItem()))->returnItem() << endl;
        node = NULL;
    }
    else if(TotalChildren(node) == 1){
        if(!node->Left())
        {
            if(root == node)
                root = node;
            else if(find(Parent(node->returnItem()))->Left() == node){
                find(Parent(node->returnItem()))->Left() = node->Right(); //SET PARENT TO CHILD'S CHILD
            }
            else if(find(Parent(node->returnItem()))->Right() == node){
                find(Parent(node->returnItem()))->Right() = node->Right(); //SET PARENT TO CHILD'S CHILD
            }
        }
        else {
            if(root == node)
                root = node;
            else if(find(Parent(node->returnItem()))->Left() == node){
                find(Parent(node->returnItem()))->Left() = node->Left();
            }
            else if(find(Parent(node->returnItem()))->Right() == node){
                find(Parent(node->returnItem()))->Right() = node->Left(); //SET PARENT TO CHILD'S CHILD
            }
        }
    }
    else{
        node->SetItem(PrivateSmallest(node->Right()));
//        cout << node->returnItem() << endl;
        RemoveSmallestRightChild(node);
    }
}
template<typename T>
bool BinarySearchTree<T>::PrivateSearch(T item, TreeNode<T> *node){
    if(!node){
        return false;
    }
    if(item == node->returnItem())
        return true;
    else if(item < node->returnItem()){
        if(!node->Left())
            return false;
        else
            return PrivateSearch(item, node->Left());
    }
    else if(item > node->returnItem()){
        if(!node->Right())
            return false;
        else
            return PrivateSearch(item,node->Right());
    }
    return false;
}

template<typename T>
void BinarySearchTree<T>::PrivatePreOrder(TreeNode<T> * node){
    if (!node) {
    }
    else {
        cout << node->returnItem() << " ";
        PrivatePreOrder(node->Left()); //recursively go left always
        PrivatePreOrder(node->Right()); //then right
    }
}

template<typename T>
void BinarySearchTree<T>::PrivateInOrder(TreeNode<T> *node){
    if(!node){
    }
    else{
        PrivateInOrder(node->Left());
        cout << node->returnItem() << " ";
        PrivateInOrder(node->Right());
    }
}

template<typename T>
void BinarySearchTree<T>::PrivatePostOrder(TreeNode<T> *node){
    if(!node){
    }
    else{
        PrivatePostOrder(node->Left());
        PrivatePostOrder(node->Right());
        cout << node->returnItem() << " ";
    }
}
template<typename T>
TreeNode<T> *&BinarySearchTree<T>::PrivateFind(T item, TreeNode<T> *&node){
    TreeNode<T>* NULLPTR = NULL;
    if(!node){
        //      node = NULL;
        return NULLPTR;
        exit(0);

    }
    if(item == node->returnItem())
        return node;
    else if(item < node->returnItem()){
        if(!node->Left())
            return NULLPTR;
        else
            return PrivateFind(item, node->Left());
    }
    else if(item > node->returnItem()){
        if(!node->Right())
            return NULLPTR;
        else
            return PrivateFind(item,node->Right());
    }
    return NULLPTR;

}

template<typename T>
void BinarySearchTree<T>::EraseAll(){
    root = NULL;
}

template<typename T>
T BinarySearchTree<T>::PrivateSmallest(TreeNode<T>*& node){
    if (!node) {
    }
    else {
        if(!node->Left())
            return node->returnItem();
        return PrivateSmallest(node->Left()); //recursively go left always
        //        return node->returnItem();
    }
}

template<typename T>
void BinarySearchTree<T>::RemoveSmallestRightChild(TreeNode<T>*& node){
    //    PrivateRemove(find(PrivateSmallest(node->Right()))); //call private remove, to remove the smallest
    //    cout << node->Right()->returnItem() << endl;
    PrivateRemove(PrivateFind(PrivateSmallest(node->Right()),node->Right()));

}
#endif // BINARYSEARCHTREE
