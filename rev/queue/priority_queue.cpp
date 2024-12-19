#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    int priority;
    Node(int d,int p){
        data = d;
        next = NULL;
        priority = p;
    }
};

//min heap mode
Node *front = NULL, *rear = NULL;
void push(int d,int p)
{
    if(front == NULL){
        Node *newnode = new Node(d, p);
        front = rear = newnode;
        return;
    }
    else{
        Node *newnode = new Node(d, p);
        if (front->priority > newnode->priority){
            newnode->next = front;
            front = newnode;
            return;
        }
        else{
            Node *ptr = front;
            while(ptr->next != NULL && ptr->priority <= newnode->priority){
                ptr = ptr->next;
            }
            ptr->next = newnode;
            rear = newnode;
        }
    }
}
void display(){
    if(front == NULL){
        return;
    }
    Node *ptr = front;
    while(ptr != NULL){
        cout << ptr->data << ": " << ptr->priority << endl;
        ptr = ptr->next;
    }
}
int main(){
    push(10, 2);
    push(12, 3);
    push(1, 1);
    push(14, 7);
    push(5, 10);
    push(50, 0);
    cout << "rear= " << rear->data << endl;
    display();
}