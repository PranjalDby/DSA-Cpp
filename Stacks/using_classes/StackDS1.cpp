#include <iostream>
using namespace std;

class Stack
{
public:
    int p;
    int capacity;
    int *arr;
    Stack(int size) : p(-1), capacity(size)
    {
        arr = new int[capacity];
    };
    void push(int data);
    void pop();
    int top();
    bool isEmpty();
};
void Stack::push(int data)
{
    if (p >= capacity - 1)
    {
        cout << "Overflow." << endl;
    }
    else
    {
        cout << "Inserted Successfully." << endl;
        p = p + 1;
        arr[p] = data;
    }
}
void Stack::pop()
{
    if (p == -1)
    {
        cout << "Underflow Condition.\n";
    }
    else
    {
        arr[p] = -1;
        p = p - 1;
    }
}
bool Stack::isEmpty()
{
    if (p == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Stack::top()
{
    if (p == -1)
    {
        return -1;
    }
    return arr[p];
}
int main()
{
    Stack stk(5);
    stk.push(30);
    stk.push(50);
    stk.push(60);
    stk.push(90);
    stk.push(190);
    stk.pop();
    stk.push(290);
    cout << stk.top();
    return 0;
}
