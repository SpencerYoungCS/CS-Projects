#ifndef LIST_H
#define LIST_H
#include "node.h"
#include "iterator.h"
using namespace std;

template <class T>
class List{
private:
    node<T>* head;
public: List(){
        void printlist();
        void inserthead(T i);
        void insertBefore(node <T>* A, T i);
        void insertAfter(node<T>* A, T i);
        void Delete(node<T>*deletethis);
        void Reverse();
        void insertEnd(T i);
        void sort();
        T getitem();
        node<T>* Previous(node<T>* location);
        node<T>* search(T tofind);
        node<T>* Next();
        node<T>* Remove(node<T>* removethis);
        node<T>* Previous(node<T>* location);
        node<T>* gethead();
        node<T>* getlast();



        //----------------------ITERATOR FUNCTIONS --------------------------U
        Iterator<T> End();
        Iterator<T> Begin();
        Iterator<T> search(int tofind);
        Iterator<T> Remove(Iterator<T> A);
        Iterator<T> Previous(Iterator<T> A);
        void insertAfter(Iterator<T> A, int i);
        void insertBefore(Iterator<T> A, int i);
        void Delete(Iterator<T> deletethis);
    }
};

//--------------------------------CODE---------------------------------------------


template <class T>
List<T>::List(){
    head = NULL;
}

template <class T>
void List<T>::printlist(){
    node<T> *walker = head;
    while(walker != NULL)
    {
        cout << walker->item << " ";
        walker = walker-> next;
    }
    cout << "NULL" << endl;
    walker = head;
}

template <class T>
void List<T>::inserthead(T i){
    node<T>* temp = new node<T>;
    temp -> item = i;
    temp -> next = head;
    head = temp ;
}
template <class T>
void List<T>::insertBefore(node<T>* location, T i){
    node<T>* temp = new node<T>;
    temp->item = i;
    temp->next = location;
    Previous(location)->next = temp;
}

template <class T>
void List<T>::insertAfter(node<T>* location, T i){
    node<T>*temp = new node<T>;
    temp->item = i;
    temp->next = location->next;
    location->next = temp;
}

template <class T>
node<T>* List<T>::Previous(node<T>* location){
    node<T>* walker = head;
    while(walker!= NULL){
        if(walker->next == location)
            return walker;
        walker = walker->next;
    }
    return NULL;
}

template <class T>
node<T>* List<T>::search(T tofind){
    node<T>* walker = head;
    while(walker != NULL){
        if(walker->item == tofind)
            return walker;
        walker = walker ->next;
    }
    return NULL;
}

template <class T>
node<T>* List<T>::Next(){
    node<T>* temp = new node<T>;
    temp = head;
    temp = temp->next;
    return temp;
}

template <class T>
node<T>* List<T>::Remove(node<T>* removethis){
    if(Previous(removethis) == NULL) // this checks if the first needs to be removed, however will kill the first if previous fails somehow;
    {
        if(head == NULL)
            return head;
        else
            return head = head->next;
    }
    if(head == NULL)
    {
        return head;
    }
    Previous(removethis)->next = removethis->next;
    return removethis;
}
template <class T>
node<T>* List<T>::Previous(node<T>* location){
    node<T>* walker = head;
    while(walker!= NULL){
        if(walker->next == location)
            return walker;
        walker = walker->next;
    }
    return NULL;
}
template <class T>
void List<T>::Delete(node<T>*deletethis){
    Remove(deletethis);
    delete deletethis;
}
template <class T>
node<T>* List<T>::gethead(){
    return head;
}

template <class T>
node<T>* List<T>::getlast(){
    node<T>* walker = head;
    while(walker != NULL){
        if (walker->next == NULL)
            return walker;
        walker = walker->next;
    }
    return walker;
}


template <class T>
void List<T>::Reverse(){
    node<T>* walker = head;
    head = NULL;
    while (walker != NULL){
        inserthead(walker ->item);
        walker = walker->next;
    }
}

template <class T>
void List<T>::insertEnd(int i){

    node<T>* walker = head;
    node<T>*temp = new node<T>;
    temp->item = i;
    temp->next = NULL;
    while(walker->next != NULL)
    {
        walker = walker->next;
    }
}

template<class T>
void List<T>::sort(){

    List<T> temp;
    node<T>* walker = head;
    node<T>* walker2 = head;
    while(walker != NULL){
        if(walker2->item >= walker->item)
            walker = walker2;
        walker2 = walker2->next;
        if(walker2 == NULL){
            temp.inserthead(walker->item);
            Remove(walker);
            walker = head;
            walker2 = head;//this original head is being removed
        }
        if (walker->next == NULL){
            temp.inserthead(walker->item);
            walker = NULL;
        }
    }
    head = temp.head;
}

template<class T>
T List<T>::getitem(){
    return head->item;
}

template <class T>
Iterator<T> List<T>::End(){
    Iterator<T> it(head);
    //it = it.next();
    while(!it.IsNull())//write a function for iterator that gives you the next value (return walker->next)
    {
        it++;
    }
}

template <class T>
Iterator<T> List<T>::Begin(){
    return Iterator<T>(head);
}

template <class T>
Iterator<T> List<T>::search(T tofind){
    node<T>* walker = head;
    while(walker != NULL){
        if(walker->item == tofind)
            return Iterator<T>(walker);
        walker = walker ->next;
    }

}

template <class T>
Iterator<T> List<T>::Remove(Iterator<T> A){
    return Iterator<T>(Remove(A.p));
}

template <class T>
Iterator<T> List<T>::Previous(Iterator<T> A){
    return Iterator<T>(Previous(A.p));
}

template <class T>
void List<T>::insertAfter(Iterator<T> A, int i){
    insertAfter(A.p,i);
}

template <class T>
void List<T>::insertBefore(Iterator<T> A, int i){
    insertBefore(A.p, i);
}
template <class T>
void List<T>::Delete(Iterator<T>, deletethis){
    Delete(deletethis.p);
}

#endif // LIST_H
