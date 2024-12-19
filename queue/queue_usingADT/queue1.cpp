#include <iostream>
using namespace std;

// impleneting queue using array;
class Queue{
    public:
        int s;
        int front, rear;
        int *arr;
        Queue(int n)
        {
            s = n;
            front = -1;
            rear = -1;
            arr = new int[n];
        }

        int size(){
            if(front == -1 || rear == -1){
                return 0;
            }
            return rear-front + 1;
        }
        bool isfull(){
            if(rear == s){
                return true;
            }
            return false;
        }
        bool empty(){
            if(front == -1 || front == rear){
                return true;
            }
            return false;
        }
        int getfront(){
            if(front == -1 || rear == -1){
                return -1;
            }
            return arr[front];
        }
        int back(){
            if(front == -1 || rear == -1){
                return -1;

            }
            return arr[rear];
        }

        void push(int data){
            if(isfull()){
                cout << "Can't insert data unable to push new element:\n";
                return;
            }
            if(front == -1){
                front = 0;
            }
            rear++;
            arr[rear] = data;
        }
        int pop(){
            int ans;
            if (front == rear)
            {
                //cout << "Can't delete data unable to pop:\n";
                return -1;
            }
            s--;
            ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = rear = 0;
            }
            return ans;
        }
};

int main()
{

    Queue qu(6);
    qu.push(22);
    qu.pop();
    qu.push(55);
    qu.push(65);
    cout << "Befor deletion = " << qu.getfront() << endl;
    qu.pop();
    qu.push(59);
    qu.push(159);
    qu.push(99);
    cout << qu.size() << endl;
    cout << "After deletion = " << endl;
    cout << qu.getfront() << endl;
    cout << "rear element = " << qu.back() << endl;
    return 0;
}