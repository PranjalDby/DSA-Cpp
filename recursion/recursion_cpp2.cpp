#include <iostream>
#include <queue>
using namespace std;

// int pivot(int arr[],int l,int h){
//     int piv = arr[l];
//     int p = l + 1;
//     int q = h ;
//     while(p<=q){
//         if(arr[p] <= piv){
//             p++;
//         }
//         if(arr[q] >= piv){
//             q--;
//         }
//         if(p<q && arr[p] >= piv){
//             swap(arr[p], arr[q]);
//         }
//     }
//     if(p>=q){
//         swap(arr[l], arr[q]);
//     }
//     return q;
// }
// void divide(int arr[],int l,int h){
//     if(l < h){
//         int p = pivot(arr, l, h);
//         divide(arr, l, p - 1);
//         divide(arr, p+1,h);
//     }
// }
int binarySearch(int arr[],int s,int e,int x){
    if(s > e){
        return -1;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == x){
        return mid;
    }
    if(arr[mid] < x){
        return binarySearch(arr, mid + 1, e, x);
    }
    else{
        return binarySearch(arr, s, mid - 1, x);
    }
}
int fibonacci(int n){
    if(n == 0 || n==1){
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
void merge(int arr[],int l,int mid,int h){
    int n1 = mid - l + 1;
    int n2 = h - mid;
    int L[n1 + 1];
    int R[n2 + 1];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    for (int i = 0; i < n1;i++){
        L[i] = arr[i + l];
    }
    for (int j = 0; j < n2;j++){
        R[j] = arr[mid + j + 1];
    }
    int i = 0, j = 0, k = l;
    while(i<n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void divide(int arr[],int l,int h){
    if(l<h){
        cout << "l = " << l << " : "
             << "h = " << h << endl;
        int mid = l + (h - l) / 2;
        divide(arr, l, mid);
        divide(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}
struct node{
    int data;
    node *next;
    node(int d) : data(d) {
        next = NULL;
    };
};
void createLL(node **head,int data){
    node *newnode = new node(data);
    if (head == NULL || *head == NULL)
    {
        *head = newnode;
        return;
    }
    else{
        cout << "Line 113\n";
        node *ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;

    }
}
node* reverseLL(node *head,node *prev){
    if(head == NULL){
        return prev;
    }
    node *t = head->next;
    head->next = prev;
    return reverseLL(t, head);
}
void displayL(node *head){
    if(head == NULL){
        cout << "Emt\n";
        return;
    }
    node *p = head;
    while(p!= NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
node *mergeLL(node *a,node *b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    if(a->data < b->data){
        a->next = mergeLL(a->next, b);
        return a;
    }
    else{
        b->next = mergeLL(a, b->next);
        return b;
    }
}
struct Node{
    int data;
    Node *left, *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
queue<Node*> q;
void insertInorder(Node **root, int data)
{
    if(!root || !(*root)){
        Node *newnode = new Node(data);
        *root = newnode;
        return;
    }
    else{
        q.push(*root);
        if (!q.front()->left)
        {
            Node *newnode = new Node(data);
            q.front()->left = newnode;
            q.push(q.front()->left);
            return;
        }
        if(!q.front()->right){
            Node *newnode = new Node(data);
            q.front()->right = newnode;
            q.push(q.front()->right);
            q.pop();
        }
    }
}
void printLeaf(Node *root){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        cout << root->data << " ";
    }
    printLeaf(root->left);
    printLeaf(root->right);
}
void display(Node *root){
    if(root == NULL){
        return;
    }
    display(root->left);
    cout << root->data << "\n";
    display(root->right);
}
int main()
{
    int arr[] = {1,2,3,7};
    int arr2[] = {5,6,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // divide(arr, 0,n-1);
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        insertInorder(&head, arr[i]);
    }
    // display(head);
    printLeaf(head);
    // node *head2 = NULL;
    // for (int i = 0; i < n2; i++)
    // {
    //     createLL(&head2, arr2[i]);
    // }

    // display(head);
    // display(head);
    // int a = 0,b = 1;
    // head = reverseLL(head, NULL);
    // cin >> k;
    // for (int i = 0; i < k;i++){
    //     int c = a + b;
    //     cout << a << " " << endl;
    //     a = b;
    //     b = c;
    // }
    // cout << "found at index = " << binarySearch(arr, 0, n - 1, -10) << endl;
    // cout << "Fibonnaci series = " << fibonacci(8);
    // divide(arr, 0, n - 1);
    return 0;
}