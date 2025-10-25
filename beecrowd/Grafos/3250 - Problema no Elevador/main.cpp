#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 1e6;
bool visited[MAX + 1];
int dist[MAX + 1];

void bfs(int f, int s, int g, int u, int d){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while(!q.empty()){
        int a = q.front();
        q.pop();
        vector<int> vizinhos;
        if(a + u <= f)vizinhos.push_back(a+ u);
        if(a - d >=1)vizinhos.push_back(a - d);

        for(int &v : vizinhos){
            if(!visited[v]&&v<=f&&v>0){
                visited[v] = true;
                dist[v] = dist[a] + 1;
                q.push(v);
            }
        }
    }
}
int main(){
    int f, s, g, u, d;
    cin>>f>>s>>g>>u>>d;
    bfs(f, s, g, u, d);
    if(visited[g]){
        cout<<dist[g]<<endl;
    }else{
        cout<<"use the stairs"<<endl;
    }
    return 0;
}