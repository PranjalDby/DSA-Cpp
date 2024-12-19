#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

#define V 5
void addedge(int adj[][V],int src,int des,int d){
    adj[src][des] = 1;
    if(d == 1){
        adj[des][src] = 1;
        return;
    }
}

void BFS(int adj[][V],int src){
    bool visited[V] = {false};
    queue<int> q;
    //put the item into the queue and marked as visited
    q.push(src);
    visited[src] = true;
    //traverse the entire queue
    while(!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        for (int i = 1; i < V; i++)
        {
            // pushing all the neighbours of node curr;
            if (adj[curr][i] != -1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
}
int visited[V] = {false};
queue<int> q;
void DFS(int adj[][V], int src)
{
    if(visited[src]){
        return;
    }
    //marking the node as visited
    visited[src] = true;
    cout << src << " ";
    // traverse all it neighbours;
    for (int i = 1; i < V;i++){
        if(adj[src][i] != -1 && !visited[i]){
            //recursive call
            DFS(adj, i);
        }
    }
}
int main(){
    int adj[V][V];
    for (int i = 0; i < V;i++){
        for (int j = 0; j < V;j++){
            adj[i][j] = -1;
        }
    }
    addedge(adj, 0, 2, 1);
    addedge(adj, 2, 1, 1);
    addedge(adj, 2, 4, 1);
    addedge(adj, 1, 3, 1);
    addedge(adj, 3, 4, 1);
    for (int i = 0; i < V; i++)
    {
        cout << endl;
        for (int j = 0; j < V; j++)
        {
            cout <<setw(2)<< adj[i][j] << " ";
        }
    }
    printf("\n");
    BFS(adj, 0);
    printf("\n");
    printf("DFS\n");
    DFS(adj, 0);
}