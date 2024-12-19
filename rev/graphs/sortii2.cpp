#include <iostream>

using namespace std;

#define inf 99999

int pivot(int arr[],int l,int h){
    int pivot = l;
    int p = l + 1;
    int q = h;
    while(true){
        while(p<= q && arr[pivot] <= arr[q]){
            q--;
        }
        while(p <= q && arr[pivot] >= arr[p]){
            p++;
        }
        if(p>=q){
            break;
        }
        swap(arr[p], arr[q]);
    }
    swap(arr[pivot], arr[q]);
    return q;
}
void divide(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = pivot(arr, l, h);
        divide(arr, l, p-1);
        divide(arr, p +1 , h);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 6, 2, 7, 1, 4};
    cout << "Unsorted array: ";
    int n = sizeof(arr) / sizeof(arr[0]);
    divide(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}