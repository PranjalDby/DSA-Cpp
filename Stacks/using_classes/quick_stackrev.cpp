#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d) : data(d)
    {
        next = NULL;
    }
};
void push(Node **top,int data){
    
    Node *newnode = new Node(data);
    newnode->next = *top;
    *top = newnode;
}
void pop(Node **top){
    if(top == nullptr || *top == nullptr){
        cout << "stack is empty\n";
        return;
    }
    else{
        Node *t = *top;
        *top = (*top)->next;
        cout << "Deleted " << t->data << endl;
        delete t;
    }
}
void display(Node **n){
    if(*n == nullptr){
        return;
    }
    Node *t = *n;
    cout << "Data printing from top\n";
    while (t!= NULL)
    {
        cout << t->data << "->";
        t = t->next;
    }
}
int main()
{
    Node *top = NULL;
    push(&top, 30);
    push(&top, 20);
    push(&top, 40);
    push(&top, 60);
    push(&top, 90);
    pop(&top);
    display(&top);
}