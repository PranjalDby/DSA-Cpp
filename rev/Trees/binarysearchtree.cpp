#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *insert(Node *root,int data){
    if(root == NULL){
        Node *newnode = new Node(data);
        root = newnode;
        return root;
    }
    if(root->data > data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

int getMax(Node *root){
    if(root == NULL){
        return INT_MIN;
    }
    int ans = INT_MIN;
    if (ans < root->data){
        ans = root->data;
    }
    ans = max(ans,getMax(root->right));
    return ans;
}
int getMin(Node *root){
    if(root == NULL){
        return INT_MAX;
    }
    int ans = INT_MAX;
    if (ans > root->data){
        ans = root->data;
    }
    ans = min(ans,getMin(root->left));
    return ans;
}
void preorder(Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void post(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    printf("%d ", root->data);
}
bool search(Node *root,int d){
    if(root == NULL){
        return false;
    }
    bool ans = false;
    if (d < root->data)
    {
        ans = search(root->left, d);
    }
    else if(d > root->data){
        ans = search(root->right, d);
    }
    else{
        return true;
    }
    return ans;
}

int inorder_successor(Node *right_part){
    Node *ptr = right_part;
    int min = INT_MAX;
    while(ptr!=NULL && ptr->data < min){
        min = ptr->data;
        ptr = ptr->left;
    }
    return min;
}
Node *deleted(Node *root,int d){
    if(root == NULL){
        return root;
    }
    if(d < root->data){
        root->left = deleted(root->left, d);
    }
    else if(d > root->data){
        root->right = deleted(root->right, d);
    }
    else{
        printf("Node found\n");
        if (root->left == NULL && root->right == NULL)
        {
            cout << "deleted leaf node\n";
            return NULL;
        }
        else if(root->left!= NULL && root->right == NULL){
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL && root->right != NULL){
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left != NULL && root->right != NULL){
            printf("Node has two childrens\n");
            //find in-order succecessor
            int minimum = inorder_successor(root->right);
            cout << "inoreder successor value = " << minimum << endl;
            root->data = minimum;
            root->right = deleted(root->right, minimum);
        }
    }
    return root;
}
int main()
{
    int arr[] = {5, 3, 8, 1, 6, 9, 2, 7,11};
    Node *root = NULL;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        root = insert(root, arr[i]);
    }
    // preorder(root);
    // inorder(root);
    // post(root);
    root = deleted(root, 8);
    inorder(root);
    // cout << "is present = " << search(root, 15) << endl;
    // cout << "minimum value = " << getMin(root);
}