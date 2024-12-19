///Quadratic probing
#include<iostream>
#include<cmath>
using namespace std;

#define empty -99999

int *ht;
int tablesSize = 131;
int hash_func(int e){
    int squred = e * e;
    int n_digits = log10(squred) + 1;
    int middle = (n_digits / 2);
    // to remove the trailling digits
    int divisor = pow(10, middle - 1);
    int table_size_digit = log10(tablesSize) + 1;
    int m = squred / divisor;
    // printf("middle = %d\n for %d\n", (m % (int)pow(10,table_size_digit)),e);
    return (middle % (int)pow(10, table_size_digit)) % tablesSize;
}
void insert(int k)
{
    int loc = hash_func(k);
    // printf("loc for %d = %d\n", k, loc);
    for (int i = 1; i <= tablesSize; i++)
    {
        if(ht[loc] == empty || ht[loc] == -1){
            ht[loc] = k;
            return;
        }
        // printf("collision is there\n");
        loc = (hash_func(k) + i * i) % tablesSize;
    }
}

int delete_key(int k){
    int loc = hash_func(k);
    for (int i = 1; i <= tablesSize;i++){
        if(ht[loc] == k){
            int t = ht[loc];
            ht[loc] = -1;
            return t;
        }
        if(ht[loc] == empty){
            printf("delete failed\n");
            return -1;
        }
        loc = (hash_func(k) + i * i) % tablesSize;
    }
    return -1;
}
bool search(int k){
    int loc = hash_func(k);
    for (int i = 1; i <= tablesSize;i++){
        if(ht[loc] == k){
            printf("Key found at %d\n", loc);
            return true;
        }
        if(ht[loc] == empty){
            printf("search error key not found\n");
            return false;
        }
        loc = (hash_func(k) + i * i) % tablesSize;
    }
    return false;
}
int main(){

    int arr[] = {10, 22, 31, 33, 54, 98, 676, 496, 73, 11};
    ht = new int[tablesSize];
    for (int i = 0; i < tablesSize;i++){
        ht[i] = empty;
    }
    printf("inserting into hashTable\n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]);i++){
        insert(arr[i]);
    }
    delete_key(676);
    insert(19);
    for (int i = 0; i < tablesSize; i++)
    {
        if (ht[i] != empty)
        {
            printf("%d ", ht[i]);
        }
    }
   
} 