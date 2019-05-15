#include "function.h"
using namespace std;

void Implement::InsertBack(int data){
    Node* neww = new Node;
    neww->data = data;
     Node* cur=head;
    if(head==NULL) head=neww;
    else{
        while(cur->next!=NULL) cur=cur->next;
        cur->next=neww;
    }
}
void Implement::InsertFront(int data){
    Node* neww = new Node;
    neww->data = data;
    Node* cur = head;
    if(head==NULL) head=neww;
    else{
        neww->next=cur;
        head = neww;
    }
}
void Implement::InsertAfter(int data,int data_ref){ ///!!!!!!!!
    Node* neww = new Node;
    neww->data = data;
    Node* cur = head;
    Node* prev=NULL;
    if(head==NULL) return;
    while(cur->next!=NULL&&cur->data!=data_ref) cur=cur->next;

    if(cur->data==data_ref){
        if(cur->next==NULL){
            cur->next=neww; /// after tail
        }else{
            neww->next=cur->next;
            cur->next=neww;
        }
    }else return;
}
void Implement::InsertBefore(int data,int data_ref){
    Node* neww = new Node;
    neww->data = data;
    Node* cur = head;
    Node* prev=NULL;///more efficient
    while(cur->data!=data_ref&&cur->next!=NULL){
        prev=cur;
        cur=cur->next;
    }
    if(cur==head){ ///before head
        neww->next=cur;
        head=neww;
    }else if(cur->data==data_ref){
        neww->next=cur;
        prev->next=neww;
    }else return;
}

void Implement::Delete(int data){
    if(head==NULL) return;
    Node* cur=head;
    Node* prev=NULL;
    while(cur->next!=NULL&& cur->data!=data){
        prev=cur;
        cur=cur->next;
    }
    if(cur==head){ /// if delete node is the first
        head=cur->next;
        cur->next=NULL;
        delete cur;
        cur=NULL;
    }
    else if(cur->data==data){
        prev->next=cur->next;
        cur->next=NULL;
        delete cur;
        cur=NULL; /// to avoid unnecessary bug
    }else return;

}
void Implement::DeleteFront(){
    Node* temp=head;
    if(head==NULL) return;
    else if(head->next==NULL) head=NULL;///!!!!!!!!!
    else{
        temp = head;
        head = temp->next;
        delete temp;
        temp=NULL;
    }
}
void Implement::DeleteBack(){ //!1111111!!!!
    Node* cur = head;
    Node* prev = NULL;
    if(head==NULL) return;
    while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
    }
    if(cur==head){
        delete head;
        head=NULL;
    }else{
        prev->next=NULL;
        delete cur;
        cur=NULL;
    }
}
void Implement::Reverse(){ ///!!!!!!!!!!!!!

   if(head==NULL||head->next==NULL) return;
   Node* cur=head;
   Node* previous=NULL;
   Node* proceding=cur->next;

       while(proceding!=NULL){
            cur->next=previous;
            previous=cur;
            cur=proceding;
            proceding=proceding->next;
       }
       cur->next=previous;
       head=cur;
}
void Implement::Rotate(int k){

    if(head==NULL||head->next==NULL) return;
    Node* cur=head;
    Node* link=head;
    Node* tail=head;
    Node* prev=NULL;
    int num=1;
    int pos=0;
    while(tail->next!=NULL) tail=tail->next,num++;
    int times;
    if(num>k) times=k;
    else times=k%num;
    if(times==0) return;
    else{
        while(cur->next!=NULL&& pos!=num-times){
            prev=cur;
            cur=cur->next;
            pos++;
        }
        head=cur;
        prev->next=NULL;
        tail->next=link;

    }
    /*while(k--){
        Node* link=head;
        Node* temp=head;
        Node* tail;
        while(temp->next->next!=NULL) temp=temp->next;
        tail=temp->next;
        temp->next=NULL;
        tail->next=link;
        head=tail;
    }*/
}
