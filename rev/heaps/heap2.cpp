#include<iostream>

using namespace std;


void heapify_min(int heap[],int n,int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[smallest] > heap[left]){
        smallest = left;
    }
    if (right < n && heap[smallest] > heap[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(heap[i], heap[smallest]);
        heapify_min(heap, n, smallest);
    }
}

void insert(int heap[],int &n,int e){
    int index = n;
    heap[n] = e;
    n++;
    while (index != 0 && heap[(index - 1)/2] > heap[index])
    {
        swap(heap[(index - 1)/2], heap[index]);
        index = (index - 1) / 2;
    }
}
void heap_sort(int heap[],int n){
    while(n!=0){
        cout << heap[0] << " ";
        heap[0] = heap[n - 1];
        n--;
        heapify_min(heap, n, 0); // heapify for root
    }
}
int main(){
    int arr[] = {5, 3, 8, 4, 1, 7, 2, 6, 34};
    int ss = sizeof(arr) / sizeof(arr[0]);
    int heap[100] = {0};
    // //creatinon of min heap
    // for (int i = ss / 2 - 1; i >= 0; i--)
    // {
    //     heapify_min(arr,ss, i);
    // }
    int cap = 0;
    for (int i = 0; i < ss;i++)
        insert(heap, cap, arr[i]);
    heap_sort(heap,cap);
    // for (int i = 0; i < ss; i++)
    // {
    //     cout << heap[i] << " ";
    // }
}