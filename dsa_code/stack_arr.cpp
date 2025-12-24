#include <iostream>
using namespace std;

class Stack{
private:
    int size;
    int length;
    int *stack=new int[size];
public:
    Stack(int size):size(size), length(0){}

    bool isEmpty(){
        return (length<1);
    }

    bool isFull(){
        return (length==size);
    }

    void push(int data){
        if (!(isFull())){
            *(stack+length)=data;
            length++;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if (!(isEmpty())){
            length--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    void peek(){
        cout<<*(stack+length-1)<<endl;
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
