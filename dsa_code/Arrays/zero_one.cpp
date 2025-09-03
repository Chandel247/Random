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
	for (int i=0;i<size;i++){
		if (arr[i]==1){
      			for (int j=i;j<size;j++){
      				if (arr[j]==0){
      					arr[i]=arr[i]^arr[j];
      					arr[j]=arr[i]^arr[j];
      					arr[i]=arr[i]^arr[j];
      					print_array(arr, size);
					break;
      				}
      			}
      		}
	}
	return 0;
}

