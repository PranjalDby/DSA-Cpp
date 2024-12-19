#include<iostream>

using namespace std;


struct Node{
    int d;
    Node *left,*right;
    Node(int data){
        d = data;
        left = right = NULL;
    }
};

Node *createBst(Node *root,int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(root->d > d){
        root->left = createBst(root->left, d);

    }
    else if(root->d < d){
        root->right = createBst(root->right, d);
    }
    return root;
}
Node * succecessor(Node *root,int key){
    // finding the node with minimum value in right-subtree's left -part
    int min = key;
    while (root->left != NULL)
    {
        if(min < root->d){
            min = root->d;
        }
        root = root->left;
    }
    return root;
}
Node *deleteNode(Node *root,int key){
    //base case
    if(root == NULL){
        return NULL;
    }
    //left-subtree
    if(root->d > key){
        root->left = deleteNode(root->left, key);
    }
    else if(root->d < key){
        //right-subtree
        root->right = deleteNode(root->right, key);
    }
    else{
        // if we found the key;
        // if it has single child either left or right;
        if(root->left != NULL && root->right == NULL){
            Node *t = root->left;
            delete root;
            return t;
        }
        else if(root->right != NULL && root->left == NULL){
            Node *t = root->right;
            delete root;
            return t;
        }
        else if(root->left != NULL && root->right != NULL){
            //if both the childs are present
            //we have to replace root with its inorder successor or inorder predecessor
            Node *inorder_succ = succecessor(root->right, key);
            swap(root->d, inorder_succ->d);
            //because of inorder of successor the element is moved to the right-subtree. so we have to do this tasks in right-subtree also.
            root->right = deleteNode(inorder_succ, key);
            return root;
        }
        else{
            //if it is a leaf Node.
            return NULL;
        }
    }
    return root;
}
void inorder(Node *root){
    if(root == NULL){
        cout << "\nX\n";
        return;
    }
    inorder(root->left);
    cout << root->d << "\n";
    inorder(root->right);
    cout << " ";
}
int
main()
{
    int arr[] = {50,30,70,80,20,35};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = createBst(root, arr[i]);
    }
    root = deleteNode(root,50);
    root = deleteNode(root, 30);
    // root = deleteNode(root, -34);
    inorder(root);
}