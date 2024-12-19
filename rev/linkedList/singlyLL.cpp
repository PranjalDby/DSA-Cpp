#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int d) : data(d) {
        next = NULL;
    };
};
Node *addNode(Node *head,int d){
    if(head == NULL){
        Node *newnode = new Node(d);
        head = newnode;
        return head;
    }
    else{
        Node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        Node *newnode = new Node(d);
        ptr->next = newnode;
        ptr = newnode;
    }
    return head;
}
Node * deleteHead(Node *head){
    if(head == nullptr){
        cout << "No head\n";
        return NULL;
    }
    Node *ptr = head->next;
    head->next = NULL;
    delete head;
    head = ptr;
    return head;
}
Node * deleteLast(Node *head){
    if(head == nullptr){
        cout << "No head\n";
        return NULL;
    }
    Node *ptr = head;
    Node *prev = ptr;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    delete ptr;
    return head;
}
Node *deleteAtinde(Node *head,int indx){
    if(head == NULL){
        return head;
    }
    Node *ptr = head;
    Node *prev = NULL;
    int i = 0;
    while(i<indx && ptr->next != NULL){
        prev = ptr;
        ptr = ptr->next;
        i++;
    }
    if(prev == NULL){
        printf("deleting head Node\n");
        prev = ptr->next;
        delete ptr;
        return prev;
    }
    if(ptr->next != NULL){
        prev->next = ptr->next->next;
    }
    else{
        prev->next = ptr->next;
    }
    delete ptr;
    return head;
}

Node* deleteAllprimes(Node *head){
    if(head == NULL){
        return head;
    }
    Node *ptr = head;
    Node *prev = NULL;
    while (ptr != NULL)
    {
        bool isprime = true;
        if (ptr->data <= 1) {
            isprime = false;
        } else {
            for (int k = 2; k< ptr->data; k++)
            {
                if(ptr->data % k == 0){
                    isprime = false;
                    break;
                }
            }
        }
        if(isprime){
            if (prev == NULL) {
                head = ptr->next;
                delete ptr;
                ptr = head;
            } else {
                prev->next = ptr->next;
                delete ptr;
                ptr = prev->next;
            }
            printf("deletion successful\n");
        } else {
            prev = ptr;
            ptr = ptr->next;
        }
    }
    return head;
}
void display(Node *head){
    if(head == NULL){
        return;
    }
    cout << head->data << " ";
    display(head->next);
}
Node *reverseList(Node *head){
    if(head == NULL){
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *next = head->next;
    while(curr!= NULL){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next != NULL){
        next = next->next;
        }
    }
    head = prev;
    return head;
}
int main()
{
    int arr[8] = {5, 3, 8, 1, 7, 2, 6, 4};
    Node *head = NULL;
    for(int i = 0; i < 8; i++){
        head = addNode(head, arr[i]);
    }
    // head = deleteHead(head);
    // printf("deleted last node\n");
    // head = deleteLast(head);
    printf("deleting all primes\n");
    // head = deleteAtinde(head, 2);
    head = deleteAllprimes(head);
    // display(head);
    head = reverseList(head);
    display(head);
    printf("\n");
    return 0;
}