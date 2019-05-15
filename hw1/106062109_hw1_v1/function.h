#ifndef Function_H
#define Function_H
#include <iostream>
#define TIME_QUANTUM 3

using namespace std;

//Definition of a process
/*
    you can access each element as follows:
    process p;
    p.process_id ; p.arrival_time; p.require_time;

*/
struct process{
    int process_id;
    int arrival_time;
    int require_time;
};


/*
Definition of template queue
You have to implement public member functions
A circular queue may be a good idea, see lecture slide for more information
Any problem with this template: ILMS
*/
template <class T>
class Queue
{
public:
    Queue(); //Constructor
    Queue(const Queue<T>&);
    ~Queue(); //Destructor
    bool IsEmpty(); //Check if the queue is empty
    T& Front(); //Return front element of queue
    T& Rear(); //Return rear element of queue
    void Push(const T &item); //Push a element to the end of queue
    void Pop(); //Pop element from queue
private:
    T* Data; //Memory space that store data
    int front , rear; //front and rear index
    int capacity,size; //capacity: total memory space
                        //size: current number of elements in the queue
};
void scheduler(Queue<process> &,int );
template class Queue<process>; //explicit template class
#endif

