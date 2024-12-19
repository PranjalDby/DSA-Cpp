#include<iostream>
using namespace std;


void bubbleSort(int arr[],int n){
    /*
    Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until the list is sorted. The algorithm gets its name because smaller elements "bubble" to the top of the list.
    */
    for (int i = 0; i < n;i++){
        //no of passes
        for (int j = 0; j < n;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main(){
    int arr[6] = {64, 34, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}