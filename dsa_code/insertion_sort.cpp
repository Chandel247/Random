#include <iostream>
using namespace std;

// ======= SORT FUNCTION TO IMPLEMENT =======
void mySort(vector<int>& arr) {

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
