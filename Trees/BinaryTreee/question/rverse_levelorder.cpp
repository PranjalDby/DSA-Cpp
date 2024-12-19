#include <iostream>
#include<queue>
using namespace std;

struct node{
    int d;
    node *left, *right;
    node(int dd){
        d = dd;
        left = right = nullptr;
    }
};
void createNode(node **root,int d){
    if(root == nullptr || *root == nullptr){
        node *newnode = new node(d);
        *root = newnode;
        return;
    }
    else{
        queue<node *> q;
        q.push(*root);
        while(!q.empty()){
            node *curr = q.front();
            q.pop();
            if(!curr->left){
                curr->left = new node(d);
                return;
            }
            else{
                q.push(curr->left);
            }
            if(!curr->right){
                curr->right = new node(d);
                return;
            }
            else{
                q.push(curr->right);
            }
        }
    }
}
void display(node *root){
    if(root == nullptr){
        return;
    }
    else{
        queue<node *> q;
        q.push(root);
        while(!q.empty()){
            node *curr = q.front();
            cout << curr->d << " ";
            q.pop();
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
    }
}
void display_rev(node *root){
    if(root == nullptr){
        return;
    }
    else{
        queue<node *> q;
        stack<node *> st;
        q.push(root);
        while(!q.empty()){
            node *curr = q.front();
            q.pop();
            st.push(curr);
            if(curr->right){
                q.push(curr->right);
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
        }

        while (!st.empty())
        {
            node *curr = st.top();
            cout << curr->d << " ";
            st.pop();
        }
     }
}
int main()
{
    int arr[] = {10, 20, 65,76, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        createNode(&root, arr[i]);
    }
    display_rev(root);
    return 0;
}