#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 1e5 + 5; // limite máximo de vértices

vector<int> grafo[MAX]; // lista de adjacência
bool vis[MAX];          // vértices visitados

void dfs(int u) {
    vis[u] = true;
    cout << u << " "; // ação ao visitar o nó

    for (int v : grafo[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n = vértices, m = arestas
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a); // remova se for direcionado
    }

    int origem;
    cin >> origem;

    cout << "DFS a partir de " << origem << ": ";
    dfs(origem);
    cout << endl;

    return 0;
}
