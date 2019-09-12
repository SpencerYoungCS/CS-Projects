#ifndef MAP
#define MAP
#include "listfunctions.h"
#include "functors.h"
template<typename T, typename U>
class Map{
private:
    node<Pair<T,U> >* head = NULL;
    node<Pair<T,U> >* walker = head;
public:
    Map();
    void Insert(T item);
    void DeleteThis(node<Pair<T,int> >* deletethis);
    void PrintList();
    void MergeThis(node<Pair<T,int> >*thehead);
    U& operator[](T item);
    node<Pair<T,U> >* SearchList(T item);
    node<Pair<T,U> >* gethead();

};

template<typename T, typename U>
Map<T,U>::Map(){
    head = NULL;
}

template<typename T, typename U>
U& Map<T,U>::operator[](T item){
    if(SearchList(item) == NULL)
        Insert(item);
    return SearchList(item)->item.UniqueValue;
}

template<typename T, typename U>
void Map<T,U>::Insert(T item){
    Pair<T,U> temp(item);
    InsertSortedUnique(temp, head, DoNothing<Pair<T,U> >());
}

template<typename T, typename U>
void Map<T,U>::PrintList(){
    Print(head,PrintPair<Pair<T,U> >());
}

template<typename T, typename U>
node<Pair<T,U> >* Map<T,U>::SearchList(T item){
    Pair<T,int> temp(item);
    return Search(temp,head);
}
template<typename T, typename U>
void Map<T,U>::DeleteThis(node<Pair<T,int> >* deletethis){
    Delete(deletethis,head);
}
template<typename T, typename U>
void Map<T,U>::MergeThis(node<Pair<T,int> >*thehead){
        Merge(thehead,head);
    }

template<typename T, typename U>
node<Pair<T,U> >* Map<T,U>::gethead(){
    return head;
}
#endif // MAP
