#include "list.h"
#include <iostream>

using namespace std;

template <class T>
List<T>::List(){
    head = NULL;
}

template <class T>
void List<T>::inserthead(T i){
    node<T>* temp = new node<T>;
    temp -> item = i;
    temp -> next = head;
    head = temp ;
}

template <class T>
void List<T>::insertAfter(node<T>* location, T i){
    node<T>*temp = new node<T>;
    temp->item = i;
    temp->next = location->next;
    location->next = temp;
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
