#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data):data(data), prev(nullptr), next(nullptr){}
};

class LinkedList{
public:
    Node *head;
    LinkedList():head(nullptr){}

    void display(){
        Node *temp=head;
        while (temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void insert(int data, int idx){
        Node *node=new Node(data);

        if (idx==0){
            node->next=head;
            head=node;
            if (node->next){
                node->next->prev=node;
            }
        }
        else{
            Node *temp=head;
            for (int i=1;i<idx-1;i++){
                temp=temp->next;
            }
            node->next=temp->next;
            node->prev=temp;
            if (temp->next){
                temp->next->prev=node;
            }
            temp->next=node;
        }
    }

    void del(int idx){
        if (idx==0){
            Node *temp=head;
            head=head->next;
            head->prev=nullptr;
            temp->next=nullptr;
            delete(temp);
        }
        else{
            Node *temp=head;
            for (int i=1;i<idx;i++){
                temp=temp->next;
            }
            temp->prev->next=temp->next;
            if (temp->next){
                temp->next->prev=temp->prev;
            }
            temp->next=nullptr;
            temp->prev=nullptr;
            delete(temp);
            }
        }
};

int main(){
    LinkedList ll;
    ll.insert(3,0);
    ll.display();
    ll.insert(2,0);
    ll.display();
    ll.insert(1,0);
    ll.display();
    ll.insert(5,4);
    ll.display();
    ll.insert(4,4);
    ll.display();
    ll.del(0);
    ll.display();
    ll.del(3);
    ll.display();
    ll.del(3);
    ll.display();
}
