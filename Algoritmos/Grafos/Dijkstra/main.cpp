#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e5 + 5;

int n, m, s, f; // n = nós, m = arestas, s = origem, f = destino
vector<pair<int,int>> g[MAXN]; // grafo (v, peso)
vector<int> dist; // vetor de distâncias

// algoritmo de dijkstra
void dijkstra(int s) {
    dist.assign(n + 1, INF); // o vetor de distâncias ser externo é situacional
    priority_queue<pair<int,int>> pq; // (distância negativa, nó)

    dist[s] = 0; // lembrar de colocar a distância inicial como 0
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (-d > dist[u]) continue; // ignora se já há caminho melhor

        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v}); // negativo pra simular min-heap
            }
        }
    }
}