#include<iostream>

using namespace std;
#define inf 99999
int quicksort(int arr[], int low, int high) {
    int pivot = low;
    int p = low + 1;
    int q = high;
    while(true){
        while(p <= q && arr[p] <= arr[pivot]){
            p++;
        }
        while(p <= q && arr[q] >= arr[pivot]){
            q--;
        }
        if(p >= q){
            break;
        }
        swap(arr[q], arr[p]);
    }
    //case if p>=q swapping pivot element with q
    swap(arr[pivot], arr[q]);
    return q;
}
void divide(int arr[],int l,int h){
    if(l < h){
        int pivot = quicksort(arr, l, h);
        divide(arr, l, pivot - 1);
        divide(arr, pivot + 1, h);
    }
}
int main(){
    int arr[8] = {34, 7, 23, 32, 5, 62, 39, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    divide(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}