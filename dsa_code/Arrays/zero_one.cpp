#include <iostream>
using namespace std;

void print_array(int *arr,int size){
    for (int i=0;i<size;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<"\n";
}

int main(){
    int arr[]={0,1,0,0,1,0};
    int size=sizeof(arr)/sizeof(arr[0]);
    //Will code 2 pointer
    int l=0;
    int r=size-1;
    while (l<r){
        if (arr[l]==0){
            l++;
        }
        else if (arr[r]!=0){
            r--;
        }
        else{
            arr[l]=arr[l]^arr[r];
            arr[r]=arr[l]^arr[r];
            arr[l]=arr[l]^arr[r];
            r--;
        }
        print_array(arr,size);
    }
    return 0;
}

