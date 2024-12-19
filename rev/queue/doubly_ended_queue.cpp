#include<iostream>
#include<queue>
using namespace std;

class DoublyQu{
    public:
    int *dq;
    int maxsize;
    int front, rear;
    DoublyQu(int n){
        maxsize = n;
        dq = new int[n];
        front = rear = -1;
    }
    bool isfull(){
        if((front == 0 && rear == maxsize - 1) || (rear == (front - 1) % (maxsize - 1))){
            return true;
        }
        return false;
    }
    bool isempty(){
        if(front == -1){
            return true;
        }
        return false;
    }
    bool push_front(int d)
    {
        if(isfull()){
            cout << "full\n";
            return false;
        }
        else if(front == -1){
            //initial element
            front = rear = 0;
        }
        else if(front == 0 && rear != maxsize - 1){
            // rear in somewhere middle;
            front = maxsize - 1;
        }
        else{
            front--;
        }
        dq[front] = d;
        return true;
    }
    bool push_rear(int d)
    {
        if(isfull()){
            cout << "full\n";
            return false;
        }
        else if(front == -1){
            //initial element
            front = rear = 0;
        }
        else if(rear == maxsize-1 && front != 0){
            //cyclic nature
            rear = 0;
        }
        else{
            rear++;
        }
        dq[rear] = d;
        return true;
    }
    int pop_rear()
    {
        if(isempty()){
            return -1;
        }
        int d = dq[rear];
        if (rear == 0)
        {
            //rear reaches to the front
            rear = maxsize - 1;
        }
        else if(front == rear){
            //single element
            rear = front = -1;
        }
        else{
            rear--;
        }
        return d;
    }
    int pop_front()
    {
        if(isempty()){
            return -1;
        }
        int d = dq[front];
        if (front == rear)
        {
            //single element
            rear = front = -1;
        }
        else if(front == maxsize-1){
            front = 0;
        }
        else{
            front++;
        }
        return d;
    }
};

int main()
{

    //using stl
    // deque<int> dqu;
    // dqu.push_front(30);
    // dqu.push_back(45);
    // cout << dqu.front() << endl;
    // cout << dqu.back() << endl;
    DoublyQu qu(5);
    qu.push_front(45);
    qu.push_rear(12);
    cout << qu.front << " :: " << qu.rear << endl;
    qu.push_front(125);
    qu.push_rear(34);
    qu.push_rear(44);
    // qu.push_rear(64);
    cout << qu.front << " :: " << qu.rear << endl;
    qu.pop_rear();
    qu.pop_front();
    qu.pop_front();
    cout << qu.front << " :: " << qu.rear << endl;
}