#include<iostream>
using namespace std;
#include <cmath>

int *ht;
int maxsize = 10;
#define empty -9999
int midSquare(int key)
{
    int square = key * key;
    cout << "Square = " << square << endl;
    // no of digits;
    int ndigit = log10(square) + 1;
    cout << "Ndigit = " << ndigit << endl;
    int middle = (ndigit / 2) - 1;
    cout << "middle digit = " << middle << endl;
    int p = pow(10, middle);
    int divisor = square / p;
    cout << divisor << endl;
    return divisor % maxsize;
}
void linearprobe(int key){
    int loc = midSquare(key);
    if(ht[loc] == -1){
        ht[loc] = key;
        cout << "Insertion Successfull\n";
        return;
    }
    cout << "Collision\n probe until we find empty slot or -1 which means no data is ever inserted";
    while(ht[loc] != -1 && ht[loc] != empty){
        loc = (loc + 1) % maxsize;
    }
    ht[loc] = key;
    return;
}
int deletekey(int key){
    int loc = midSquare(key);
    while (ht[loc] != -1){
        if(ht[loc] == key){
            ht[loc] = empty;
            return key;
        }
        loc = (loc + 1) % maxsize;
    }
    return -1;
}
int main()
{
    // cout << midSquare(1711);
    ht = new int[maxsize];
    for (int i = 0;i<maxsize;i++){
        ht[i] = -1;
    }
    int arr[8] = {23, 45, 12, 67, 34, 89, 78, 56};
    for (int i = 0; i < 8; i++) {
        linearprobe(arr[i]);
    }
    deletekey(34);
    linearprobe(34);
    linearprobe(74);
    for (int i = 0; i < maxsize; i++)
    {
        if (ht[i] != -1) {
            cout << "Index " << i << ": " << ht[i] << endl;
        }
    }
}