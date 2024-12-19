//constructing binary tree from pre-order and inorder traversal.
#include<iostream>
using namespace std;


struct Node{
    int data;
    Node *left,*right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

int getpos(int inord[],int element,int n){
    for (int i = 0; i < n;i++){
        if(inord[i] == element){
            return i;
        }
    }
    return -1;
}
Node *createTreeFrom(int inord[],int preord[],int &index,int preorder_start,int preorder_end,int n){
    if(index >=n){
        return nullptr;
    }
    if(preorder_start > preorder_end){
        return nullptr;
    }
    int element = preord[index++];
    Node *root = new Node(element);
    int inorder_pos = getpos(inord, element, n);

    // creating left-subtree;
    root->left = createTreeFrom(inord, preord, index, preorder_start, inorder_pos + 1, n);

    // creating right-subtree;
    root->right = createTreeFrom(inord, preord, index, inorder_pos + 1, preorder_end, n);
    return root;
}
void displayPost(Node *root){
    if(root == NULL){
        return;
    }

    displayPost(root->left);
    displayPost(root->right);
    cout << root->data << " ";
}
int main()
{
    int inord[] = {3, 1, 4, 0, 5, 2};
    int preor[] = {0, 1, 3, 4, 2, 5};
    int n1 = sizeof(inord) / sizeof(inord[0]);
    int n2 = sizeof(preor) / sizeof(preor[0]);
    Node *root = nullptr;
    int preorderIndex = 0;
    root = createTreeFrom(inord, preor, preorderIndex, 0, n1 - 1, n1);
    displayPost(root);
}