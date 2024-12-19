#include <iostream>
using namespace std;


class CircularQueue{
    public:
        int front, rear;
        int *arr;
        int n = 1000;
        CircularQueue(int s){
            n = s;
            front = rear = -1;
            arr = new int[n];
        }
        bool enqueue(int value){
            if((front == 0 && rear == n-1) || (rear == (front-1) % (n-1))){
                return false;
            }
            else if(front == -1){
                front = 0;
                rear = 0;
            }
            else if(rear == n-1 && front != 0){
                //rear reach to end and front is in b/w the array
                rear = 0;
            }
            else{
                rear++;
            }
            arr[rear] = value;
            return true;
        }
        int dequeue(){
            if (front == -1)
            {
                return -1;
            }
            int ans = arr[front];
            arr[front] = -1;
            if(front == rear){
                front = -1;
                rear = -1;
            }
            else if(front == n-1){
                front = 0;
            }
            else{
                front++;
            }
            return ans;
        }
};
int main()
{

    return 0;
}