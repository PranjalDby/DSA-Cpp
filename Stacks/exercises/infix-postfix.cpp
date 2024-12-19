#include <iostream>
#include<stack>
using namespace std;


int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if(c== '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}
void infix_post(string s){
    stack<char> st;
    string res = "";
    for (int i = 0; i < s.length();i++)
    {
        if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                //remove closing bracket
                st.pop();
            }
        }
        else if(isalpha(s[i])){
            res += s[i];
        }
        else{
            while (!st.empty() && prec(st.top()) > prec(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    cout << res << endl;
}
int main(){

    string s = "(a-b/c)*(a/k-l)";
    infix_post(s);

    return 0;
}