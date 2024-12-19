#include<iostream>
#include<queue>
using namespace std;

int maxi = 5;
int *qu;
int front = -1,rear = -1;

void enqueue(int d){
    //check if queue is full or not
    if(rear == maxi-1){
        cout << "Queue is currently full\n";
        return;
    }
    else if(front == rear && rear == -1){
        front = 0;
        rear = 0;
        qu[rear] = d;
    }
    else{
        rear++;
        qu[rear] = d;
    }
}
int dequeu(){
    //check queue is empty or not
    if(front == rear && rear == -1){
        cout << "queue is empty\n";
        return -1;
    }
    //only single element is present
    if(front == rear && front != -1){
        int d = qu[front];
        qu[front] = -1;
        front = rear = -1;
        return d;
    }
    int d = qu[front];
    front++;
    return d;
}
int main()
{
    // queue<int> que;
    // que.push(10);
    // que.push(20);
    // que.push(40);
    // que.push(50);
    // que.pop();
    // cout << que.front() << endl;
    qu = new int[maxi];
    int arr[8] = {34, 7, 23, 32, 5, 62, 32, 2};
    for(int i = 0; i < 8; i++) {
        enqueue(arr[i]);
    }
    cout << "previous front element = " << qu[front] << endl;
    cout << "popped element = " << dequeu() << endl;
    cout << "previous front element = " << qu[front] << endl;
    cout << "popped element = " << dequeu() << endl;
    cout << "previous front element = " << qu[front] << endl;
    cout << "popped element = " << dequeu() << endl;
    cout << "previous front element = " << qu[front] << endl;
    // cout << "last element = " << qu[rear] << endl;
    cout << "updated front element = " << qu[front] << endl;
    cout << endl;
}