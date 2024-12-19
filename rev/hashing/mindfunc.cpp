#include<iostream>

using namespace std;


int counts(int arr[],int n,int k){
    int start = 0;
    int end = n;
    int start_index = 0;
    int count = 0;
    int mid = start + (end - start) / 2;
    int end_index = mid + 1;
    while (start < end)
    {
        if (arr[mid] < k){
            start_index = 0;
            start = mid + 1;
            end_index++;
        }
        else if(arr[mid] > k){
            end = mid - 1;
            end_index = end_index - end;
        }
        else{
            count++;
            break;
        }
        cout << "Mid = " << mid << endl;
        mid = start + (end - start) / 2;
    }
    cout << "start = " << start_index << "end = " << end_index << endl;
    for (int i = start_index; i < end_index; i++)
    {
        count++;
    }
    return count;
}

int main(){

    int arr[] = {13,14,17,23,26,33,35};
    int n = sizeof(arr) / sizeof(arr[0]);
    // sort(arr,arr + n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "elements less than equal to 9 \n" << counts(arr, n, 32);
}