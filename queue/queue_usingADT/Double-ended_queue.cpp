#include <iostream>
using namespace std;


//it implementation is same as circular queue
class DoubleEnded{
    public:
        int front, rear;
        int *arr;
        int n;
        DoubleEnded(int s):n(s){
            front = rear = -1;
            arr = new int[s];
        }
        void push_rear(int data)
        {
            if (isFull())
            {
                cout << "Full\n";
                return;
            }
            if (rear == n - 1 && front != 0)
            {
                rear = 0;
            }
            else if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                rear++;
            }
            arr[rear] = data;
        }
        void push_front(int data){
            if(isFull()){
                cout << "Front Full \n";
                return;
            }
            if(front == -1){
                // initial element;
                front = 0;
                rear = 0;
            }
            else if(front == 0 && rear != n-1){
                // more than one element;
                front = n - 1;
            }
            else{
                front--;
            }
            arr[front] = data;
        }
        int pop_rear(){
            if(front == -1){
                return -1;
            }
            int res = arr[rear];
            arr[rear] = -1;
            if (front == rear)
            {
                //if single element
                front = rear = -1;
            }
            else if(rear == 0){
                rear = n - 1;
            }
            else{
                rear--;
            }
            // arr[rear] = -1;
            return res;
        }
        int pop_front(){
            if(front == -1){
                return -1;
            }
            int res = arr[front];
            arr[front] = -1;
            if (front == rear)
            {
                //single-element
                front = rear = -1;
            }
            else if(front == n-1){
                front = 0;
            }
            else{
                front++;
            }
            // arr[front] = -1;
            return res;
        }
        bool isFull(){
            if((front == 0 && rear == n-1)||(front != 0 && (rear == (front-1) %(n-1)))){
                return true;
            }
            else{
                return false;
            }
        }
};

int main()
{
    DoubleEnded dq(6);
    dq.push_rear(20);
    dq.push_front(80);
    dq.push_rear(30);
    dq.push_front(130);
    dq.push_rear(60);
    dq.push_rear(90);
    dq.push_rear(50);
    dq.push_rear(30);
    cout << dq.rear << endl;
    cout << dq.front << endl;
    // dq.pop_front();
    // dq.pop_rear();
    cout << "front = " << dq.arr[dq.front] << endl;
    cout << "back = " << dq.arr[dq.rear] << endl;
    return 0;
}