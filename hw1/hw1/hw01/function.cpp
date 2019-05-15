#include "function.h"
using namespace std;

template<class T>
Queue<T>::Queue()
{
    front = -1;
    rear = -1;
    capacity = 100000;
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
Queue<T>::~Queue()
{
    delete []Data;
}

template<class T>
bool Queue<T>::IsEmpty()
{
    if(front == rear) return true;
    else return false;
}

template<class T>
T& Queue<T>::Front()
{
    return Data[front+1];
}

template<class T>
T& Queue<T>::Rear()
{
    return Data[rear];
}

template<class T>
void Queue<T>::Push(const T &item)
{
    if(rear+1 == capacity)
    {
        capacity *= 2;
        T* newData = new T[capacity];
        for ( int i = front+1 ; i <= rear ; i++)
            newData[i] = Data[i];
        Data = newData;
    }
    size++;
    rear ++;
    Data[rear] = item;
}

template<class T>
void Queue<T>::Pop()
{
    if(!IsEmpty())
    {
        front++;
        size--;
    }
}
void scheduler(Queue<process>& q,int n)
{
    Queue<process> ready_queue;
    int time=q.Front().arrival_time;
    ready_queue.Push(q.Front());
    q.Pop();
    int finish=0;
    bool flag=false;
    process not_finish;
    while(finish!=n)
    {
        while(q.Front().arrival_time<time&&!q.IsEmpty())
        {
            ready_queue.Push(q.Front());
            q.Pop();
        }
        if(flag)
        {
            ready_queue.Push(not_finish);/// been done before
            flag=false;
        }
        process working = ready_queue.Front();
        ready_queue.Pop();
        if(working.require_time>3)
        {
            working.require_time-=3;
            time+=3;
            flag = true;
            not_finish = working;
        }
        else
        {
            finish++;
            if(finish != n) cout << working.process_id<< ",";
            else cout << working.process_id;
            time+=working.require_time;
        }
        if(ready_queue.IsEmpty()&&flag==false){
            time=q.Front().arrival_time;
            ready_queue.Push(q.Front());
            q.Pop();
        }
    }
    cout << "\n";
    return;
}
