#include<iostream>

using namespace std;

#define inf 99999

void merge(int arr[],int low,int mid,int high){
    int left_s = mid - low + 1;
    int right_s = high - mid;
    int LEFT[left_s];
    int RIGHT[right_s];
    // for continuing comparison we put inffinty
    LEFT[left_s - 1] = inf;
    RIGHT[right_s - 1] = inf;
    //copying the elements of array to left part
    for (int i = 0; i < left_s;i++)
    {
        LEFT[i] = arr[low + i];
    }
    for (int j = 0; j < right_s;j++){
        RIGHT[j] = arr[mid + j + 1];
    }
    int k = low;
    int i = 0,j = 0;
    while (i<left_s && j < right_s){
        if(LEFT[i] < RIGHT[j]){
            arr[k++] = LEFT[i++];
        }
        else{
            arr[k++] = RIGHT[j++];
        }
    }
    // for remaining elements;
    while(i<left_s){
        arr[k++] = LEFT[i++];
    }
    while(j<right_s){
        arr[k++] = RIGHT[j++];
    }
    printf("\n");
}
void divide(int arr[],int low,int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        //dividing
        //left sub-part
        divide(arr, low, mid);
        // right-subpart;
        divide(arr, mid + 1, high);
        //merge the sorted part
        merge(arr, low, mid, high);
    }
}

int main(){
    int arr[8] = {6,4,2,1,9,8,3,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    divide(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}