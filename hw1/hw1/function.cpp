#include "function.h"

template<class T>
Queue<T>::Queue()
{
    front = -1;
    rear = -1;
    capacity = 1;
    size = 0;
    Data = new T[capacity];
}
template<class T>
Queue<T>::Queue(const Queue<T> &q)
{
    front = q.front;
    rear  = q.rear;
    capacity = q.capacity;
    size = q.size;
    Data = new T[capacity];
	for ( int i = 0 ; i < capacity ; i++)
		Data[i] = q.Data[i];
}

template<class T>
Queue<T>::~Queue(){}

template<class T>
bool Queue<T>::IsEmpty()
{
}

template<class T>
T& Queue<T>::Front()
{

}

template<class T>
T& Queue<T>::Rear()
{

}

template<class T>
void Queue<T>::Push(const T &item)
{
    //Watch that: if queue is full, you have to re-allocate memory space (datas)

}

template<class T>
void Queue<T>::Pop()
{

}

void scheduler(Queue<process>& q,int n)
{

    Queue<process> ready_queue;

    // Your code goes here
    // +U everybody


    return;
}


