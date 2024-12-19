#include <iostream>
#include <stack>
using namespace std;
void sorted(stack<int> &stk, int el)
{
    if (stk.empty() || stk.top() < el)
    {
        stk.push(el);
        return;
    }
    int top = stk.top();
    stk.pop();
    sorted(stk, el);
    stk.push(top);
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
    {
        return;
    }
    int el = stack.top();
    stack.pop();
    sortStack(stack);
    sorted(stack, el);
}

int main()
{
}