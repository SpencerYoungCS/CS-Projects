#ifndef LINKEDLIST
#define LINKEDLIST
#include "node.h"

template<typename T>
class LinkedList{
private:
    node<T>* head = NULL;
public:
    void printlist();
    void inserthead(T i);
    void insertBefore(node<T>* location, T i);
    void insertAfter(node<T>* location, T i);
    node<T>* Previous(node<T>* location);
    node<T>* search(T tofind);
    node<T>* Next();
    node<T>* Remove(node<T>* removethis);
    void Delete(node<T>* deletethis);
    node<T>* gethead();
    node<T>* getlast();
    int length();
    void insertEnd(T i);
    T getitem();
    node<T>* operator [](int location);
};

template<typename T>
node<T>* LinkedList<T>::operator [](int location){
        node<T> *walker = head;
//    for(int i = 0; i != location; i++ )
        int i = 0;
    while (i != location){
        if(walker != NULL){
            walker = walker->next;
        }
        i++;
    }
    return walker;
}


template <class T>
void LinkedList<T>::printlist(){
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
void LinkedList<T>::inserthead(T i){
    node<T>* temp = new node<T>;
    temp -> item = i;
    temp -> next = head;
    head = temp ;
}
template <class T>
void LinkedList<T>::insertBefore(node<T>* location, T i){
    node<T>* temp = new node<T>;
    temp->item = i;
    temp->next = location;
    Previous(location)->next = temp;
}

template <class T>
void LinkedList<T>::insertAfter(node<T>* location, T i){
    node<T>*temp = new node<T>;
    temp->item = i;
    temp->next = location->next;
    location->next = temp;
}

template <class T>
node<T>* LinkedList<T>::Previous(node<T>* location){
    node<T>* walker = head;
    while(walker!= NULL){
        if(walker->next == location)
            return walker;
        walker = walker->next;
    }
    return NULL;
}

template <class T>
node<T>* LinkedList<T>::search(T tofind){
    node<T>* walker = head;
    while(walker != NULL){
        if(walker->item == tofind)
            return walker;
        walker = walker ->next;
    }
    return NULL;
}

template <class T>
node<T>* LinkedList<T>::Next(){
    node<T>* temp = new node<T>;
    temp = head;
    temp = temp->next;
    return temp;
}

template <class T>
node<T>* LinkedList<T>::Remove(node<T>* removethis){
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
void LinkedList<T>::Delete(node<T>*deletethis){
    Remove(deletethis);
    delete deletethis;
}
template <class T>
node<T>* LinkedList<T>::gethead(){
    return head;
}

template <class T>
node<T>* LinkedList<T>::getlast(){
    node<T>* walker = head;
    while(walker != NULL){
        if (walker->next == NULL)
            return walker;
        walker = walker->next;
    }
    return walker;
}

template<typename T>
int LinkedList<T>::length()
{
    node<T>* walker = head;
    int i = 0;
    while(walker){
        walker = walker->next;
        i++;
    }
    return i;
}


template <class T>
void LinkedList<T>::insertEnd(T i){

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
T LinkedList<T>::getitem(){
    return head->item;
}

#endif // LINKEDLIST

