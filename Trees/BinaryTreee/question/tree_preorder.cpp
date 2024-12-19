//building a binary tree from pre-order

#include<iostream>
using namespace std;

struct Node{
    int d;
    Node *left, *right;
    Node(int dd){
        d = dd;
        left = right = NULL;
    }
};
int main()
{
    int arr[] = {8, 5, 1,-1,-1, 7, 10,-1, 12,-1,-1};
    int n = sizeof(arr) / sizeof(arr[0]);
}