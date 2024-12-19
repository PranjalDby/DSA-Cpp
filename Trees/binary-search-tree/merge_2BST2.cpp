#include <iostream>
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


void inorder_print(Node *root)
{
    if (root == NULL)
    {

        return;
    }
    int ans = -1;
    inorder_print(root->right);
    cout << root->d << " ";
}

void createLLFromBst(Node *root,Node **head){
    if(root == NULL){
        return;
    }
    createLLFromBst(root->right, head);
    root->right = *head;
    if (*head != NULL)
    {
        (*head)->left = root;
    }
    *head = root;
    createLLFromBst(root->left, head);
}

int main()
{
    int arr1[] = {50, 40, 60, 70};
    int arr2[] = {55, 45, 67, 35, 47};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    Node *root1 = NULL;
    Node *root2 = NULL;

    for (int i = 0; i < n1; i++)
    {
        root1 = createBst(root1, arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        root2 = createBst(root2, arr2[i]);
    }

    Node *h1 = NULL;
    Node *h2 = NULL;
    createLLFromBst(root1, &h1);
    createLLFromBst(root2, &h2);
    inorder_print(h1);
    inorder_print(h2);
}