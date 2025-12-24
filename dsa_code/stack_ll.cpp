#include <iostream>
using namespace std;

class Node{
private:
    int data;
public:
    Node *next;

    int getData(){
        return data;
    }
    Node(int data):data(data), next(nullptr){}
};

class Stack{
private:
    Node *head;
    int length;
    int max;
public:
    Stack(int max):max(max), length(0), head(nullptr){}

    void peek(){
        cout<<head->getData()<<endl;
    }

    bool isEmpty(){
        return (length<1);
    }

    bool isFull(){
        return (length==max);
    }

    void push(int data){
        if (!(isFull())){
            Node *node=new Node(data);

            node->next=head;
            head=node;
            length++;
        }
        else{
            cout<<"Invalid operation"<<endl;
        }
    }

    void pop(){
        if (!(isEmpty())){
            Node *temp=head;

            head=head->next;
            temp->next=nullptr;
            delete(temp);
            length--;
        }
        else{
            cout<<"Invalid operation"<<endl;
        }
    }

    void size(){
        cout<<length<<endl;
    }
};

int main(){
    Stack S(5);
    S.push(1);
    S.peek();
    S.push(2);
    S.push(2);
    S.push(2);
    S.push(2);
    S.peek();
    S.push(2);
    S.pop();
    S.peek();
    S.push(3);
    S.peek();
}
