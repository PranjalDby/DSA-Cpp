#include <iostream>
using namespace std;

void selection_sort(int arr[], int n)
{
    // it is kind of stable sorting algorithm where it places smallest element to its correct position during each pass.
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}

int main()
{

    int arr[] = {-1, 9, -7, 2, 13, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    cout << "After sorting = " << endl;
    // selection_sort(arr, size);
    // insertion_sort(arr, size);
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    }

    return 0;
}