#ifndef BTREE
#define BTREE
#include "treenode.h"

template<typename T>
class BTree{
private:
    TreeNode<T>* root;


    void PrivateInOrder(TreeNode<T> *node);
    void PrivatePreOrder(TreeNode<T> *node);
    void PrivatePostOrder(TreeNode<T> *node);
    void PrivateInsert(T item,TreeNode<T>*& node);
    T PrivateParent(T item, TreeNode<T>* node); //this will help my remove function as i need to know the parent
    bool PrivateSearch(T item, TreeNode<T> *node);
    TreeNode<T> *&PrivateFind(T item, TreeNode<T> *&node);
    void PrivateInsertOnly(T item, TreeNode<T> *& node);
    T PrivateSmallest(TreeNode<T>*& node);
    void RemoveSmallestRightChild(TreeNode<T>*& node);
    void PrivateRemove(TreeNode<T>*& node);

public:
    BTree();
    BTree(TreeNode<T> StartingRoot);
    void insert(T item);
    void remove(T item);
    int TotalChildren(TreeNode<T> *node);
    void inOrder();
    void preOrder();
    void postOrder();
    //--------------------------Functions for help other functions------------------------------
    T Parent(T item);
    bool search(T item);
    TreeNode<T> *&find(T item);
};

template<typename T>
BTree<T>::BTree(){
    root = NULL;
}
template<typename T>
BTree<T>::BTree(TreeNode<T> StartingRoot){
    root = StartingRoot;
}

template<typename T>
void BTree<T>::insert(T item)
{
    PrivateInsert(item, root);
}

template<typename T>
void BTree<T>::remove(T item){
    if(search(item)){
        PrivateRemove(root);
    }
    cout << "in remove: " << item << " does not exist!";
}

template<typename T>
void BTree<T>::inOrder(){
    cout << "In Order: ";
    PrivateInOrder(root);
    cout << endl;
}

template<typename T>
void BTree<T>::preOrder(){
    cout << "PreOrder: ";
    PrivatePreOrder(root);
    cout << endl;
}

template<typename T>
void BTree<T>::postOrder(){
    cout << "Post Order: ";
    PrivatePostOrder(root);
    cout << endl;
}

template<typename T>
T BTree<T>::Parent(T item){
    return PrivateParent(item, root);
}

template<typename T>
bool BTree<T>::search(T item){
    return PrivateSearch(item, root);
}

template<typename T>
TreeNode<T> *&BTree<T>::find(T item){
    return PrivateFind(item, root);
}

template<typename T>
void BTree<T>::PrivateInOrder(TreeNode<T> *node){

    if(!node){
    }
    else{
        if(node->returnItem1() && node->returnItem2()){
            PrivateInOrder(node->Left());
            cout << "[" << node->returnItem1() <<":" << node->returnItem2() << "]" << " ";
            PrivateInOrder(node->Middle());
            PrivateInOrder(node->Right());
        }
        else{
            PrivateInOrder(node->Left());
            cout << "[" << node->returnItem1() << "]" << " ";
            PrivateInOrder(node->Right());
        }
    }
}

template<typename T>
void BTree<T>::PrivatePreOrder(TreeNode<T> *node){

    if (!node) {
    }
    else {
        if(node->returnOverflow()){
            cout << "[" << node->returnItem1() << ":" << node->returnItem2() << ":" << node->returnOverflow() <<"]"  <<" ";
            PrivatePreOrder(node->Left()); //recursively go left always
            PrivatePreOrder(node->Middle());
            PrivatePreOrder(node->Right()); //then right
        }
        else if(node->returnItem1() && node->returnItem2()){
            cout << "[" << node->returnItem1() << ":" << node->returnItem2() <<"]"  <<" ";
            PrivatePreOrder(node->Left()); //recursively go left always
            PrivatePreOrder(node->Middle());
            PrivatePreOrder(node->Right()); //then right
        }
        else{
            cout << "[" << node->returnItem1() << "]"  <<" ";
            PrivatePreOrder(node->Left()); //recursively go left always
            PrivatePreOrder(node->Middle());
            PrivatePreOrder(node->Right()); //then right
        }
    }
}

