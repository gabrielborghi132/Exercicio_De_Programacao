#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;
bool visited[MAX + 1];
int dist[MAX + 1];
unordered_set<int> proibido;
void bfs(int inicio,int alvo){
    queue<int>q;
    q.push(inicio);
    visited[inicio] = true;
    dist[inicio] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == alvo)return;
        vector<int> vizinhos;
        if (u - 1 > 0) vizinhos.push_back(u - 1);
        if (u + 1 <= MAX) vizinhos.push_back(u + 1);
        if (u % 2 == 0 && u / 2 > 0) vizinhos.push_back(u / 2);
        if (u * 2 <= MAX) vizinhos.push_back(u * 2);
        if (u * 3 <= MAX) vizinhos.push_back(u * 3);


        for(int &v: vizinhos){
            if(!visited[v]&&v<=MAX&& v>0&&proibido.find(v)==proibido.end()){
                visited[v] = true;
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int inicio, alvo, qtdeProibido;;
    while(cin>> inicio>>alvo>>qtdeProibido && (inicio||alvo||qtdeProibido)){
        proibido.clear();
        memset(visited, false, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        for(int i = 0;i<qtdeProibido;i++){
            int x;
            cin>>x;
            proibido.insert(x);
        }
        bfs(inicio, alvo);
        if(visited[alvo]){
            cout<<dist[alvo]<<endl;
        }else{
            cout<<-1<<endl;
        }
    }

    return 0;
}