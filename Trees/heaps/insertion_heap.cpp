#include<iostream>

using namespace std;

bool isPrime(int n){
    if(n <= 1){
        return false;
    }
    for (int i = 2; i < n;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void insertIntoMaxHeap(int arr[],int data,int &s){
    arr[s] = data;
    s++;
    int index = s - 1; //inserting at last index or leaf node
    // if we have single element size = 1; then we don't need to compare it.
    // otherwise compare the last inserted element with its root node;
    while (index != 0 && arr[index / 2] < arr[index])
    {
        swap(arr[index / 2], arr[index]);
        index = index / 2;
    }
}
void buildHeapFromPrime(int arr[], int n)
{
    int s = 0;
    int *heap = new int[n];
    for (int i = 0; i < n; i++)
    {
        insertIntoMaxHeap(heap, arr[i], s);
        // if(isPrime(arr[i])){
        //     insertIntoMaxHeap(heap, arr[i], s);
        // }
        // else{
        //     cout << arr[i] << "Is not prime Number:\n";
        // }
    }
    cout << "Newly builded max heap = \n";
    for (int i = 0; i < s;i++){
        cout << heap[i] << " ";
    }
    return;
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    buildHeapFromPrime(arr, n);
}