#ifndef LIST
#define LIST

#include "listfunctions.h"
#include "functors.h"

template <typename T>
class List{
private:
    node<T>* head = NULL;
    node<T>* walker = head;
public:
    node<T>* previous(node<T> *location);
    void insertHead(T i);
    void insertBefore(node<T>* location,T i);
    void insertAfter(node<T>* location, T i);
    node<T>* gethead();
    void insertSorted(T i);
    node<T>* search(T i);
    node<T>* at(int i);
    void DeleteThis(node<T>* deletethis);
    node<T>* remove(node<T> *removethis);
    void PrintList();
    int count();
    void reverse();
    void deleteRepeats();
    void sort();
    void copy(node<T> *head1, node<T> *copythis);
    void Shuffle();
    void merge(node<T>* thehead);
};

template<typename T>
node<T>* List<T>::previous(node<T>* location){
    Previous(location, head);
}

template <typename T>
void List<T>::insertHead(T i){
     Insert(i,head);
}

template<typename T>
void List<T>::insertBefore(node<T>* location,T i){
    InsertBefore(location, i, head);
    }

template <typename T>
void List<T>::insertAfter(node<T>* location, T i){
    InsertAfter(location,i);

}
template<typename T>
node<T>* List<T>::gethead(){
return head;
}

template<typename T>
void List<T>::insertSorted(T i){
       InsertSorted (i,head);
    }

template <typename T>
node<T>* List<T>::search(T i){
    return Search(i,head);
}

template <typename T>
node<T>* List<T>::at(int i){
    return At(i,head);
}

template <typename T>
void List<T>::DeleteThis(node<T>* deletethis){
    Delete(deletethis,head);
}

template<typename T>
node<T>* List<T>::remove(node<T> *removethis){
    return Remove(removethis, head);

}

template <typename T>
void List<T>::PrintList(){
    Print(head, GetItem<T>());
}
template<typename T>
int List<T>::count(){
    Count(head);
}

template <typename T>
void List<T>::reverse(){
    Reverse(head);
}

template <typename T>
void List<T>::deleteRepeats(){
    DeleteRepeats(head);
}
template <typename T>
void List<T>::sort(){
    Sort(head);

}

template <typename T>
void List<T>::Shuffle(){// get a little extra help on shuffle

    List<T> A;
    walker = head;
    int i = 0;
    int j = 1;
    while(i <= count()+1){
//            cout << "count is: " << count() << endl;
//        int k = rand()%count();
//            cout << "k is: " << k << endl;
        while(j <= rand()%count()){
            walker = walker->next;
            j++;
        }
        A.insertHead(Remove(walker)->item);
        i++;
        j=1;
        walker = head;
    }
    A.insertHead(head->item);
    head = A.head;
}

template <typename T>
void List<T>::merge(node<T>*thehead){
    Merge(thehead, head);

}
template<typename T>
void List<T>::copy(node<T>* newhead, node<T>* copythis){
//        newhead = copythis;
    Copy(newhead,copythis);
    }

#endif // LIST
