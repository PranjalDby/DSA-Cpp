#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int d;
    Node *left, *right;
    Node(int data):d(data){
        left = NULL;
        right = nullptr;
    }
};
Node *createNodes(Node *root,int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(root->d > d){
        root->left = createNodes(root->left, d);
    }
    else if(root->d < d){
        root->right = createNodes(root->right, d);
    }
    
    return root;
}

void Level(Node *root){
    if(root == NULL){
        return;
    }
    else{
        queue<Node *> qu;
        qu.push(root);
        while(!qu.empty()){
            Node *curr = qu.front();
            qu.pop();
            cout << curr->d << " ";
            if (curr->left)
            {
                qu.push(curr->left);
            }
            if(curr->right){
                qu.push(curr->right);
            }
        }
    }
}
bool isPresent(Node *root,int key){
    bool ans = false;
    if(root == NULL){
        return false;

    }
    else{
        if (root->d > key)
        {
            ans = isPresent(root->left, key);
        }
        else if(root->d < key){
            ans = isPresent(root->right, key);
        }
        else{
            ans = true;
        }
    }

    return ans;


}

int getMax(Node *root){

    int max = INT_MIN;
    Node *ptr = root;
    while(ptr != NULL){
        if(ptr->d > max){
            max = ptr->d;
        }
        ptr = ptr->right;
    }

    return max;
}

int main()
{
    int arr[] = {6, 2, 8, 7, 9,87,65};
    Node *root = NULL;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]);i++){
        root = createNodes(root, arr[i]);
    }
    Level(root);
    cout << "\n";
    cout << (isPresent(root, 20) ? "Present " : "Not Present") << endl;
    cout << "Maximum element is = " << getMax(root);
}
