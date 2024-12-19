#include <iostream>
using namespace std;

struct node
{
    int d;
    node *left, *right;
    node(int dd)
    {
        d = dd;
        left = right = nullptr;
    }
};
void createNode(node **root, int d)
{
    if ((root == nullptr || *root == nullptr) && d >= 0)
    {
        node *newnode = new node(d);
        *root = newnode;
        return;
    }
    else
    {

        queue<node *> q;
        q.push(*root);
        while (!q.empty())
        {
            node *curr = q.front();
            q.pop();
            if (!curr->left)
            {
                curr->left = new node(d);
                return;
            }
            else
            {
                q.push(curr->left);
            }
            if (!curr->right)
            {
               
                curr->right = new node(d);
                return;
            }
            else
            {
                q.push(curr->right);
            }
        }
    }
}

int height(node *root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
pair<bool,int> isBalanced(node *root){
    if(root == NULL){
        return pair<bool,int>(true,0);
    }
    //other cases
    pair<bool,int> left = isBalanced(root->left);
    pair<bool,int> right = isBalanced(root->right);

    bool left_ans = left.first;
    bool right_ans = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if (left_ans && right_ans && diff)
    {
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}
void inorder(node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->d << " ";
    inorder(root->right);
}
pair<bool, int> sumAll(node *root)
{
    if (root == NULL)
    {
        return pair<bool, int>(true, 0);
    }
    if (root->left == NULL && root->right == NULL)
    {
        return pair<bool, int>(true, root->d);
    }
    pair<bool, int> left_sum = sumAll(root->left);
    pair<bool, int> right_sum = sumAll(root->right);

    bool left = left_sum.first;
    bool right = right_sum.first;
    bool ans = root->d == (left_sum.second + right_sum.second);

    pair<bool, int> res;
    if (left && right && ans)
    {
        res.first = true;
        res.second = root->d + left_sum.second + right_sum.second;
    }
    else
    {
        res.first = false;
        res.second = 0;
    }
    return res;
}
bool isSumTree(node *root)
{
    // Your code here
    return sumAll(root).first;
}
int main(){
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    node *root = nullptr;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        createNode(&root, arr[i]);
    }

    inorder(root);
    cout << endl;

    pair<bool, int> result = isBalanced(root);
    if (result.first) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}