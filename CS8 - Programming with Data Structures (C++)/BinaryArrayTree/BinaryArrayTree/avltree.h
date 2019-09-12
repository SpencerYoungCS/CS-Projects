#ifndef AVLTREE
#define AVLTREE
#include "treenode.h"


template<typename T>
class AVLtree{
private:
    TreeNode<T>* root;
    int binaryArray[100];


    //-------------THESE ARE PRIVATE FUNCTIONS TO MAKE IT EASIER FOR THE USER------------
    void PrivatePreOrder(TreeNode<T> *node);
    void PrivatePostOrder(TreeNode<T> *node);
    void PrivateInOrder(TreeNode<T> *node);
    TreeNode<T> *PrivateInsert(T item, TreeNode<T> *node);
    void PrivateRemove(TreeNode<T> *&node);
    bool PrivateSearch(T item, TreeNode<T> *node);
    TreeNode<T> *&PrivateFind(T item, TreeNode<T> *&node);
    T PrivateParent(T item, TreeNode<T>* node); //this will help my remove function as i need to know the parent
    T PrivateSmallest(TreeNode<T>*& node);
    void RemoveSmallestRightChild(TreeNode<T>*& node);
    int privateSize(TreeNode<T>* node);

    //----------------------------------------------------------------------------

public:
    //-----------------------------THESE ARE FOR 10.4--------------------------------
    void Privatesetlocation(TreeNode<T>* node, bool location[]);
    int operator [](int location);
    int size();



    //-------------------------------------------------------------------------------

    //     void PrivateDelete(TreeNode<T>*& node);
    void EraseAll();
    AVLtree();
    AVLtree(TreeNode<T> StartingRoot);
    void insert(T item);
    void remove(T item);
    bool search(T item);


    //-------------------------------MY OWN FUNCTIONS TO MAKE THINGS EASIER-------------------
    TreeNode<T> *&find(T item);
    T Parent(T item);
    T TotalChildren(TreeNode<T> *node);
    T Smallest();

    //------------THESE ARE MY PRINT FUNCTIONS!!------------------------------------
    void inOrder();
    void postOrder();
    void preOrder();

    //----------------------------LOOK HERE, SPECIAL CASES FOR MAKING AN AVL TREE------------------------

    int ReturnOffset(TreeNode<T> *node);
    int ReturnGreater(int x, int y);
    int getBalance(TreeNode<T> *node);
    TreeNode<T>* rightRotate(TreeNode<T> *node);
    TreeNode<T>* leftRotate(TreeNode<T> *node);


};


//------------------------------------AVL SPECIFIC FUNCTIONS---------------------------------------------
//So the reason why I put this in for AVL is cause now i need to know the how tall a branch is and if
//the difference between two branches from a parent is greater than 1, then I will have to apply a rotation
template<typename T>
int AVLtree<T>::ReturnOffset(TreeNode<T> *node){
    if (!node)
        return 0;
    return node->returnOffset();
}

//This will help determine which brancher has a greater offset by return the larger value
template<typename T>
int AVLtree<T>::ReturnGreater(int x, int y){
    return (x > y)? x : y;
}
//Using our Offset integer, we can subtract the two offsets to determine if the difference is greater than 1
template<typename T>
int AVLtree<T>::getBalance(TreeNode<T> *node)
{
    if (!node)
        return 0;
    else if(!node->Left()){
        if(!node->Right())
            return 0;
        return (0 - node->Right()->returnOffset());
    }
    else if(!node->Right())
        return (node->Left()->returnOffset()- 0);
    else
        return (node->Left()->returnOffset()- node->Right()->returnOffset());
    //    return (ReturnOffset(node->Left()) - ReturnOffset(node->Right()));
}

template<typename T>
TreeNode<T>* AVLtree<T>::rightRotate(TreeNode<T> *node){
    TreeNode<T> *NewNode = node->Left();
    TreeNode<T> *NewNode2 = NewNode->Right();

    // Perform rotation
    NewNode->Right() = node;
    node->Left() = NewNode2;

    // Update offset
    if(!node->Left()){//the reason for the portion is simply so it doesnt try to look into a null
        if(!node->Right()){
            node->SetOffset(1);
        }
        else
            node->SetOffset(node->Right()->returnOffset()+1);
    }
    else if(!node->Right())
        node->SetOffset(node->Left()->returnOffset()+1);
    else
        node->SetOffset(ReturnGreater(node->Left()->returnOffset(), node->Right()->returnOffset())+1);
    if(!NewNode->Left()){
        if(!NewNode->Right())
            NewNode->SetOffset(1);
        else
            NewNode->SetOffset(NewNode->Right()->returnOffset()+1);
    }
    else if(!NewNode->Right())
        NewNode->SetOffset(NewNode->Left()->returnOffset()+1);
    else
        NewNode->SetOffset(ReturnGreater(NewNode->Left()->returnOffset(), NewNode->Right()->returnOffset())+1);
    //        NewNode->SetOffset(ReturnGreater(NewNode->Left()->returnOffset(), NewNode->Right()->returnOffset())+1);
    //update root
    return NewNode;

}


