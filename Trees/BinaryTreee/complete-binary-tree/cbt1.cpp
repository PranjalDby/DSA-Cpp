#include<iostream>
#include<queue>
using namespace std;

// complete-binary is a binary tree in which all level's are completely filled except the last level.and node inserted from left to right fashion

struct Node{
    int d;
    Node *left, *right;
    Node(int dd){
        d = dd;
        left = NULL;
        right = NULL;
    }
};

void createCompleteBinaryTree(Node **root, int d)
{
    if (*root == NULL || root == nullptr)
    {
        Node *newnode = new Node(d);
        *root = newnode;
        return;
    }
    else
    {
        queue<Node *> q;
        q.push(*root);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (!temp->left)
            {
                temp->left = new Node(d);
                return;
            }
            else
            {
                q.push(temp->left);
            }
            if (!temp->right)
            {
                temp->right = new Node(d);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
}
void display(Node *root){
    if(root == NULL){
        return;
    }
    display(root->left);
    cout << root->d << " ";
    display(root->right);
}

void lvl_order(Node *root)
{
    
    if(root == NULL){
        return;
    }
    else{
        queue<Node *> q1;
        q1.push(root);
        q1.push(NULL);
        while (!q1.empty())
        {
            Node *t = q1.front();
            q1.pop();
            if(t == NULL){
                cout << endl;
                if(!q1.empty()){
                    q1.push(NULL);
                }
            }
            else{
                cout << t->d << " ";
                if(t->left){
                    q1.push(t->left);
                }
                if(t->right){
                    q1.push(t->right);
                }
            }
        }
    }
}

bool isCBT(Node *root){
    queue<Node *> q;
    if(root == NULL){
        return true
        ;
    }
    else{
        q.push(root);
        bool isEnd = false;
        while(!q.empty()){
            if(q.front()->left){
                if(isEnd){
                    return false;
                }
                q.push(q.front()->left);
            }
            else{
                isEnd = true;
            }
            if(q.front()->right){
                if(isEnd){
                    return false;
                }
                q.push(q.front()->right);
            }
            else{
                isEnd = true;
            }
            q.pop();
        }
        return true;
    }
}
int main()
{
    int arr[] = {20, 34, 56, 78, 92, 50, 110, 45, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n << endl;
    Node *root = NULL;
    // root->left = new Node(34);
    // root->right= new Node(78);
    // root->left->left = new Node(89);
    for (int i = 0; i < n; i++)
    {
        createCompleteBinaryTree(&root, arr[i]);
    }
    // display(root);
    lvl_order(root);
    cout << endl;
    // cout << isCBT(root);
    // display(root);
}