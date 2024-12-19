#include<iostream>
#include <algorithm>
using namespace std;

#define empty -99999
int tableSize = 7;
int *ht;
int prob = 0;

int hash_func(int k)
{
    return k % tableSize;
}
void insert(int k){
    int loc = hash_func(k);
    //probing for empty slot
    while(ht[loc] != empty && ht[loc] != -1){
        prob++;
        loc = (loc + 1) % tableSize;
    }
    ht[loc] = k;
}

bool search(int k){
    int loc = hash_func(k);
    //prob until ht[loc] != k or you find the key or an empty slot occured
    int i = 0;//to prevent infinite probing
    while (ht[loc] != k && i < tableSize)
    {
        if (ht[loc] == empty){
            printf("failed to find the key\n");
            return false;
        }
        loc = (loc + 1) % tableSize;
        i++;
    }
    if(ht[loc] == k){
        return true;
    }
    return false;
}
int deleteKey(int k){
    int loc = hash_func(k);
    int deleted = -1;
    while (ht[loc] != empty)
    {
        printf("eee\n");
        if (ht[loc] == k)
        {
            printf("found the key: %d\n", ht[loc]);
            deleted = ht[loc];
            ht[loc] = -1;
            return deleted;
        }
        loc = (loc + 1) % tableSize;
    }
    return -1;
}
int main()
{
    int arr[] = {10, 20, 11, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    ht = new int[tableSize];
    for (int i = 0; i < tableSize;i++){
        ht[i] = empty;
    }
    for (int i = 0; i < n;i++){
        insert(arr[i]);
    }
    for (int i = 0; i < tableSize;i++){
        cout << ht[i] << " ";
    }
    printf("\n");
    printf("deleting a key\n");
    int de = deleteKey(11);
    de = deleteKey(9);
    printf("is 7 present %d\n", search(7));
    printf("%d\n", de);
    // insert(9);
    for (int i = 0; i < tableSize; i++)
    {
        cout << ht[i] << " ";
    }
}