#include<iostream>
using namespace std;


/**
 * @brief Sorts an array using the insertion sort algorithm.
 * 
 * Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. 
 * It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
 * 
 * The algorithm divides the array into a sorted and an unsorted region. It iteratively takes an element from the unsorted region 
 * and inserts it into the correct position in the sorted region. This process is repeated until the entire array is sorted.
 * 
 * Time Complexity:
 * - Best case: O(n) when the array is already sorted.
 * - Average and Worst case: O(n^2) when the array is in reverse order.
 * 
 * Space Complexity: O(1) as it is an in-place sorting algorithm.
 * 
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void insertionsort(int arr[],int n){
    /**
    @brief outer loop from i - n-1 is traverse through unsorted portion
    @brief inner loop from j = i-1 to 0 traverse through sorted portion
    */
    for (int i = 1; i < n - 1;i++){
        int small = arr[i];
        int j = i - 1;
        //travset until we get element less than our current smallest element and j >= 0
        while(j>=0 && arr[j] > small){
            //right-shift the larger element
            arr[j + 1] = arr[j];
            j--;
        }
        //put the element into its correct position
        arr[j + 1] = small;
    }
}
int main(){
    int arr[6] = {5, 2, 9, 1, 5, 6};
    int n = 6;
    insertionsort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}