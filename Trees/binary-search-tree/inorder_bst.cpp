#include<iostream>
#include<vector>
using namespace std;


struct TreeNode{
    int data;
    TreeNode *right, *left;
    TreeNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode *inorder_bst(TreeNode *root,vector<int>arr,int s,int e){
    if(s <= e){
        int mid = s + (e - s) / 2;
        root = new TreeNode(arr[mid]);
        root->left = inorder_bst(root->left, arr, s, mid - 1);
        root->right = inorder_bst(root->right, arr, mid + 1, e);
    }
    return root;
}

void display_i(TreeNode *root){
    if(root == NULL){
        return;
    }
    display_i(root->left);
    cout << root->data << " ";
    display_i(root->right);
}
int main()
{
    vector<int> arr;
    arr.push_back(40);
    arr.push_back(50);
    arr.push_back(60);
    arr.push_back(70);
    arr.push_back(32);
    arr.push_back(49);
    arr.push_back(59);
    TreeNode *root = NULL;
    root = inorder_bst(root, arr, 0, arr.size() - 1);
    display_i(root);
}