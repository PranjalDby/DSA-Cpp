#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
void createTree(Node **tree,int d){
    if(*tree == NULL){
        Node *newnode = new Node(d);
        *tree = newnode;
    }
    else{
        queue<Node *> qu;
        qu.push(*tree);
        while(!qu.empty()){
            Node *curr = qu.front();
            qu.pop();
            if(curr->left){
                qu.push(curr->left);
            }
            else{
                curr->left = new Node(d);
                return;
            }
            if(curr->right){
                qu.push(curr->right);
            }
            else{
                curr->right = new Node(d);
                return;
            }
        }
    }
}
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void inorder_iter(Node *root){
    if(root == NULL){
        return;
    }
    Node *ptr = root;
    stack<Node *> s;
    vector<int> d;
    while(ptr != NULL || !s.empty()){
        while(ptr != NULL){
            s.push(ptr);
            ptr = ptr->left;
        }
        ptr = s.top();
        s.pop();
        d.push_back(ptr->data);
        ptr = ptr->right;
    }
    for(int i : d){
        cout << i << " ";
    }
}
void preorder_iter(Node *root){
    if(root == NULL){
        return;
    }
    Node *ptr = root;
    stack<Node *> s;
    vector<int> d;
    while(ptr != NULL || !s.empty()){
        while(ptr != NULL){
            s.push(ptr);
            d.push_back(ptr->data);
            ptr = ptr->left;
        }
        ptr = s.top();
        s.pop();
        
        ptr = ptr->right;
    }
    for(int i : d){
        cout << i << " ";
    }
}
void post_iter(Node *root){
    if(root == NULL){
        return;
    }
    stack<Node *> s;
    stack<bool> visited;
    vector<int> d;
    visited.push(false);
    s.push(root);
    while (!s.empty())
    {
        Node *curr = s.top();
        bool visit = visited.top();
        s.pop();
        visited.pop();
        if(curr){
            if(visit){
                d.push_back(curr->data);
            }
            else{
                visited.push(true);
                s.push(curr);
                s.push(curr->right);
                visited.push(false);
                s.push(curr->left);
                visited.push(false);
            }
        }
    }
    for(int i : d){
        cout << i << " ";
    }
}
void preorder(Node *root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    Node *root = NULL;
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        createTree(&root, arr[i]);
    }
    // inorder_iter(root);
    post_iter(root);
    // postorder(root);
    return 0;
}