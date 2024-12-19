#include<iostream>
#include<stack>

using namespace std;


int eval_exp(string arr,int n){
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '*' || arr[i] == '+' || arr[i] == '-' || arr[i] == '/'){
            if(!stk.empty()){
                int a = static_cast<int>(stk.top());
                stk.pop();
                int b = static_cast<int>(stk.top());
                stk.pop();
                int res = 0;
                switch (arr[i])
                {
                case '*':
                    res = a * b;
                    break;
                case '/':
                    res = b / a;
                    break;
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = b - a;
                    break;

                default:
                    break;
                }
                stk.push(res);
            }
        }
        else if (isdigit(arr[i]))
        {
           
            int r = static_cast<int>(arr[i]-'0');
            cout << r << endl;
            stk.push(r);
        }
    }
    return stk.top();
}
int main(){
    string exp = "231*9+-";

    cout << eval_exp(exp, exp.size()) << endl;
    ;
}