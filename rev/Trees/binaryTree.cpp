#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

queue<Node *> q;
void insertBinary(Node **root,int d){
    if (*root == NULL)
    {
        Node *newnode = new Node(d);
        *root = newnode;
        return;
    }
    else {
        if(q.size() == 0){
            q.push(*root);
        }
        //is left subtree is null
        Node *curr = q.front();
        if (curr->left == NULL){
            Node *newnode = new Node(d);
            curr->left = newnode;
            q.push(curr->left);
            return;
        }
        if(curr->right == NULL){
            Node *newnode = new Node(d);
            curr->right = newnode;
            q.push(curr->right);
        }
        q.pop();
    }
}
void printInorder(Node *root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    int arr[8] = {5, 3, 8, 1, 6, 9, 2, 7};
    Node *root = NULL;
    for(int i = 0; i < 8; i++) {
        insertBinary(&root, arr[i]);
    }
    
    // Additional code to print or use the tree can be added here
    printInorder(root);
    return 0;
}