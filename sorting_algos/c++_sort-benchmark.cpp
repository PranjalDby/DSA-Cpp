#include<iostream>
#include<random>
#include<thread>
using namespace std;

void insertion_sort(int *arr,int n){
    for (int i = 0; i < n;i++){

    }
}
int main(int argc,char *argv[]){
    srand(time(0));
    cout << "No of command line argument passed = " << argc << endl;
    if(argc > 1){
        long int length = strtol(argv[argc - 1], nullptr, 10);
        cout << length << endl;
        long long int *arr;
        arr = new long long int[length];
        for (int i = 0; i < length;i++){
            arr[i] = rand();
        }
        thread sort_thread(insertion_sort, arr, length);
        sort_thread.join();
        for (int i = 0; i < length;i++){
            cout << arr[i] << "\n";
        }
    }
}