template<typename T>
void BTree<T>::PrivatePostOrder(TreeNode<T> *node){
    if(!node){
    }
    else{
        PrivatePostOrder(node->Left());
        PrivatePostOrder(node->Middle());
        PrivatePostOrder(node->Right());
        if(node->returnItem1() && node->returnItem2())
            cout << "[" << node->returnItem1() << ":" << node->returnItem2() <<"]"  <<" ";
        else
            cout << "[" << node->returnItem1() << "]" << " ";
    }
}

template<typename T>
void BTree<T>::PrivateInsert(T item, TreeNode<T> *&node){
    if(!node){
        cout << "making new node.." << endl;
        node = new TreeNode<T>(item);
    }

    else{
        //if no children then then insert it
        if(!TotalChildren(node)){
            //first place where it belongs in tree
            if(node->returnItem1() && node->returnItem2()){
                if(item < node->returnItem1()){
                    node->SetOverflowItem(node->returnItem2());
                    node->SetItem2(node->returnItem1());
                    node->SetItem(item);
                }
                else if(item > node->returnItem1() && item < node->returnItem2()){
                    node->SetOverflowItem(node->returnItem2());
                    node->SetItem2(item);
                }
                else
                    node->SetOverflowItem(item);
            }
            else{
                if(item < node->returnItem1()){
                    node->SetItem2(node->returnItem1());
                    node->SetItem(item);
                }
                else
                    node->SetItem2(item);
            }
        }
        //if it has children, use recursion
        else {
            if(node->Left()){
                if(item < node->returnItem1()){//traverse the left
                    return PrivateInsert(item, node->Left());
                }
            }
            //SPENCER START HERE. BASICALLY THE RECUSION INSERTS 4 FROM ABOVE. THEN IT DOES EVERYTHING, AKA INSERTING INTO MIDDLE
            //THEN AT THIS POINT IT ADDS 4 AGAIN BECAUSE MIDDLE EXISTS NOW.
            if(node->Middle()){
                if(item > node->returnItem1() && item < node->returnItem2())
                    return PrivateInsert(item,node->Middle());
            }

            if(node->Right()){
                if(node->returnItem2()){
                    if(item > node->returnItem2())
                        return PrivateInsert(item,node->Right());
                }
                else{
                    if(item > node->returnItem1())
                        return PrivateInsert(item,node->Right());
                }
            }
        }
    }
    while(node->returnOverflow()){
        cout << "Overflowed!" << endl;
        if(!Parent(node->returnItem2())){//if parent is 0, then there is no parent
            cout << "no parent for " << item << endl;
            TreeNode<T>* NewNode = new TreeNode<T>(node->returnItem2());
            TreeNode<T>* NewLeft = new TreeNode<T>(node->returnItem1());
            TreeNode<T>* NewRight = new TreeNode<T>(node->returnOverflow());
            if(!TotalChildren(node)){
                cout << "no parent for: " << node->returnItem2() << ", making new node" << endl;
                NewNode->Left() = NewLeft;
                NewNode->Right() = NewRight;
                //                NewLeft->Left() = node->Left();
            }
            if(TotalChildren(node)){
                //--------------------IF CHILDREN--------------------
                if(node->Left()->returnItem2()){
                    NewLeft->Left() = new TreeNode<T>(node->Left()->returnItem1());
                    NewLeft->Left()->Left() = node->Left()->Left();
                    NewLeft->Right() = new TreeNode<T>(node->Left()->returnItem2());
                    NewLeft->Right()->Right() = node->Left()->Right();
                }
                //                NewLeft->Right() = node->Middle();
                if(node->Right()->returnItem2()){
                    NewRight->Left() = new TreeNode<T>(node->Left()->returnItem1());
                    NewRight->Left()->Left() = node->Right()->Left();
                    NewRight->Right() = new TreeNode<T>(node->Left()->returnItem2());
                    NewRight->Right()->Right() = node->Left()->Right();
                }
            }
            node = NewNode;
        }
        else{
            cout << item <<" has a parent" << endl;
            T itemholder1 = node->returnItem1();
            T itemholder2 = node->returnItem2();
            T overflowholder = node->returnOverflow();
            //note: insert middle first always.
            if(find(Parent(node->returnItem1()))->Left() == node){
                node->SetItem2(NULL);
                node->SetOverflowItem(NULL);
                PrivateInsert(overflowholder,find(Parent(itemholder1))->Middle());
                PrivateInsertOnly(itemholder2,find(Parent(itemholder1)));
            }

            // if left child, give overflow to
            //parent's middle child
            //if right child, give item1 to parent's middle child
            else if(find(Parent(node->returnItem1()))->Right() == node){
                cout << item << " is the right child" << endl;
                node->SetItem2(NULL);
                node->SetOverflowItem(NULL);
                node->SetItem(overflowholder);
                PrivateInsert(itemholder1,find(Parent(overflowholder))->Middle());
                PrivateInsertOnly(itemholder2,find(Parent(overflowholder)));
            }
            else if(find(Parent(node->returnItem1()))->Middle() == node){

                PrivateInsertOnly(itemholder2,find(Parent(itemholder2)));
            }

            //------------------------DEBUGGING----------------------------
            cout << "TESTING: IN PRIVATE INSERT: " << endl;
            cout << "ACCORDING TO FIND, THE PARENT OF " << node->returnItem1()
                 << " IS :" << find(Parent(node->returnItem1()))->returnItem1() << endl;
            cout << "ACCORDING TO PARENT, PARENT OF " << node->returnItem1() <<" IS: " << Parent(node->returnItem1()) << endl;
            cout << "TOTAL CHILDREN OF PARENT: " <<
                    TotalChildren(find(Parent(node->returnItem1())))  << endl;

            //---------------------------------------------------------------
            //the original node is no longer overflowed
            // now give the parent a middle child with current nodes left children

            //            if(find(Parent(node->returnItem1()))->Left() == node){

            //                TreeNode<T>* NewMiddle = new TreeNode<T>(node->returnItem2());
            //                find(Parent(node->returnItem1()))->Middle() =  NewMiddle;
            //                //					NewMiddle->Left() = node->Middle();
            //                //                    NewMiddle->Right() = node->Left();
            //                node->SetItem2(NULL);
            //                node->Right() = node->Middle();
            //            }
            //            else if(find(Parent(node->returnItem1()))->Middle() == node){

            //            }
            //            else if(find(Parent(node->returnItem1()))->Right() == node){
            //                cout << "found the parent of " << node->returnItem1() << ":" << find(Parent(node->returnItem1()))->returnItem1();

            //                TreeNode<T>* NewMiddle = new TreeNode<T>(node->returnItem1());
            //                find(Parent(node->returnItem1()))->Middle() =  NewMiddle;
            //                NewMiddle->Right() = node->Left();
            //                //					NewMiddle->Right() = node->Middle();
            //                node->Left() = node->Middle();
            //                node->SetItem(node->returnItem2());
            //                node->SetItem2(NULL);
            //                //					node->Left() = NULL;
            //            }
        }
        //---------------------------------------------------

        //            //right side
        //            TreeNode<T>* NewRight = new TreeNode<T>(node->returnItem2());
        //            find(Parent(node->returnItem2()))->Right() = NewRight;
        //            NewRight->Right() = node->Right();

        //            //left side
        //            TreeNode<T>* NewLeft = new TreeNode<T>(node->returnItem1());
        //            find(Parent(node->returnItem1()))->Left() = NewLeft;
        //            NewLeft->Left() = node->Left();

        //                cout << find(Parent(node->returnItem2()))->returnItem1() << endl;
    }

}
//}
//}


