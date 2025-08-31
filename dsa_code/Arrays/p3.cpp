#include <iostream>
using namespace std;

int main(){
	int arr[5];
	for (int i=0;i<5;i++){
		cin>>arr[i];
	}

	//Sum of every element
	int sum=0;
	for (int i=0;i<5;i++){
		sum+=arr[i];
	}
	cout<<sum<<endl;

	//Sum of alternate element
	int sum_alt=0;
	for (int i=0;i<5;i=i+2){
		sum_alt+=arr[i];
	}
	cout<<sum_alt<<endl;

	//Second highest element
	int highest=0;
	for (int i=0;i<5;i++){
		if (arr[i]>highest){
      			highest=arr[i];
      		}
	}
	int second_highest=0;
	for (int i=0;i<5;i++){
		if (arr[i]>second_highest && arr[i]<highest){
      			second_highest=arr[i];
      		}
	}
	cout<<second_highest<<endl;

	return 0;
}
