#include "list.h"
#include <iostream>

using namespace std;


List::List(){
    head = NULL;
}

List::List(const List &A){
    node* walker = A.head;
    while(walker != NULL){
        inserthead(walker->item);
        walker = walker->next;
    }
    head = A.head;
}

Iterator List::Begin(){
    return Iterator(head);
}

Iterator List::search(int tofind){
    node* walker = head;
    while(walker != NULL){
        if(walker->item == tofind)
            return Iterator(walker);
        walker = walker ->next;
    }
    return Iterator(NULL);
}

Iterator List::Remove(Iterator A){
    return Iterator(Remove(A.p));
}

void List::printlist(){
    node* walker = head;
    while(walker != NULL){
        cout << walker->item << " ";
        walker = walker-> next;
    }
    cout << "NULL" << endl;
}

void List::inserthead(int i){
    node* temp = new node;
    temp -> item = i;
    temp -> next = head;
    head = temp ;
}
void List::insertAfter(Iterator A, int i){
    insertAfter(A.p,i);
}

void List::insertBefore(Iterator A, int i){
    insertBefore(A.p, i);
}
void List::Delete(Iterator deletethis){
    Delete(deletethis.p);
}

void List::insertEnd(int i){
    node* walker = head;
    node*temp = new node;
    temp->item = i;
    temp->next = NULL;
    while(walker->next != NULL)
    {
        walker = walker->next;
    }
    walker->next = temp;
}

void List::sort(){
    List temp;
    node* walker = head;
    node* walker2 = head;
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

int List::getitem()
{
    return head->item;
}

node *List::gethead()
{
    return head;
}

node *List::getlast()
{
    node* walker = head;
    while(walker != NULL){
        if (walker->next == NULL)
            return walker;
        walker = walker->next;
    }
    return walker;
}

node* List::Previous(node* location){
    node* walker = head;
    while(walker!= NULL){
        if(walker->next == location)
            return walker;
        walker = walker->next;
    }
    return NULL;
}

node* List::Remove(node*removethis){

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

Iterator List::End(){
    Iterator it(head);
    //it = it.next();
    while(!it.IsNull())//write a function for iterator that gives you the next value (return walker->next)
    {
        it++;
    }
    return it;
}

Iterator List::Previous(Iterator A){
    return Iterator(Previous(A.p));
}

node *List::Next(){
    node* temp = new node;
    temp = head;
    temp = temp->next;
    return temp;

}


void List::insertAfter(node* location, int i){
    node*temp = new node;
    temp->item = i;
    temp->next = location->next;
    location->next = temp;
}

void List::insertBefore(node* location, int i){
    node* temp = new node;
    temp->item = i;
    temp->next = location;
    if(Previous(location) == NULL){
        inserthead(i);
    }
    else
        Previous(location)->next = temp;
}

void List::Delete(node*deletethis){
    Remove(deletethis);
    delete deletethis;
}

void List::Reverse(){
    node* walker = head;
    head = NULL;
    while (walker != NULL){
        inserthead(walker ->item);
        walker = walker->next;
    }
}


