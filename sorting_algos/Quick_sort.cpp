#include <iostream>
using namespace std;

int partition(int arr[], int, int);
void quicksort(int arr[], int low, int high)
{
    if(low < high){
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}
int partition(int arr[], int l, int high) {
    int pivot = arr[l]; // Set pivot to the first element
    int p = l + 1;
    int q = high;
    //first pass complete when pivot swaps with q
    while(p<=q){
        if(arr[p] <= pivot){
            p++;
        }
        if(arr[q] >= pivot){
            q--;
        }
        if(p<q && arr[p] >= pivot){
            swap(arr[p], arr[q]);
        }
    }
    // first-pass ends here
    //  p > q; then swap pivot with q
    swap(arr[q],arr[l]);
    return q;
}
int main(){

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    for (int i = 0;i<sizeof(arr)/sizeof(arr[0]);i++){
        cout << arr[i] << endl;
    }
    return 0;
}