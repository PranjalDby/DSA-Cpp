#include <iostream>
using namespace std;

int partition(int[], int, int);
void quick_sort(int arr[], int low, int high)
{
    if(low < high){
        int pivot = partition(arr, low, high);
        //solve left-subpart
        quick_sort(arr, low, pivot - 1);
        //solve right-subpart
        quick_sort(arr, pivot + 1, high);
    }
}
int partition(int arr[],int low,int high){

    int pivot = arr[low];
    int p = low+1;
    int q = high;
    //scan the array with these pointers
    while(p<=q){
        if(arr[p] <= pivot){
            //increment p until we found element greater than pivot
            p++;
        }
        if(arr[q] >= pivot){
            //decrement q until we found element lesser than pivot
            q--;
        }
        if(p<q && arr[p] >= pivot){
        swap(arr[p], arr[q]);//swap greater element with smaller element
        }
    }
    //p and q crosses each other.then swap pivot with q element
    swap(arr[low], arr[q]);
    // return q; which is our break point b/w two partitions
    return q;
}
int main(){
    int arr[10] = {34, 7, 23, 32, 5, 62, 32, 4, 12, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}