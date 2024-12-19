#include<iostream>

using namespace std;

int *circular;
int front = -1, rear = -1;
int maxsize = 5;
void enque(int d){
    // check if queue is not full;
    if((front == 0 && rear == maxsize-1) || (rear == (front - 1) % (maxsize-1))){
        cout << "queue is full\n";
        return;
    }
    else if(front != 0 && rear == maxsize-1){
        // rear reaches to end;
        rear = 0;
    }
    else if(front == -1){
        front = rear = 0;
    }
    else{
        rear++;
    }
    circular[rear] = d;
}
int dequeu(){
    int d = -1;
    if (front == -1)
    {
        cout << "empty\n";
        return -1;
    }
    else if(front == rear){
        //single element
        d = circular[front];
        front = rear = -1;
        return d;
    }
    else if(front == maxsize-1){
        //front reaches end
        d = circular[front];
        front = 0;
        return d;
    }
    else{
        d = circular[front];
        front++;
    }
    return d;
}
int main()
{
    int arr[8] = {34, 7, 23, 32, 5, 62, 31, 12};
    circular = new int[maxsize];
    enque(arr[0]);
    enque(arr[1]);
    enque(arr[2]);
    enque(arr[3]);
    enque(arr[4]);
    cout << "deleted = " << dequeu() << endl;
    // cout << "deleted = " << dequeu() << endl;
    enque(arr[5]);
    cout << "deleted = " << dequeu() << endl;
    enque(arr[6]);
    enque(arr[7]);
    cout << "front i = " << front << endl;
    cout << "front = " << circular[front] << endl;
    cout << "rear = " << circular[rear] << endl;
}