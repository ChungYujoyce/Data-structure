#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <iostream>
class Node
{
public:
    Node(){
        this->next = NULL;
    }
    Node(const int element , Node *next){
        this->data = element;
        this->next = next;
    }
    ~Node(){
        this->next = NULL;
    }
    friend class Chain;
    Node *next;
    int data;
};


class Chain
{
public:

    Chain(){
        head = NULL;
    }
    Chain(Node *head){
        this->head = head;
    }
    virtual void InsertBack(int data) = 0;
    virtual void InsertFront(int data) = 0;
    virtual void InsertAfter(int data,int data_ref) = 0;
    virtual void InsertBefore(int data,int data_ref) = 0;
    virtual void Delete(int data) = 0;
    virtual void DeleteFront() = 0;
    virtual void DeleteBack() = 0;
    virtual void Reverse() = 0;
    virtual void Rotate(int k) = 0;


    bool IsEmpty(){
        return this->head == NULL;
    }

    std::string PrintChain(){
        Node *cur = this->head;
        std::string result = "";
        if(cur == NULL){
            result = "Empty";
            return result;
        }
        while(cur != NULL){

            int num = cur->data;
            std::string num_str = std::to_string(num);
            result.append(num_str);
            if(cur -> next){
                result.append("->");
            }
            cur = cur->next;
        }
        return result;
    }


    Node *head;
};

class Implement : public Chain
{
public:
    void InsertBack(int data);
    void InsertFront(int data);
    void InsertAfter(int data,int data_ref);
    void InsertBefore(int data,int data_ref);
    void Delete(int data);
    void DeleteFront();
    void DeleteBack();
    void Reverse();

    void Rotate(int k );

} ;

#endif // FUNCTION_H

