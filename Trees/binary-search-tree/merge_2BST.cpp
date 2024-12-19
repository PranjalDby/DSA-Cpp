#include<iostream>
using namespace std;

struct Node
{
    int d;
    Node *left, *right;
    Node(int data)
    {
        d = data;
        left = right = NULL;
    }
};

Node *createBst(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (root->d > d)
    {
        root->left = createBst(root->left, d);
    }
    else if (root->d < d)
    {
        root->right = createBst(root->right, d);
    }
    return root;
}

void inorder(Node *root, vector<int> &res){
    if(root == NULL){
        
        return;
    }
    int ans = -1;
    inorder(root->left,res);
    res.push_back(root->d);
    inorder(root->right, res);
    
}
void inorder_print(Node *root){
    if(root == NULL){
        
        return;
    }
    int ans = -1;
    inorder_print(root->left);
    cout << root->d << " ";
    inorder_print(root->right);
}

vector<int> merge_two(vector<int>res1,vector<int>res2){
    vector<int> merged;
    int i = 0;
    int j = 0;
    while(i<res1.size() && j < res2.size()){
        if(res1[i] > res2[j]){
            merged.push_back(res2[j]);
            j++;
        }
        else{
            merged.push_back(res1[i]);
            i++;
        }
    }

    // for-remaining element
    while(i<res1.size()){
        merged.push_back(res1[i]);
        i++;
    }
    while(j<res2.size()){
        merged.push_back(res2[j]);
        j++;
    }

    return merged;
}
int main(){
    int arr1[] = {50, 40, 60, 70};
    int arr2[] = {55,45,67,35,47};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *root1 = NULL;
    Node *root2 = NULL;

    for (int i = 0; i < n1;i++){
        root1 = createBst(root1, arr1[i]);
    }
    for (int i = 0; i < n2;i++){
        root2 = createBst(root2, arr2[i]);
    }
    vector<int> res1;
    vector<int> res2;
    inorder(root1,res1);
    inorder(root2, res2);
    vector<int> res = merge_two(res1, res2);
    for (int i : res)
    {
        cout << i << " ";
    }

    cout << "Creating BST with merged Nodes\n";
    Node *root3 = NULL;
    for (int i = 0; i < res.size();i++){
        root3 = createBst(root3, res[i]);
    }
    inorder_print(root3);
}