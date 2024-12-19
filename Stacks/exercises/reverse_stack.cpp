#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }
    int el = stack.top();
    stack.pop();
    insertAtBottom(stack, x);
    stack.push(el);
}
void reverseStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
    {
        return;
    }
    // top element side me rakh rahe hai
    int top = stack.top();
    stack.pop();
    cout << "Top = " << top << "\n";
    // reverse
    reverseStack(stack);
    cout << "after reverse Top = " << top << "\n";
    insertAtBottom(stack, top);
}

int main()
{
    stack<int> stk;
    for (int i = 0; i < 5; i++)
    {
        int el;
        cin >> el;
        stk.push(el);
    }
    reverseStack(stk);
}