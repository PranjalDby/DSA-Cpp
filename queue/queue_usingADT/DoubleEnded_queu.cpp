#include <iostream>
using namespace std;

class Dq{
    public:
        int front, rear;
        int *arr;
        int n;
        Dq(int s):n(s){
            front = rear = -1;
            arr = new int[n];
        }
        bool isFull(){
            if((rear == n-1 && front == 0)||(front != 0 && (rear == (front-1) % (n-1)))){
                return true;
            }
            return false;
        }
        bool isEmpty(){
            if(front == -1){
                return true;
            }
            return false;
        }
        void push_back(int data){
            if(isFull()){
                cout << "Full already\n";
                return;
            }
            if(front == -1){
                front = rear = 0;
            }
            else if(rear == n-1 && front != 0){
                rear = 0;
            }
            else{
                rear++;
            }
            arr[rear] = data;
        }
        void push_front(int data){
            if(isFull()){
                cout << "Full already\n";
                return;
            }
            if(front == -1){
                front = rear = 0;
            }
            else if(front == 0 && rear != n-1){
                front = n-1;
            }
            else{
                front--;
            }
            arr[front] = data;
        }
        int pop_front(){
            if(isEmpty()){
                cout << "Empty already\n";
                return -1;
            }
            int ans = arr[front];
            arr[front] = -1;
            if (front == n - 1)
            {
                front = 0;
            }
            else if(front == rear){
                front = rear =  - 1;
            }
            else{
                front++;
            }
            return ans;
        }
        int pop_back(){
            if(isEmpty()){
                cout << "Empty already\n";
                return -1;
            }
            int ans = arr[rear];
            arr[rear] = -1;
            if (rear == 0)
            {
                rear = n - 1;
            }
            else if(front == rear){
                front = rear = -1;
            }
            else{
                rear--;
            }
            return ans;
        }
};
int main()
{
    Dq d(5);
    d.push_back(40);
    d.push_front(60);
    d.push_front(50);
    d.push_front(80);
    d.push_front(90);
    d.pop_back();
    d.pop_back();
    int s = d.pop_front();
    cout << "First pop = " << s << endl;
    s = d.pop_front();
    cout << "Second pop = " << s << endl;
    d.push_back(89);
    cout << "Back = " << d.arr[d.rear] << " " << "Front = " << d.arr[d.front] << endl;
    return 0;
}