template<typename T>
TreeNode<T>* AVLtree<T>::leftRotate(TreeNode<T> *node){
    TreeNode<T> *NewNode = node->Right();
    TreeNode<T> *NewNode2 = NewNode->Left();

    // Perform rotation
    NewNode->Left() = node;
    node->Right() = NewNode2;

    // Update offset
    if(!node->Left()){//the reason for the portion is simply so it doesnt try to look into a null
        if(!node->Right()){
            node->SetOffset(1);
        }
        else
            node->SetOffset(node->Right()->returnOffset()+1);
    }
    else if(!node->Right())
        node->SetOffset(node->Left()->returnOffset()+1);
    else
        node->SetOffset(ReturnGreater(node->Left()->returnOffset(), node->Right()->returnOffset())+1);
    if(!NewNode->Left()){
        if(!NewNode->Right())
            NewNode->SetOffset(1);
        else
            NewNode->SetOffset(NewNode->Right()->returnOffset()+1);
    }
    else if(!NewNode->Right())
        NewNode->SetOffset(NewNode->Left()->returnOffset()+1);
    else
        NewNode->SetOffset(ReturnGreater(NewNode->Left()->returnOffset(), NewNode->Right()->returnOffset())+1);
    //        NewNode->SetOffset(ReturnGreater(NewNode->Left()->returnOffset(), NewNode->Right()->returnOffset())+1);
    //update root
    return NewNode;
}

//---------------------------------AVL SPECIFIC FUNCTIONS END-------------------------------------

template<typename T>
AVLtree<T>::AVLtree()
{
    root = NULL;
}

template<typename T>
AVLtree<T>::AVLtree(TreeNode<T> StartingRoot)
{
    root = StartingRoot;
}

template<typename T>
void AVLtree<T>::insert(T item)
{
//---------------------ARRAYS STUFF---------------------------------------
    binaryArray[size()] = item;

//------------------------------------------------------------------------

    root = PrivateInsert(item, root);

}

template<typename T>
void AVLtree<T>::remove(T item)
{
    if(search(item)){
        PrivateRemove(find(item));// here i will use my find function to find what the user wanted to delete.
    }
    else
        cout << "Item does not exist!" << endl;
}
template<typename T>
bool AVLtree<T>::search(T item){
    return PrivateSearch(item, root);
}

