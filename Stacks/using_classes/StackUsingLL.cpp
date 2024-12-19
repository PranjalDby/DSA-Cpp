#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node *top = NULL;

void push(int data)
{
    if (top == NULL)
    {
        Node *newnode = new Node(data);
        newnode->next = top;
        top = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        newnode->next = top;
        top = newnode;
    }
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    Node *t = top;
    top = top->next;
    t->next = NULL;
    delete (t);
}
void display()
{
    if (top == NULL)
    {
        cout << "Empty Stack." << endl;
    }
    else
    {
        Node *p = top;
        while (p != NULL)
        {
            cout << p->data << endl;
            p = p->next;
        }
    }
}
int main()
{
    push(30);
    push(20);
    push(50);
    push(90);
    pop();
    pop();
    pop();
    pop();
    display();
    return 0;
}