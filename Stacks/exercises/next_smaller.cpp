#include <stack>
#include<iostream>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> stack;
    stack.push(-1);
    vector<int> res(n);
    for (int i = n-1; i>=0; i--)
    {
        int curr = arr[i];
        while (stack.top() >= curr){
            stack.pop();
        }
        res[i] = stack.top();
        stack.push(curr);
    }
    return res;
}
vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> stack;
    stack.push(-1);
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (stack.top() >= curr){
            stack.pop();
        }
        res[i] = stack.top();
        stack.push(curr);
    }
    return res;
}

int main(){
    vector<int> arr(4);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 3;
    vector<int> res = prevSmallerElement(arr, arr.size());
    for(auto i:res){
        cout << i << endl;
    }
}