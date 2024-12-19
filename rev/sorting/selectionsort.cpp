#include<iostream>
using namespace std;

void selectionsort(int arr[],int n){
    for (int i = 0; i < n;i++){
        int smallest = i;
        for (int j = i + 1; j < n;j++){
            if(arr[smallest] > arr[j])
                smallest = j;
        }
        if(smallest != i){
            swap(arr[smallest], arr[i]);
        }
    }
}

int main(){
    int arr[6] = {64, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionsort(arr, n);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}