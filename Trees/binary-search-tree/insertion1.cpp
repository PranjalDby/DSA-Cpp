#include<iostream>

using namespace std;


struct Node{
    int data;
    Node *right, *left;
    Node(int d) : data(d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};
Node *createNode(Node *root,int d){
    if(root == NULL){
        Node *newnode = new Node(d);
        root = newnode;
        return root;
    }
    else{
        if(root->data > d){
            root->left = createNode(root->left, d);
        }
        else{
            root->right = createNode(root->right, d);
        }
    }
    return root;
}

Node *insert_node(Node *root,int data){
    if(root == NULL){
        Node *newnode = new Node(data);
        root = newnode;
        return root;
    }
    else{
        if(root->data < data){
            root->right = insert_node(root->right, data);
        }
        else if(root->data > data){
            root->left = insert_node(root->left, data);
        }
        return root;
    }
}
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << "\n";
    inorder(root->right);
}
void post(Node *root){
    if(root == NULL){
        return;
    }
    post(root->left);
    post(root->right);
    cout << root->data << "\n";
}
int main()
{
    int arr[] = {100, 20, 500, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = createNode(root, arr[i]);
    }
    root = insert_node(root, 87);
    post(root);
}