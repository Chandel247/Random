#include <iostream>
using namespace std;

class dyn_arr{
public:
    int size;
    int capacity;
    int *arr;

    dyn_arr(int size):size(size), capacity(0){
        arr=new int[size];
    }

    void display_arr(){
        for (int i=0;i<(this->capacity);i++){
            cout<<*((this->arr)+i)<<" ";
        }
        cout<<endl;
    }

    void insert(int ele, int idx){
        if (this->capacity==this->size){
            this->size=this->size*2;
            int *new_arr=new int[this->size];
            for (int i=0;i<capacity;i++){
                *(new_arr+i)=*(arr+i);
            }
            delete[] arr;
            this->arr=new_arr;
        }
        if (idx==-1){
            *((this->arr)+(this->capacity))=ele;
        }
        else{
            for (int i=(this->capacity);i>idx;i--){
                *((this->arr)+i)=*((this->arr)+i-1);
            }
            *((this->arr)+idx)=ele;
        }
        this->capacity++;
    }

    void del(int idx){
        if (idx==-1){
            this->capacity--;
        }
        else{
            for (int i=idx;i<capacity;i++){
                *((this->arr)+i)=*((this->arr)+i+1);
            }
            this->capacity--;
        }
    }
};

int main(){
    dyn_arr arr1(5);
    arr1.insert(1,-1);
    arr1.display_arr();
    arr1.insert(4,-1);
    arr1.display_arr();
    arr1.insert(2,1);
    arr1.display_arr();
    arr1.insert(3,2);
    arr1.display_arr();
    arr1.insert(5,-1);
    arr1.display_arr();
    arr1.insert(6,-1);
    arr1.display_arr();
    arr1.del(-1);
    arr1.display_arr();
    arr1.del(-1);
    arr1.display_arr();
    arr1.del(1);
    arr1.display_arr();
    arr1.del(0);
    arr1.display_arr();
}
