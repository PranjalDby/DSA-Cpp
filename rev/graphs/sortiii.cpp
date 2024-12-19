#include<iostream>


using namespace std;

#define inf 99999
void merge(int arr[], int l, int mid, int h)
{
    int l_size = mid - l + 1;
    int r_size = h - mid;
    int left[l_size];
    int right[r_size];
    //infi
    left[l_size] = inf;
    right[r_size] = inf;

    //copy the dat
    for (int i = 0; i < l_size;i++){
        left[i] = arr[l + i];
    }
    for (int j = 0; j < r_size;j++){
        right[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = l;
    while(i < l_size && j < r_size){
        if(left[i] < right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }

    //for left elements
    while(i<l_size){
        arr[k++] = left[i++];
    }
    while(j<r_size){
        arr[k++] = right[j++];
    }
}
void divide(int arr[],int l,int h){
    if(l<h){
        int mid = l + (h - l) / 2;
        divide(arr, l, mid);
        divide(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

int main(){
    int arr[] = {5, 3, 8, 6, 2, 7, 1, 4};
    cout << "Unsorted array: ";
    int n = sizeof(arr) / sizeof(arr[0]);
    divide(arr, 0,n-1);
    for (int i = 0; i <n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}