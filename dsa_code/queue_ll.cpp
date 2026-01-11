#include <iostream>
using namespace std;

class Node{
private:
    int data;

public:
    Node *next;
    Node(int data):data(data), next(nullptr){}
};

class Queue{
private:
    Node *head;
    Node *tail;

public:
    Queue():head(nullptr), tail(nullptr){}

    void enqueue(int data){
        Node *node=new Node(data);
        if (head==nullptr){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }

    }

    void dequeue(){
        Node *temp=head;
        head=head->next;
        temp->next=nullptr;
        delete(temp);
    }

};
