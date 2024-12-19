#include <iostream>
using namespace std;

struct Node{
    int data;
    int priority;
    Node *next;
};
void push(Node **root,int data,int p){
    if(*root == NULL){
        Node *newnode = new Node();
        newnode->data = data;
        newnode->priority = p;
        *root = newnode;
        return;
    }
    else{
        Node *start = *root;
        Node *newnode = new Node();
        newnode->data = data;
        newnode->priority = p;
        if((*root)->priority < newnode->priority){
            // if root-Node priority is less than newnode;
            //then make newnode as root node
            newnode->next = *root;
            *root = newnode;
        }
        else{
            //if root->priority is greater than newnode then find the node whose priority is less than newnodes
            Node *p = *root;
            while(p->next != NULL && p->next->priority > newnode->priority){
                p = p->next;
            }
            //now p is pointing to the element whose next element priority is less than newnode priority.
            if(p!=NULL){
                cout << "P is Not NULL\n";
                Node *t = p->next;
                p->next = newnode;
                newnode->next = t;
            }
        }
    }
}
int pop(Node **root){
    if(root == NULL || (*root) == NULL){
        cout << "queue is empty\n";
        return -1;
    }
    else{
        int i = 0;
        Node *t = *root;
        *root = (*root)->next;
        i = t->data;
        delete t;
        return i;
    }
}
int peek(Node **root){
    //return the top-most element
    if (root == NULL || *root == NULL)
    {
        cout << "queue is empty\n";
        return -1;
    }
    else{
        Node *ptr = *root;
        return ptr->data;
    }
}
int main()
{
    Node *root = NULL;
    while (true)
    {
        cout << "1: for push 2: pop 3:front 4:back:: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Push\n";
            cout << "enter the data and priority: \n";
            int data,p;
            cin >> data >> p;
            
            push(&root, data, p);
            break;
        case 2:
            cout << "Pop\n";
            cout << "Popped data is = " << pop(&root) << endl;
            break;
        case 3:
            cout << "Front dat =\n";
            cout <<peek(&root)<< endl;
            break;
        default:
            exit(0);
            break;
        }
    }

    return 0;
}