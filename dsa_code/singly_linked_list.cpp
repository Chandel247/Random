#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data):data(data){}
};

class LinkedList{
public:
    Node *head;
    LinkedList():head(NULL){}

    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void insert(int data, int idx){
        if (idx==0){
            Node *node=new Node(data);
            node->next=head;
            head=node;
        }
        else{
            Node *temp=head;
            for (int i=1;i<idx-1;i++){
                temp=temp->next;
            }
            Node *node=new Node(data);
            node->next=temp->next;
            temp->next=node;
        }
    }

    void del(int idx){
        if (idx==0){
            Node *temp=head;
            head=temp->next->next;

            free(temp);
        }
        else{
            Node *prev=head;
            Node *curr=head->next;
            for (int i=1;i<idx-2;i++){
                curr=curr->next;
                prev=prev->next;
            }
            prev->next=curr->next;
            curr->next=NULL;
            free(curr);
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
    ll.insert(4,2);
    ll.display();
    ll.insert(5,3);
    ll.display();
    ll.insert(6,2);
    ll.display();
    ll.del(0);
    ll.display();
    ll.del(2);
    ll.display();
}

