#include<iostream>
#include<cmath>
using namespace std;

int getHash(int key,int n){
    long long square = static_cast<long long>(key) * key;
    int num_digits = log10(square) + 1;//get the no of digits
    int middle = (num_digits / 2) - 1; // finding the middle two digits;
    int divisor = pow(10, middle);     // removing trailling digits
    int count_size_digit = log10(n) + 1;
    cout << "no of digits required = " << count_size_digit << endl;
    int to_divide = pow(10, count_size_digit - 1);
    int middle_dig = (square / divisor) % to_divide;
    return middle_dig % n;
}
int main(){
    int key = 122;
    int n = 1000;
    cout << "Hash value = " << getHash(key, n);
}