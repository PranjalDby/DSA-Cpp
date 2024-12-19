#include<iostream>
using namespace std;

int binarysearch(int arr[],int s,int e,int key){
    if(s>e){
        return -1;
    }
    int mid = s + (e - s) / 2;
    int ans = -1;

    if (key > arr[mid])
    {
        //element lies in right part
        ans = binarysearch(arr, mid+1,e,key);
    }
    else if(key < arr[mid]){
        //element
        ans = binarysearch(arr, s, mid-1,key);
    }
    else if(key == arr[mid]){
        ans = mid;
        return ans;
    }
    return ans;
}
int main(){
    int arr[8] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int element = 12; // Element to search for
    int result = binarysearch(arr, 0, size - 1,element);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
}