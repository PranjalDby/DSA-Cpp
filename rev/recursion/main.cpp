#include<iostream>

using namespace std;

void hanoi(char from,char to,char aux,int disks){
    if(disks == 0){
        return;
    }
    hanoi(from,aux,to, disks - 1);
    cout << "shifting disk " << disks << " from " << from << " to " << to  << endl;
    hanoi(aux, to, from,disks - 1);
}
int main(){
    hanoi('a', 'c', 'b', 3);
}