#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e5 + 5;

int n, m, s, f; // n = nós, m = arestas, s = origem, f = destino
vector<tuple<int,int,int>> edges; // arestas (u, v, peso)
vector<int> dist; // vetor de distâncias

// algoritmo de Bellman-Ford com saída antecipada e detecção de ciclo negativo
bool bellman_ford(int s) {
    dist.assign(n + 1, INF);
    dist[s] = 0;

    // relaxa todas as arestas até (n - 1) vezes
    for (int i = 1; i <= n - 1; i++) {
        bool atualizado = false;
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                atualizado = true;
            }
        }
        // se nenhuma atualização ocorreu, pode parar cedo
        if (!atualizado) break;
    }

    // checagem de ciclo negativo
    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[v] > dist[u] + w)
            return true; // ciclo negativo detectado
    }
    return false; // sem ciclo negativo
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c; // número de casos de teste
    cin >> c;
    
    while (c--) {
        cin >> n >> m;
        edges.clear();
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
        }
        
        bool has_negative_cycle = bellman_ford(0);
        
        if (has_negative_cycle) {
            cout << "possible\n";
        } else {
            cout << "not possible\n";
        }
    }
    
    return 0;
}