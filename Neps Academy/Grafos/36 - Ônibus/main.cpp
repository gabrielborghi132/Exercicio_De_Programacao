#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int visitado[MAX+1];
vector<int> grafo[MAX+1];
int dist[MAX+1];
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;
    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    auto bfs = [&](int inicio,int fim){
        queue<int> fila;
        fila.push(inicio);
        visitado[inicio] = true;
        while(!fila.empty()){
            int u = fila.front();
            fila.pop();
            for(int v : grafo[u]){
                if(!visitado[v]){
                    fila.push(v);
                    visitado[v] = true;
                    dist[v] = dist[u] + 1;
                }
            }
        }
    };
    bfs(a,b);
    cout<<dist[b]<<"\n";
    return 0;
}