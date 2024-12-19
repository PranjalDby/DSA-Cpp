#include<iostream>

using namespace std;



void heapify(int heap[],int s,int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // compair root element with it left child and right child;
    if(left < s && heap[left] < heap[smallest]){
        smallest = left;
    }
    if(right < s && heap[right] < heap[smallest]){
        smallest = right;
    }

    // swap root element with smaller value;
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        // call for next index or heapify downwards
        heapify(heap, s, smallest);
    }
}
void buildMinHeap(int arr[],int n){
    for (int i = n/2 - 1; i >= 0;i--){
        heapify(arr, n, i);
    }
}

void deleteNode(int arr[],int &n){
    arr[0] = arr[n - 1];
    n--;
    heapify(arr, n, 0);
}

void heapSort(int arr[],int n){
    int t = n;
    while(n > 0){
        cout << arr[0] << " ";
        // swap(arr[0],arr[t-1]);
        // t--;
        // heapify(arr, t, 0);
        deleteNode(arr, n);
    }
}

void insertNode(int arr[],int &s,int d){
    arr[s] = d;
    s++;
    int i = s - 1;
    while(i!= 0 && arr[s/2] < arr[i]){
        swap(arr[i / 2], arr[i]);
        i = i / 2;
    }

}
int main(){
    int arr[] = {54, 53, 52, 50,65,42};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Min heap is =\n";
    buildMinHeap(arr, n);
    // deleteNode(arr, n);
    // deleteNode(arr, n);
    // insertNode(arr, n, 30);
    cout << "Printing in ascending order\n";
    heapSort(arr, n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
}