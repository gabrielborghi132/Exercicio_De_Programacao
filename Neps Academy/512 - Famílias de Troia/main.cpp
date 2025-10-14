#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX =1e5;
vector<int> grafo[MAX+1];
bool visitado[MAX+1];
int v,e;
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>v>>e;
    for(int i = 0;i<e;++i){
        int a,b;
        cin>>a>>b;
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
    }
    auto dfs_iterativa = [&](int inicio){
        stack<int> pilha;
        pilha.push(inicio);
        visitado[inicio] = true;
        while(!pilha.empty()){
            int u = pilha.top();
            pilha.pop();
            for(int v:grafo[u]){
                if(!visitado[v]){
                    pilha.push(v);
                    visitado[v] = true;
                }
            }
        }
    };
    int componente = 0;
    for(int i = 0;i<v;++i){
        if(!visitado[i]){
            componente++;
            dfs_iterativa(i);
        }
    }
    cout<<componente<<endl;
}