#include <iostream>
using namespace std;

int main(){
	int arr[10];

	for (int i=0;i<10;i++){
		cin>>arr[i];
	}

	//For element in even index
	for (int i=0;i<10;i=i+2){
		cout<<arr[i]<<" ";
	}
	cout<<" "<<endl;

	//For element in odd index
	for (int i=1;i<10;i=i+2){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	//First and last element
	cout<<arr[0]<<" "<<arr[9]<<endl;

	//Array in reverse
	for (int i=0;i<5;i++){
		arr[i]=arr[i]^arr[9-i];
		arr[9-i]=arr[i]^arr[9-i];
		arr[i]=arr[i]^arr[9-i];
	}
	for (int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}

	cout<<endl;
	return 0;
}
