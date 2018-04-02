#ifndef LISTFUNCTIONS
#define LISTFUNCTIONS
#include "pair.h"


template<typename T>
node<T>* ReturnBigger(node<T>* &head, T item){
    node<T>* walker = new node<T>;
    walker = head;
    while(walker!=NULL){
        if(walker->item < item)
            walker = walker->next;
        else
            return walker;
    }
    return walker;
}


template<typename T>
node<T>* Previous(node<T>* location, node<T>* &head){
    node<T>* walker = new node<T>;
    walker = head;
    while(walker!= NULL){
        if(walker->next == location)
            return walker;
        walker = walker->next;
    }
    return NULL;
}

template <typename T >
void  Insert(T i, node<T>* &head){
    node<T>* temp = new node<T>;
    temp -> item = i;
    temp -> next = head;
    head = temp ;
}

template <typename T>
void Sort(node<T>*& head){
    node<T>* walker = new node<T>;
    walker = head;
    node<T>* walker2 = head->next;

    int temp;

    while(walker2 != NULL){
        while(walker2 != walker){
            if(walker2->item < walker->item){
                temp = walker->item;
                walker->item = walker2->item;
                walker2->item = temp;
            }
            walker = walker->next;
        }
        walker = head;
        walker2 = walker2->next;
    }
    head = walker ;
}

template<typename T>
node<T>*  InsertSorted(T item,node<T>* &head){
    node<T>* walker = new node<T>;
    walker = head;
    if (walker == NULL)
        Insert(item, head);
    else if(ReturnBigger(head,item) == NULL){
        while(walker->next != NULL)
            walker=walker->next;
        InsertAfter(walker, item);
    }
    else
        InsertBefore(ReturnBigger(head,item),item,head);
}
template<typename T, typename Action>
void InsertSortedUnique(T item,node<T>* &head, Action Act){
    if(Search(item, head) == NULL){
        InsertSorted(item,head);
    }
    else{
        Act(Search(item,head));
    }
}

template<typename T>
void  InsertBefore(node<T>* location, T i, node<T>* &head){
    node<T>* temp = new node<T>;
    temp->item = i;
    temp->next = location;
    if(Previous(location, head) == NULL){
        Insert(i,head);
    }
    else
        Previous(location,head)->next = temp;
}

template <typename T>
void  InsertAfter(node<T>* location, T i){
    node<T>*temp = new node<T>;
    temp->item = i;
    temp->next = location->next;
    location->next = temp;
}
template<typename T>
node<T>*  gethead(node<T>* head){
    return head;
}

template <typename T>
node<T>* Search(T i, node<T>* head){
    node<T>* temp = new node<T>;
    temp = head;
    if(temp == NULL)
        return NULL;
    while(temp != NULL){
        if (temp->item == i)
            return temp;
        temp = temp->next;
    }
    if(temp == NULL){
        //        cout << "Search error" << endl;
        return NULL;
    }
}

template <typename T>
node<T>* At(int i,node<T>* head){
    node<T>* temp = new node<T>;
    temp = head;
    int j = 1;
    while(i != j)
    {
        if(temp->next == NULL)
            return temp;
        temp = temp->next;
        j++;
    }
    return temp;
}

template <typename T>
void Delete(node<T>* deletethis,node<T>*& head){
    node<T>* temp = new node<T>;
    temp = head;
    if(temp == deletethis){
        head = temp->next;
    }
    else{
        while(temp->next != NULL)
        {
            if(temp->next == deletethis){
                temp->next = deletethis->next;
            }
            if(temp->next == NULL){
            }
            else
                temp = temp->next;
        }
    }
}
template<typename T>
node<T>* Remove(node<T>*removethis, node<T>*& head){
    Delete(removethis, head);
    return removethis;
}

template <typename T, typename Action>
void Print(node<T>* head, Action Act){
    node<T>* walker = new node<T>;
    walker = head;
    while(walker != NULL){
//        cout << "["; Act(walker); cout << "|";Act2(walker); cout << "] ";
        Act(walker);
        walker = walker-> next;
    }
    cout << "NULL" << endl;
}
template<typename T>
int  Count(node<T>* head){
    node<T>*temp = new node<T>;
    temp = head;
    int i = 0;
    if(temp->next == NULL)
        return 1;
    while(temp !=NULL){
        temp = temp->next;
        i++;
    }
    return i;
}

template <typename T>
void Reverse(node<T>*& head){
    node<T>* walker = new node<T>;
    walker = head;
    head = NULL;
    while (walker != NULL){
        Insert(walker ->item, head);
        walker = walker->next;
    }
}

template <typename T>
void DeleteRepeats(node<T>*& head){
    if(head == NULL){
    }
    else{
        node<T>* walker = new node<T>;
        walker = head;
        node<T>* walker2 = new node<T>;
        walker2 = head->next; //walker 2 will start 1 link ahead
        while(walker->next != NULL){
            while(walker2 != NULL){
                if(walker->item == walker2->item){
                    Delete(walker,head);
                    walker = head;
                    walker2 = head->next;
                }
                else
                    walker2 = walker2->next;
            }
            walker = walker->next;
            walker2 = walker->next;
        }
    }
}

template <typename T>
void  Shuffle(node<T>* head){// get a little extra help on shuffle
}

template <typename T>
void Merge(node<T>*thehead, node<T>*& head){
    node<T>* walker = new node<T>;
    walker = head;
    while(walker->next != NULL)
        walker = walker->next;
    walker->next = thehead;
}
template<typename T>
void Copy(node<T>*& newhead, node<T>*& copythis){
    newhead = copythis;
}



#endif // LISTFUNCTIONS
