#include <iostream>
using namespace std;

void merge(int arr[],int l,int q,int r){
    int n1 = q - l + 1; //left-array size
    int n2 = r - q;     // right-array size
    int L[n1 + 1];
    int R[n2 + 1];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    for (int i = 0; i < n1; i++)
    {
        // copying element before mid;
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2;j++){
        // copying element after mid;
        R[j] = arr[q + j + 1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if(R[j] <= L[i]){
            //element in right part is less than element on left part
            arr[k] = R[j];
            j++;
        }
        else{
            arr[k] = L[i];
            i++;
        }
        k++;
    }
    // merge the remaining elements of L[]
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // merge the remaining elements of R[]
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void divide(int arr[],int l,int r){
    if(l < r){
        int mid = l + (r - l) / 2;
        divide(arr, l, mid); // divide arr into left-subpart
        divide(arr, mid + 1, r); // divide arr into right-subpart;
        //merge the array element in sorted fashion
        merge(arr, l, mid, r);
    }
}
int main(){
    int arr[10] = {34, 7, 23, 32, 5, 62, 32, 12, 22, 11};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;

    divide(arr, 0, arr_size - 1);

    cout << "Sorted array is \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}