template<typename T>
void BTree<T>::PrivateRemove(TreeNode<T> *&node){
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
int BTree<T>::TotalChildren(TreeNode<T> *node){
    if(!node){
        cout << "Total Children Error: Node does no exist" << endl;
        return 0;
    }
    if(node->Middle()){
        if(node->Right()){
            return 3;
        }
        return 2;
    }
    else if(node->Left()){
        if(node->Right())
            return 2;
        return 1;
    }
    return 0;
}

template<typename T>
T BTree<T>::PrivateParent(T item, TreeNode<T>* node){
    //returns 0 when there is no parent or it doesnt exist
    if(PrivateSearch(item, node)){
        if(!node){}
        else if(node->returnItem1() == item || node->returnItem2() == item || node->returnOverflow() == item)
            return 0;
        else if(!TotalChildren(node))//MAKE SURE AT LEAST 1 CHILD EXIST---------------
            return 0;

        if(node->Left()){
            if(node->Left()->returnItem1() == item || node->Left()->returnItem2() == item || node->Left()->returnOverflow())
                return node->returnItem1();
            else if(item < node->returnItem1())
                return PrivateParent(item,node->Left());
        }

        if(node->Middle()){
            if(node->Middle()->returnItem1() == item || node->Middle()->returnItem2() == item || node->Middle()->returnOverflow() == item)
                return node->returnItem1();
            if(item > node->returnItem1() && item < node->returnItem2()){
                return PrivateParent(item, node->Middle());
            }
        }

        if(node->Right()){
            if(node->Right()->returnItem1() == item || node->Right()->returnItem2() == item || node->Right()->returnOverflow()){
                //                    cout << "Child is on the right" << endl;
                return node->returnItem1();
            }
            else if(item > node->returnItem1() && item > node->returnItem2())
                return PrivateParent(item,node->Right());
        }

        //------------------ACTUAL RECURSION HERE---------------------------------
        if(PrivateParent(item,node->Left())){
            //            cout << "traversing left in privateparent" << endl;
            return PrivateParent(item,node->Left());
        }
        if(PrivateParent(item, node->Middle())){
            //            cout << "traversing middle in privateparent" << endl;
            return PrivateParent(item,node->Middle());
        }
        if(PrivateParent(item,node->Right())){
            //            cout << "traversing right in privateparent" << endl;
            return PrivateParent(item,node->Right());
        }
    }
    else{
        cout << item << " is not found in privatesearch!" << endl;
        return 0;
    }
    //    return 0;
}

template<typename T>
bool BTree<T>::PrivateSearch(T item, TreeNode<T> *node){
    if (!node) {
    }
    else if(item == node->returnItem1() || item == node->returnItem2() || item == node->returnOverflow()){
        return true;
    }
    else {
        if(PrivateSearch(item,node->Left()))
            return true; //recursively go left always
        if(PrivateSearch(item,node->Middle()))
            return true;
        if(PrivateSearch(item,node->Right()))
            return true;
    }
    return false;
}

template<typename T>
TreeNode<T> *&BTree<T>::PrivateFind(T item, TreeNode<T> *&node){
    //    cout << "Finding: " << item << endl;

    TreeNode<T>* NULLPTR = NULL;
    if(!node){
        //      node = NULL;
        return NULLPTR;
        exit(0);
    }
    if(item == node->returnItem1() || item == node->returnItem2() || item == node->returnOverflow())
        return node;
    else if(item < node->returnItem1()){
        if(!node->Left())
            return NULLPTR;
        else
            return PrivateFind(item, node->Left());
    }
    else if(!node->Middle()){
        if(!node->Right())
            return NULLPTR;
        else
            return PrivateFind(item,node->Right());
    }
    else if(item > node->returnItem1() && item < node->returnItem2()){
        return PrivateFind(item,node->Middle());
    }

    return NULLPTR;
}

template<typename T>
void BTree<T>::PrivateInsertOnly(T item, TreeNode<T> *&node){
    if(!node){
        //        cout << "making new node.." << endl;
        node = new TreeNode<T>(item);
    }

    else{
        if(node->returnItem1() && node->returnItem2()){
            if(item < node->returnItem1()){
                node->SetOverflowItem(node->returnItem2());
                node->SetItem2(node->returnItem1());
                node->SetItem(item);
            }
            else if(item > node->returnItem1() && item < node->returnItem2()){
                node->SetOverflowItem(node->returnItem2());
                node->SetItem2(item);
            }
            else
                node->SetOverflowItem(item);
        }
        else{
            if(item < node->returnItem1()){
                node->SetItem2(node->returnItem1());
                node->SetItem(item);
            }
            else
                node->SetItem2(item);
        }

        //------------MARCH 19 SPENCER START HERE, RUN THE PROGRAM. YOURE AT SECOND OVERFLOWED!

        while(node->returnOverflow()){
            cout << "Overflowed!" << endl;
            preOrder();
            if(!Parent(node->returnItem2())){//if parent is 0, then there is no parent
                cout << "no parent for " << item << endl;
                TreeNode<T>* NewNode = new TreeNode<T>(node->returnItem2());
                TreeNode<T>* NewLeft = new TreeNode<T>(node->returnItem1());
                TreeNode<T>* NewRight = new TreeNode<T>(node->returnOverflow());
                NewNode->Left() = NewLeft;
                NewNode->Right() = NewRight;
                //                if(!TotalChildren(node)){
                //                    cout << "no parent for: " << node->returnItem2() << ", making new node" << endl;

                //                NewLeft->Left() = node->Left();
                //                }
                if(TotalChildren(node)){
                    //--------------------IF CHILDREN--------------------
                    //                    if(node->Left()->returnItem2()){
                    //                        NewLeft->Left() = new TreeNode<T>(node->Left()->returnItem1());
                    //                        NewLeft->Left()->Left() = node->Left()->Left();
                    //                        NewLeft->Right() = new TreeNode<T>(node->Left()->returnItem2());
                    //                        NewLeft->Right()->Right() = node->Left()->Right();
                    //                    }
                    //                    //                NewLeft->Right() = node->Middle();
                    //                    else if(node->Right()->returnItem2()){
                    //                        NewRight->Left() = new TreeNode<T>(node->Left()->returnItem1());
                    //                        NewRight->Left()->Left() = node->Right()->Left();
                    //                        NewRight->Right() = new TreeNode<T>(node->Left()->returnItem2());
                    //                        NewRight->Right()->Right() = node->Left()->Right();
                    //                    }




                    //while loop inserting the middle items----------------------------MARCH 19 START HERE----
                    //WHAT YOU ARE GOING TO DO SPENCER, USE YOUR BST SMALLEST FUNCTION. HAVE IT RETURN THAT VALUE
                    //THEN DELETE IT, THEN HAVE THAT VALUE INSERT TO THE NEW NODE.
                    while(node->Middle()){
                        //                            T middleItemholder = node->Middle()->returnItem1();


                    }

                    //AFTER THE WHILE LOOP. SIMPLY INSERT NODE.LEFT INTO NEWNODE AND NODE.RIGHT INTO NEW NODE.

                }
                node = NewNode;
            }
            else{
                cout << item <<" has a parent" << endl;
                //first insert the middle item to the parent
                PrivateInsertOnly(node->returnItem2(),find(Parent(node->returnItem2())));
                node->SetItem2(node->returnOverflow());//make overflow item to item 2
                PrivateInsert(node->returnItem2(),find(Parent(node->returnItem2()))->Middle());//insert second item
                //to the middle
                node->SetOverflowItem(NULL);
                node->SetItem2(NULL);
            }
        }

    }
}


template<typename T>
T BTree<T>::PrivateSmallest(TreeNode<T>*& node){
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
void BTree<T>::RemoveSmallestRightChild(TreeNode<T>*& node){
    //    PrivateRemove(find(PrivateSmallest(node->Right()))); //call private remove, to remove the smallest
    //    cout << node->Right()->returnItem() << endl;
    PrivateRemove(PrivateFind(PrivateSmallest(node->Right()),node->Right()));

}
#endif // BTREE
