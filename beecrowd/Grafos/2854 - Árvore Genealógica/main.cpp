#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int MAX = 1e5;
vector<int> grafo[MAX];
bool visited[MAX];
unordered_map<string,int> id;

void dfs(int inicio){
    visited[inicio] = true;
    for(int &v:grafo[inicio]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,a;
    cin>>m>>a;
    int id_num = 0;
    for(int i = 0;i<a;++i){
        string a,b,c;
        cin>>a>>b>>c;

        if(!id.count(a))id[a] = id_num++;
        if(!id.count(c))id[c] = id_num++;

        int u = id[a];
        int v = id[c];

        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    int componentes = 0;

    for (int i = 0; i < m; ++i) {
        if (!visited[i]) {
            componentes++;
            dfs(i);
        }
    }

    cout<<componentes<<endl;
}