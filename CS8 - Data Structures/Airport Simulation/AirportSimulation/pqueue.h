#ifndef PQUEUE
#define PQUEUE
#include "plane.h"

template<typename T>
class PQueue{
public:
    PQueue();
    PQueue(queue<T> Queue);
    T front();
    void push(T plane);
    void PrintList();
private:
    queue<T> PriorityQueue;

};

template<typename T>
PQueue<T>::PQueue(queue<T> Queue)
{
    queue<T> NewQueue;
    queue<T> takeoffQueue;


    int j = Queue.size();
    int i = 0;
    while(i < j){
        if(Queue.front().getStatus() == landing){
            NewQueue.push(Queue.front());
            Queue.pop();
        }
        else{
            takeoffQueue.push(Queue.front());
            Queue.pop();
        }
        i++;
    }

    while(!takeoffQueue.empty()){
        NewQueue.push(takeoffQueue.front());
        takeoffQueue.pop();
    }
    PriorityQueue = NewQueue;

}

template<typename T>
T PQueue<T>::front()
{
   return PriorityQueue.front();
}

template<typename T>
void PQueue<T>::push(T plane){
    PriorityQueue.push(plane);
}

template<typename T>
void PQueue<T>::PrintList()
{
    queue<T> test;
    test = PriorityQueue;
    int i = 0;
    cout << "Front: ";
    while(i < PriorityQueue.size()){
        if(test.front().getStatus() == landing)
            cout << "[" << "landing" << "]";
        else if(test.front().getStatus() == takeoff)
            cout << "[" << "takeoff" << "]";
        test.pop();
        i++;
    }
        cout << ": Last";
    cout << endl;


}

#endif // PQUEUE
