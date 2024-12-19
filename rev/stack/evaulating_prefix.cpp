#include<iostream>
#include<stack>

using namespace std;
int evaluate(string exp){
    stack<int> st;
    int l = exp.size() - 1;
    int res = 0;
    for (int i = l; i >= 0; i--)
    {
        if(isdigit(exp[i])){ 
           int d = exp[i] - '0';
           st.push(d);
        }
        else{
            vector<int>arr(2,0);
            arr[0] = st.top();
            st.pop();
            arr[1] = st.top();
            st.pop();
            switch (exp[i])
            {
            case '+':
                st.push(arr[0] + arr[1]);
                break;
            case '*':
                st.push(arr[0] * arr[1]);
                break;
            case '-':
                st.push(arr[0] - arr[1]);
                break;
            case '/':
                st.push(arr[0] / arr[1]);
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string exp;
    getline(cin, exp);
    cout << evaluate(exp);
}