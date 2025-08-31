#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	float max=0,min;
      	int arr[n];
	for (int i=0;i<n;i++){
		cin>>arr[i];
		if (arr[i]>max){
      			max=arr[i];
      		}
		else if (arr[i]<min){
      			min=arr[i];
      		}
	}
	cout<<max-min<<endl;
	return 0;
}
