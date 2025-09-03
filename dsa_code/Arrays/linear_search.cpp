#include <iostream>
using namespace std;

int lin_search(int num, int *arr, int size){
	for (int i=0;i<size;i++){
      		if (*(arr+(i*4)) == num){
      			return i;
      		}
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}

	int num;
	cout<<"Enter number to find: ";
	cin>>num;
	int index=lin_search(num,arr,n);
	if (index == -1){
		cout<<"Number not found\n";
	}
	else{
		cout<<num<<" found at "<<index<<"\n";
		return 0;
	}
}
