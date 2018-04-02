#ifndef PAIR
#define PAIR
#include "node.h"

template<typename Key, typename Value>
class Pair{
public:
    Pair();
    Pair(Key i);
    void inc();
    void DoNothing();
    Key getpairitem();
    Key item;
    Value UniqueValue=1;
    Pair<Key,Value>* next;
    template <typename UKey, typename UValue>
    friend bool operator==(const Pair<UKey,UValue>& lhs, const Pair<UKey,UValue>& rhs);
    template <typename UKey, typename UValue>
    friend bool operator<(const Pair<UKey,UValue>& lhs, const Pair<UKey,UValue>& rhs);

};

template<typename Key, typename Value>
Pair<Key,Value>::Pair()
{

}

template<typename Key, typename Value>
Pair<Key,Value>::Pair(Key i)
{
    item = i;
}

template<typename Key, typename Value>
void Pair<Key,Value>::inc()
{
    UniqueValue++;
}

template<typename Key, typename Value>
void Pair<Key,Value>::DoNothing()
{

}

template<typename Key, typename Value>
Key Pair<Key,Value>::getpairitem()
{
    return item;
}
template <typename UKey, typename UValue>
bool operator==(const Pair<UKey,UValue>& lhs, const Pair<UKey,UValue>& rhs){
    if(lhs.item == rhs.item)
        return true;
    return false;
}

template <typename UKey, typename UValue>
bool operator<(const Pair<UKey,UValue> &lhs, const Pair<UKey, UValue> &rhs)
{
 if(lhs.item < rhs.item)
     return true;
 return false;
}

#endif // PAIR
