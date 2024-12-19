#include<iostream>

using namespace std;



struct Doubly{
    int data;
    Doubly *prev, *next;
    Doubly(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};
Doubly *last = NULL;
void add(Doubly **head, int data)
{
    if(head == NULL || *head == NULL){
        Doubly *newnode = new Doubly(data);
        *head = newnode;
        last = *head;
        return;
    }
    else{
        Doubly *ptr = *head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        Doubly *newnode = new Doubly(data);
        newnode->prev = ptr;
        ptr->next = newnode;
        ptr = newnode;
        last = ptr;
    }
}
void display(Doubly *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    cout << head->data << " ";
    display(head->next);
}
void displayReverse(Doubly *head) {
    if(head == NULL){
        return;
    }
    cout << head->data << " ";
    displayReverse(head->prev);
}
void deleteHead(Doubly **head){
    if(head == NULL || *head == NULL){
        return;
    }
    Doubly *ptr = *head;
    *head = (*head)->next;
    (*head)->prev = ptr->prev;
    ptr->next = NULL;
    delete ptr;
}
void deleteLast(Doubly **head){
    if(*head == NULL){
        return;
    }
    Doubly *ptr = *head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    last = ptr->prev;
    ptr->prev->next = NULL;
    delete ptr;
}
int main()
{
    int arr[8] = {5, 3, 8, 1, 7, 2, 6, 4};
    Doubly *head = NULL;
    for (int i = 0; i < 8; i++)
    {
        add(&head, arr[i]);
    }
    deleteHead(&head);
    deleteHead(&head);
    deleteLast(&head);
    // cout << head->prev << " ";
    display(head);
    displayReverse(last);
}