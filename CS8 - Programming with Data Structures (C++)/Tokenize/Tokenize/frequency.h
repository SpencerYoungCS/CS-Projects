#ifndef FREQUENCY
#define FREQUENCY
#include "listfunctions.h"
#include "functors.h"

template<typename T>
class Frequency{
public:
    Frequency();
    void Insert(T item);
    int operator[](T item);
    void PrintList();
    void MergeThis(node<Pair<T,int> >*thehead);
    void DeleteThis(node<Pair<T,int> >* deletethis);
    node<Pair<T,int> >* Remove(node<Pair<T,int> >*removethis);
    node<Pair<T,int> >* gethead();
    node<Pair<T,int> >* SearchList(T i);
private:
    node<Pair<T,int> >* head = NULL;
    node<Pair<T,int> >* walker = head;
};
template<typename T>
Frequency<T>::Frequency(){
    head = NULL;
}

template<typename T>
int Frequency<T>::operator[](T item){
    return SearchList(item)->item.UniqueValue ;
}


template<typename T>
void Frequency<T>::Insert(T item){
    Pair<T,int> temp(item);
    InsertSortedUnique(temp, head, Inc<Pair<T,int> >());
}

template<typename T>
void Frequency<T>::PrintList(){
    Print(head, PrintPair<Pair<T,int> >());
}

template<typename T>
node<Pair<T,int> >* Frequency<T>::SearchList(T i){
    Pair<T,int> temp(i);
    return Search(temp,head);
}
template<typename T>
void Frequency<T>::MergeThis(node<Pair<T,int> >*thehead){
    Merge(thehead, head);
}

template<typename T>
node<Pair<T,int> >* Frequency<T>::gethead(){
    return head;
}

template <typename T>
void Frequency<T>::DeleteThis(node<Pair<T,int> >* deletethis){
    Delete(deletethis,head);
}

template <typename T>
node<Pair<T,int> > *Frequency<T>::Remove(node<Pair<T,int> >*removethis){
    Delete(removethis);
    return removethis;
}


#endif // FREQUENCY
