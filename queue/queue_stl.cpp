#include <iostream>
#include<queue>
using namespace std;

int main(){

    queue<int> queue;
    //inserting into the queue
    queue.push(10);
    queue.push(14);
    queue.push(20);
    queue.push(35);
    cout << "Total size of queue = " << queue.size();
    if(queue.empty()){
        cout << "not empty:\n";
    }
    else{
        cout << "queue is not empty\n";

        cout << "Front element  = " << queue.back();
    }
    return 0;
}