#include<iostream>

using namespace std;



int n = 100;
int *heap;
int capacity = 0;
void insertMaxHeap(int heap[], int e)
{
    int index = capacity;
    //inserting at last then heapify up
    heap[capacity] = e;
    capacity++;
    while (index != 0 && heap[(index - 1) /2 ] < heap[index]){
        swap(heap[(index - 1) / 2], heap[(index)]);
        // moving upwards;
        index = (index - 1) / 2;
    }
}
void insertMinHeap(int heap[],int e){
    int index = capacity;
    heap[index] = e; // insertion always from last
    capacity++;
    //comparing it with parent to maintain heap order:min
    int parentindx = (index - 1) / 2;
    while (index != 0 && heap[parentindx] > heap[index]){
        swap(heap[parentindx], heap[index]);
        index = parentindx;
        parentindx = (index - 1) / 2;
    }
}
void heapify(int heap[],int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < capacity && heap[smallest] > heap[left])
    {
        smallest = left;
    }
    if(right < capacity && heap[smallest] > heap[right]){
        smallest = right;
    }
    if( smallest != i){
        swap(heap[i], heap[smallest]);
        //to heapify down
        heapify(heap, smallest);
    }
}
void heapify_max(int heap[],int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < capacity && heap[largest] < heap[left])
    {
        largest = left;
    }
    if(right < capacity && heap[largest] < heap[right]){
        largest = right;
    }
    if( largest != i){
        swap(heap[i], heap[largest]);
        //to heapify down
        heapify_max(heap, largest);
    }
}
void deleteNodeMinHeap(int heap[]){
    if(capacity == 0){
        return;
    }

    heap[0] = heap[capacity - 1];//replace root with last node
    cout << "heap = " << heap[0] << endl;
    capacity--;
    // thoda sa game khelege to reduc our computation i = (n-1)/2 se leke 0 tak chalaenge;becuase leaf are always following property
    for (int i = capacity / 2 - 1; i >= 0; i--)
    {
        heapify(heap, i);
    }
}

void deleteMaxNode(int heap[]){
    if(capacity == 0){
        return;
    }
    cout << "Deleted " << heap[0] << endl;
    heap[0] = heap[capacity - 1];
    capacity--;
    for (int i = capacity / 2 - 1; i >= 0; i--)
    {
        heapify_max(heap, i);
    }
}
void heapsort(int heap[]){
    while (capacity !=0 )
    {
        cout << heap[0] << " ";
        heap[0] = heap[capacity - 1];
        capacity--;
        heapify_max(heap, 0); // calling heapify for root node;
    }
}
void heapsort_asc(int heap[]){
    while(capacity != 0){
        cout << heap[0] << " ";
        heap[0] = heap[capacity - 1];
        capacity--;
        heapify(heap, 0);
    }
}
int main(){
    heap = new int[n];
    //creating new heap from an array
    int arr[] = {5, 3, 8, 4, 1, 7, 2, 6,34};
    int ss = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < ss; i++)
    {
        insertMinHeap(heap, arr[i]);
    }
    // cout << "size = " << capacity << endl;
    // cout << "Deleting\n";
    // // deleteMaxNode(heap);
    // cout << "heap sort\n";
    // heapsort_asc(heap);
    // // for (int i = 0; i < capacity; i++)
    // // {
    // //     cout << heap[i] << " ";
    // // }
}