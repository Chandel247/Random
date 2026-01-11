#include <iostream>
using namespace std;

class Queue{
private:
    int arr[5];
    int size=sizeof(arr)/sizeof(arr[0]);
    int capacity;

public:
    Queue():capacity(0){}

    bool isFull(){
        return (capacity==size);
    }

    bool isEmpty(){
        return (capacity==0);
    }

    void enqueue(int data){
        if (!isFull()){
            arr[capacity]=data;
            ++capacity;
        }
        else{
            return;
        }
    }

    void dequeue(){
        if (!isEmpty()){
            int prev=0;
            int next=1;
            while (next!=capacity){
                arr[prev]=arr[next];
                ++prev;
                ++next;
            }
            --capacity;
        }
        else{
            return;
        }
    }

    void print_arr(){
        for (int i=0;i<capacity;++i){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
    }
    
};

int main(){
    Queue q;
    q.enqueue(1);
    q.print_arr();
    q.enqueue(2);
    q.print_arr();
    q.enqueue(3);
    q.print_arr();
    q.enqueue(4);
    q.print_arr();
    q.dequeue();
    q.print_arr();
    q.enqueue(5);
    q.print_arr();
    q.dequeue();
    q.print_arr();
}
