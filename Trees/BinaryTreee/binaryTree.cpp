#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// using level order traversal
queue<Node *> q;
void createBinaryTree(Node **root, int data)
{
    if (!*root)
    {
        Node *newnode = new Node(data);
        *root = newnode;
        return;
    }
    else
    {
        q.push(*root);
        if (!q.front()->left)
        {
            Node *newnode = new Node(data);
            q.front()->left = newnode;
            q.push(q.front()->left);
            return;
        }
        if (!q.front()->right)
        {
            Node *newnode = new Node(data);
            q.front()->right = newnode;
            q.push(q.front()->right);
            q.pop();
        }
    }
}

void level_order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
    }
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = NULL;
    int arr[10] = {1, 2, 3, 4, 5};
    // fill_n(arr, 10, 2);
    vector<vector<int> > matrix(5, (vector<int>(5, 0)));
    // Resize the third column (index 2) of the matrix to have 10 elements
    for (int i = 0; i < 5; i++)
    {
        matrix[i].resize(10);
    }
    // for (int i = 0; i < 5; i++)
    // {
    //     createBinaryTree(&root, arr[i]);
    // }
    // level_order(root);
    cout << "-2 becomes = " << abs(-2);
    unordered_map<int, int> map;
    for (int i = 0; i < 5;i++){
        map[i] = arr[i];
    }
    for(auto i:map){
    }
    return 0;
}