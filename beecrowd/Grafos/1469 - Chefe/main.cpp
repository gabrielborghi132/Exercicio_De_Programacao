#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 1e5 + 5;

vector<int> grafo[MAX];
int ki[MAX];
bool vis[MAX];
int minIdade;

void dfs(int u) {
    vis[u] = true;
    for (auto v : grafo[u]) {
        minIdade = min(minIdade, ki[v]);
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, l;
    while (cin >> n >> m >> l) {
        for(int i = 1; i <= n; i++) {
            grafo[i].clear();
        }
        
        for(int i = 1; i <= n; i++) {
            cin >> ki[i];
        }
        
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            grafo[b].push_back(a);
        }
        
        for(int i = 0; i < l; i++) {
            char tipo;
            cin >> tipo;
            
            if(tipo == 'T') {
                int u, v;
                cin >> u >> v;
                
                swap(grafo[u], grafo[v]);
                
                for(int j = 1; j <= n; j++){
                    for(int& g : grafo[j]){
                        if(g == u) g = v;
                        else if(g == v) g = u;
                    }
                }
                
            } else if(tipo == 'P') {
                int u;
                cin >> u;
                minIdade = MAX;
                memset(vis, false, sizeof(vis));
                dfs(u);
                
                if(minIdade == MAX) {
                    cout << "*" << endl;
                } else {
                    cout << minIdade << endl;
                }
            }
        }
    }
    
    return 0;
}