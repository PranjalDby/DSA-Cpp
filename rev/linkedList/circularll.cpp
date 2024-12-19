#include<iostream>

using namespace std;

struct Circular{
    int data;
    Circular *next;
    Circular(int d){
        data = d;
        next = nullptr;
    }
};
Circular *last = NULL;
void add(Circular **head, int d)
{
    if(*head == NULL){
        Circular *newnode = new Circular(d);
        *head = newnode;
        last = newnode;
        newnode->next = *head;
        return;
    }
    else{
        Circular *newnode = new Circular(d);
        Circular *ptr = *head;
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        last = newnode;
        newnode->next = *head;
    }
}
void deletefirst(Circular **h){
    if(*h == NULL){
        printf("Maybe last element\n");
        return;
    }
    if(*h == last){
        *h = NULL;
        last = NULL;
        return;
    }
    *h = (*h)->next;
    last->next = *h;
    return;
}
void display(Circular *c){
    if(c == NULL){
        cout << "Empty\n";
        return;
    }
    Circular *ptr = c;
    while(ptr->next != c){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << ptr->data << endl;
    ;
}
int main()
{
    Circular *head = nullptr;
    int arr[8] = {5, 3, 8, 1, 7, 2, 6, 4};
    for(int i = 0; i < 8; i++) {
        add(&head, arr[i]);
    }
    cout << head->data << endl;
    deletefirst(&head);
    deletefirst(&head);
    deletefirst(&head);
    deletefirst(&head);
    deletefirst(&head);
    deletefirst(&head);
    deletefirst(&head);
    deletefirst(&head);
    // cout << head->data << endl;
    display(head);
    return 0;
}