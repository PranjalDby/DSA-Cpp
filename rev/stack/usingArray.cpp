#include<iostream>

using namespace std;

int *stacks;
int top = -1;
int intial = 0;
#define SIZE 5

void push(int data){
    if (top >= SIZE)
    {
        printf("Stack Overflow\n current size = %d\n", intial);
        return;
    }
    if(top < SIZE-1){
        top++;
        stacks[top] = data;
        intial++;
        return;
    }
}
int pop(){
    if(top == -1){
        printf("Underflow\n");
        return -1;
    }
    int d = stacks[top];
    stacks[top] = -1;
    top--;
    return d;
}
int peek(){
    if(top < SIZE && top != -1){
        return stacks[top];
    }
    return -1;
}
int main()
{
    stacks = new int[SIZE];
    push(30);
    push(40);
    push(87);
    push(34);
    push(32);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    // push(2);
    // push(2);
    printf("top = %d\n", top);
    printf("top element = %d\n", peek());
}