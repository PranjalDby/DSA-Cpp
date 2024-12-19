#include <iostream>
#include <string.h>
using namespace std;

class Stack
{
public:
    int data;
    int size;
    char *arr;
    int top;
    Stack(int size)
    {
        this->top = -1;
        this->size = size;
        this->arr = new char[size];
    }
    void push(char data)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = data;
        }
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "Underflow.\n";
            return ' ';
        }
        char res = arr[top];
        top--;
        return res;
    }
};
int main()
{
    string s;
    cout << "Enter the string." << endl;
    getline(cin, s);
    Stack stk(s.length());
    for (int i = 0; s[i] != '\0'; i++)
    {
        stk.push(s[i]);
    }

    cout << "actula reversal.\n";
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        res += stk.pop();
    }
    cout << "reversed string is = " << res;
    return 0;
}