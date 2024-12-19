#include<iostream>
#include<stack>
using namespace std;

int prece(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '/' || c == '*'){
        return 2;
    }
    else if(c == '-' || c == '+'){
        return 1;
    }
    return -1;
}
string topostfix(string exp){
    stack<char> st;
    string post = "";
    for (int i = 0; i < exp.size(); i++)
    {
        if(isalpha(exp[i])){
            post += exp[i];
        }
        else if(exp[i] == '('){
            st.push('(');
        }
        else if(exp[i] == ')'){
            while (!st.empty() && st.top()!='(')
            {
                post += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prece(exp[i]) <= prece(st.top())){
                post += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while(!st.empty()){
        post += st.top();
        st.pop();
    }
    return post;
}
int main(){
    string exp = "a+b*c+d";
    cout << "res= " << topostfix(exp);
}