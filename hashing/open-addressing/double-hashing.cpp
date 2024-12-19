#include<iostream>
using namespace std;

#define empty -99999

int *ht;
int tablesize = 7;

int hash1(int k){
    return k % tablesize;
}
int returnLargestPrime(){
    int max = INT_MIN;
    for (int i = 0; i < tablesize;i++){
        bool isPrime = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            if(max < i){
                max = i;
            }
        }
    }
    return max;
}
void insert(int k){
    int hashkey1 = hash1(k);
    int lprime = returnLargestPrime();
    // cout << lprime;
    int hashkey2 = lprime - (k % lprime);
    //qudratic probing kinda
    for (int i = 1; i <= tablesize;i++){
        int newloc = (hashkey1 + hashkey2 * i) % tablesize;
        if(newloc < tablesize && ht[newloc] == empty){
            ht[newloc] = k;
            return;
        }

    }
}
int main()
{
    int arr[] = {10, 2, 7, 9, 33, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    ht = new int[tablesize];
    for (int i = 0; i < tablesize;i++){
        ht[i] = empty;
    }
    for (int i = 0; i < n;i++){
        insert(arr[i]);
    }
    for (int i = 0; i<tablesize;i++){
        printf("%d ", ht[i]);
    }
}