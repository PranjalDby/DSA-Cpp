#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    // creating stack using standard tempelate library
    stack<int> stk1;
    stk1.push(10);
    stk1.push(20);
    stk1.push(40);
    cout << "Top element is = " << stk1.top() << endl;
    cout << "is empty = " << stk1.empty() << endl;
    return 0;
}