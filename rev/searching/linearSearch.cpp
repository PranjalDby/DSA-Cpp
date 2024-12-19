#include<iostream>
using namespace std;


//linear search perform a linear scan of array to find an element in array
//theta(n)
int main(){
    int arr[8] = {34, 7, 23, 32, 5, 62, 31, 12};
    int n = 8;
    int target = 34;
    bool found = false;

    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            found = true;
            cout << "Element found at index " << i << endl;
            break;
        }
    }

    if(!found) {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}