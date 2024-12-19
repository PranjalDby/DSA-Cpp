#include <iostream>
using namespace std;


struct node{
    int data;
    node *next;
};
node *front = NULL;
node *rear = NULL;
void enqueu(int data){
    if(front == NULL && rear == NULL){
        node *newnode = new node();
        newnode->data = data;
        rear = newnode;
        front = newnode;
    }
    else{
        node *newnode = new node();
        newnode->data = data;
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeu(){
    if(front == rear || front == NULL){
        cout << "Already empty\n";
        rear = NULL;
        front = NULL;
        return;
    }
    else{
        node *p = front;
        if(front != NULL){
            front = front->next;
        }
        delete p;
    }
}
int main()
{
    enqueu(32);
    enqueu(52);
    enqueu(62);
    enqueu(92);
    dequeu();
    enqueu(100);
    dequeu();
    dequeu();
    dequeu();
    dequeu();
    enqueu(20);
    enqueu(40);
    if (front != NULL)
    {
        cout << "front data = " << front->data << endl;
        cout << "rear data = " << rear->data << endl;
    }
    return 0;
}