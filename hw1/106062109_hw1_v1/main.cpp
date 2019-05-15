#include <iostream>
#include <cstdio>
#include "function.h"

using namespace std;



int main()
{
    int n;
    while(cin>>n){
        struct process p;
        Queue<process> q;
        for(int i=0;i<n;i++)
        {
            cin >> p.process_id >> p.arrival_time >> p.require_time;
            q.Push(p);
        }
        scheduler(q,n);

    }

    return 0;
}
