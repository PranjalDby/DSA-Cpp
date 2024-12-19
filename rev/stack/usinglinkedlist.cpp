#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
Node *top = NULL;
void push(int d){
    if(top == NULL){
        Node *newnode = new Node(d);
        top = newnode;
        return;
    }
    Node *newnode = new Node(d);
    newnode->next = top;
    top = newnode;
}
int pop(){
    if(top == NULL){
        printf("Failed\n! Empty.");
        return -1;
    }
    Node *ptr = top;
    top = top->next;
    ptr->next = NULL;
    int d = ptr->data;
    delete ptr;
    return d;
}
void display(){
    if(top == NULL){
        printf("empty\n");
        return;
    }
    Node *ptr = top;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    int arr[8] = {5, 3, 8, 1, 2, 7, 6, 4};
    for(int i = 0; i < 8; i++) {
        push(arr[i]);
    }
    // cout << top->next->data << endl;
    cout << "Popped element = " << pop() << endl;
    cout << "Popped element = " << pop() << endl;
    cout << "Popped element = " << pop() << endl;
    display();
}