#include <iostream>
using namespace std;

// ======= SORT FUNCTION TO IMPLEMENT =======
void mySort(vector<int>& arr) {
    // Implement any sorting algorithm here
    int n=arr.size();
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

// ======= DRIVER CODE =======
int main() {
    vector<int> arr={9,2,8,1,5,4,3};
    mySort(arr);

    cout << "Sorted array:\n";
    for(int x : arr){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
