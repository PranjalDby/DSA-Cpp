#include <iostream>
using namespace std;

class Q{
    private:
        string key;
    
    protected:
        pair<int,int> getAll(){
            pair<int, int> p(front,rear);
            return p;
        }
    public:
        int front, rear;
        int n;
        int *arr;
        Q(int s){
            this->key = "Hahaha.....LOL#@24Sch92";
            this->n = s;
            this->front = 0;
            this->rear = 0;
            this->arr = new int[s];
        }
        void enqueue(int data){
            // check if full;
            if(front == 0 && rear == -1){
                cout << "Full\n";
                return;
            }
            if(front == -1){
                front = 0;
            }
            else{
                arr[rear] = data;
                rear = rear + 1;
            }
        }
        friend class Matru;
        int dequeue()
        {
            //check if empty
            int ans = 0;
            if (front == rear)
            {
                return -1;
            }
            else{
                ans = arr[front];
                arr[front] = -1;
                front++;
                //if only last element is present
                if(front == rear){
                    front = rear = 0;
                }
                return ans;
            }
        }
};
class Matru{
    public:
        int data;
        string Name;
        void getPrivatedata(Q &q)
        {
            cout << "Secret Key is = " << q.key << endl;
        }
        void getMemberFunc(Q &q){
            pair<int, int> res = q.getAll();
            cout << "Front = " << res.first << " second = " << res.second << endl;
        }
};
class CircularQueue
{
    public:
        int front, rear;
        int n;
        int *arr;
        CircularQueue(int n){
            this->n = n;
            front = rear = -1;
            arr = new int[n];
        }
        void enqueue(int data){
            // check if full;
            if((front == 0 && rear == n-1) || (rear == (front-1)%(n-1) && front != 0)){
                cout << "Circular queue is full:\n";
                return;
            }
            else if(front != 0 && rear == n-1){
                // to maintain the cyclic nature;
                rear = 0;
            }
            else if(front == -1){
                // set initial element;
                front = 0;
                rear = 0;
            }
            else{
                rear = rear + 1;
            }
            arr[rear] = data;
        }
        int dequeue(){
            int ans;
            if (front == -1)
            {
                cout << "Emott\n";
                return -1;
            }
            ans = arr[front];
            arr[front] = -1;
            //if single element is present
            if(front == rear){
                front = rear = -1;
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

    
    CircularQueue qu(5);
    // Matru matar;
    // matar.getPrivatedata(qu);
    // matar.getMemberFunc(qu);
    while(true){
        cout << "1: for push 2: pop 3:front 4:back:: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Push\n";
            cout << "enter the data: \n";
            int data;
            cin >> data;
            qu.enqueue(data);
            break;
        case 2:
            cout << "Pop\n";
            cout << "Popped data is = " << qu.dequeue() << endl;
            break;
        case 3:
            cout << "Front dat =\n";
            cout << qu.front << endl;
            break;
        case 4:
            cout << "rear data = " << qu.rear << endl;
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}