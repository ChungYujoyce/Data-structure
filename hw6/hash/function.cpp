#include <iostream>
#include "function.h"
#include <bits/stdc++.h>
using namespace std;
int ans;
void  Implement ::Add(const string &str){
    if( Exist(str) ) return;  //be careful!!!!!!
    int length=str.size();
    int ex=length-1;
    ans=0;
    for(auto i:str){
        ans+=i%41*pow(13331%41,ex);
        ex--;
    }
    ans%=41;
    table[ans].push_back(str);
}
void  Implement ::Delete(const string &str){
    int length=str.size();

    int ex=length-1;
    ans=0;
    for(auto i:str){
        ans+=i%41*pow(13331%41,ex);
        ex--;
    }
    ans%=41;
    list<string>::iterator it;
    for(it=table[ans].begin();it!=table[ans].end();){
        if(*it==str)
        table[ans].erase(it++);
        else
        it++;
    }
}
bool  Implement ::Exist(const string &str){
    int length=str.size();
    int ex=length-1;
    ans=0;
    for(auto i:str){
        ans+=i%41*pow(13331%41,ex);
        ex--;
    }
    ans%=41;
    list < string> :: iterator it;
    for(it=table[ans].begin();it!=table[ans].end();){
        if(*it==str) return 1;
        else it++;
    }
    return 0;
}

