#include<iostream>

using namespace std;


struct Node{
    int data;
    Node *left, *right;
    Node(int s){
        data = s;
        left = right = nullptr;
    }
};
void create_left__skewed(Node **root,int d){
    if(!root || !*root){
        Node *newnode = new Node(d);
        *root = newnode;
        return;
    }
    else{
        create_left__skewed(&((*root)->left), d);
        return;
    }
}
void create_right__skewed(Node **root,int d){
    if(!root || !*root){
        Node *newnode = new Node(d);
        *root = newnode;
        return;
    }
    else{
        create_right__skewed(&((*root)->right), d);
        return;
    }
}
void ds(Node *root,char f){
    if(root == NULL){
        cout << "X" << endl;
        return;
    }
    if(f == 'L'){
        cout <<" "<<root->data << "\n" << "/" << "\n";
        ds(root->left,'L');
    }
    else{
        cout << " " << root->data << "\n"
             << "\\" << "\n";
        ds(root->right, 'R');
    }

}
int main()
{
    int n;
    cout << "No of Nodes\n";
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {

        int d;
        cin >> d;
        create_right__skewed(&root, d);
    }
    ds(root,'R');
}