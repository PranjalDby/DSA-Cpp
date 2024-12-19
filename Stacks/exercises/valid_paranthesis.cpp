#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isValidParenthesis(string s)
{
    stack<char> stack;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (!stack.empty() && stack.top() == '(' && s[i] == ')')
            {
                stack.pop();
            }
            else if (!stack.empty() && stack.top() == '{' && s[i] == '}')
            {
                stack.pop();
            }
            else if (!stack.empty() && stack.top() == '[' && s[i] == ']')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return stack.empty();
}

int main()
{
    string s = "}])]";
    cout << isValidParenthesis(s);
}