template<typename T>
TreeNode<T> *&AVLtree<T>::find(T item){
    return PrivateFind(item, root);
}
template<typename T>
T AVLtree<T>::Parent(T item){
    return PrivateParent(item, root);
}
template<typename T>
T AVLtree<T>::TotalChildren(TreeNode<T> *node){//this will return me the number of children a node has
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
T AVLtree<T>::Smallest(){
    return PrivateSmallest(root);
}

template<typename T>
void AVLtree<T>::preOrder(){
    cout << "PreOrder: ";
    PrivatePreOrder(root);
    cout << endl;
}
template<typename T>
void AVLtree<T>::inOrder(){
    cout << "In Order: ";
    PrivateInOrder(root);
    cout << endl;
}

template<typename T>
void AVLtree<T>::postOrder(){
    cout << "Post Order: ";
    PrivatePostOrder(root);
    cout << endl;
}



template<typename T>
TreeNode<T>* AVLtree<T>::PrivateInsert(T item, TreeNode<T>* node)
{
    if(!node){
        return node = new TreeNode<T>(item);
    }
    if(item < node->returnItem())
        node->Left() = PrivateInsert(item, node->Left());
    else
        node->Right() = PrivateInsert(item, node->Right());
    //-------------------THIS WILL UPDATE THE NODE'S OFFSET-------------------------
    if(!node->Left()){
        if(!node->Right())
            node->SetOffset(1);
        node->SetOffset(ReturnGreater(0, node->Right()->returnOffset())+1);
    }
    else if(!node->Right())
        node->SetOffset(ReturnGreater(node->Left()->returnOffset(), 0)+1);
    else
        node->SetOffset(ReturnGreater(node->Left()->returnOffset(), node->Right()->returnOffset())+1);
    //	node->SetOffset(ReturnGreater(node->Left()->returnOffset(),node->Right()->returnOffset()) + 1);

    //so basically im setting the offset to which ever returns the greater offset, then adding 1 to it.
    int offset = getBalance(node);

    //    cout << "getBalance: " << offset <<  endl;

    //-------------------------AVL ROTATIONS--------------------------------------
    //here are initializations as i will need 2 node holders for each rotation
    //There are 4 cases of rotations

    if (offset > 1 && item < node->Left()->returnItem()){//if the offset is left heavy, and item is less than left item;
        //            node = rightRotate(node);
        //        cout << "Left Left Case" << endl;
        return rightRotate(node);
    }


    // Right Right Case
    if (offset < -1 && item > node->Right()->returnItem()){ //if offset is right heavy, and item is greater that right item
        //            node = leftRotate(node);
        //        cout << "Right Right Case" << endl;
        return leftRotate(node);
    }

    // Left Right Case
    if (offset > 1 && item > node->Left()->returnItem()) //left heavy, and item is greater than left item
    {
        //        cout << "Left Right Case" << endl;
        node->Left() =  leftRotate(node->Left());
        //            node = rightRotate(node);
        return rightRotate(node);

    }

    // Right Left Case
    if (offset < -1 && item < node->Right()->returnItem()) // right heavy, and item is less than less than right item
    {
        cout << "Right Left Case" << endl;
        node->Right() = rightRotate(node->Right());
        //            node = leftRotate(node);
        return leftRotate(node);
    }

    //---------------------------------BINARY ARRAY----------------------------------------------




    //-------------------------------------------------------------------------------------------

    return node;
}

template<typename T>
T AVLtree<T>::PrivateParent(T item, TreeNode<T> *node){

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
void AVLtree<T>::PrivateRemove(TreeNode<T> *&node){
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
bool AVLtree<T>::PrivateSearch(T item, TreeNode<T> *node){
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
void AVLtree<T>::PrivatePreOrder(TreeNode<T> * node){
    if (!node) {
    }
    else {
        cout << node->returnItem() << " ";
        PrivatePreOrder(node->Left()); //recursively go left always
        PrivatePreOrder(node->Right()); //then right
    }
}

template<typename T>
void AVLtree<T>::PrivateInOrder(TreeNode<T> *node){
    if(!node){
    }
    else{
        PrivateInOrder(node->Left());
        cout << node->returnItem() << " ";
        PrivateInOrder(node->Right());
    }
}

template<typename T>
void AVLtree<T>::PrivatePostOrder(TreeNode<T> *node){
    if(!node){
    }
    else{
        PrivatePostOrder(node->Left());
        PrivatePostOrder(node->Right());
        cout << node->returnItem() << " ";
    }
}
template<typename T>
TreeNode<T> *&AVLtree<T>::PrivateFind(T item, TreeNode<T> *&node){
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
void AVLtree<T>::EraseAll(){
    root = NULL;
}

template<typename T>
T AVLtree<T>::PrivateSmallest(TreeNode<T>*& node){
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
void AVLtree<T>::RemoveSmallestRightChild(TreeNode<T>*& node){
    //    PrivateRemove(find(PrivateSmallest(node->Right()))); //call private remove, to remove the smallest
    //    cout << node->Right()->returnItem() << endl;
    PrivateRemove(PrivateFind(PrivateSmallest(node->Right()),node->Right()));

}


//---------------------------------FUNCTIONS FOR 10.4---------------------------------

template<typename T>
void AVLtree<T>::Privatesetlocation(TreeNode<T> *node, bool location[]){
if (!node) {
//    location ++;
    }
    else {
//        cout << node->returnItem() << " ";
//    	node->setIsPresent(true);
//        location[0]
//        Privatesetlocation(node->Left()); //recursively go left always
//        Privatesetlocation(node->Right()); //then right
}
}
template<typename T>
int AVLtree<T>::operator [](int location){
return binaryArray[location];
}

//i need something to traverse the tree based on an integer.
//template<typename T>//location is where we want to start
//TreeNode<T> AVLtree<T>::traverse(TreeNode<T> *node, int location, int start){
//    TreeNode<T>* NULLPTR = NULL;

//}
template <typename T>
int AVLtree<T>::size(){
    return privateSize(root);
}

template <typename T>
int AVLtree<T>::privateSize(TreeNode<T>* node){
if (!node)
    return(0);
  else {
    return(privateSize(node->Left()) + 1 + privateSize(node->Right()));
  }
}

#endif // AVLTREE

