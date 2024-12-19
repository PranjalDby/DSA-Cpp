#include <iostream>
using namespace std;

void merge(int arr[],int l,int q,int r){
    int n1 = q - l + 1;
    int n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    // inserting Sentinel Values;
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    for (int i = 0; i < n1;i++){
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2;j++){
        R[j] = arr[q + j + 1];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void divide(int arr[],int l,int r){
    if(l < r){
        int q = l + (r - l) / 2;
        divide(arr, l, q);
        divide(arr, q + 1, r);
        merge(arr, l, q, r);
    }
}
int main(){
    int arr[5] = {12, 4, 7, 9, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    divide(arr, 0, arr_size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}