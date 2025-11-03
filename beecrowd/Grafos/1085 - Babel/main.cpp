#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 1e5 + 5;

int n;
unordered_map<string,int> id;
unordered_map<int,string> idReverso;
unordered_map<string,int> idPalavras;
unordered_map<int,string> idPalavrasReverso;

using tiii = tuple<int,int,string>;
vector<tiii> g[MAXN];
vector<int> dist;

void dijkstra(int s) {
    dist.assign(id.size() + 1, INF); // o vetor de distâncias ser externo é situacional
    priority_queue<tuple<int,int,string>> pq; // (distância negativa, nó)

    dist[s] = 0; // lembrar de colocar a distância inicial como 0
    pq.push({0, s, idReverso[s]});
    string letra = idReverso[s];
    while (!pq.empty()) {
        auto [d, u, p] = pq.top(); pq.pop();
        if (-d > dist[u]) continue; // ignora se já há caminho melhor
        
        for (auto [v, w, x] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v, x}); // negativo pra simular min-heap
                letra = p;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n, n) {
        id.clear();

        string inicio, fim;
        cin >> inicio >> fim;
        int counter = 0;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            string s, s2, s3;
            cin >> s >> s2 >> s3;

            if (!id.count(s)) id[s] = idx++;
            if (!id.count(s2)) id[s2] = idx++;
            if (!id.count(s3)) {
                idPalavras[s3] = counter++;
            }
            idReverso[id[s]] = s;
            idReverso[id[s2]] = s2;
            idReverso[idPalavras[s3]] = s3;
            g[id[s]].push_back({id[s2], 1, s3});
            g[id[s2]].push_back({id[s], 1, s3});
        }

        dijkstra(id[inicio]);

        if (!id.count(fim) || dist[id[fim]] == INF)
            cout << "impossivel\n";
        else
            cout << dist[id[fim]] << '\n';

        for (int i = 0; i < idx; i++) g[i].clear();
    }

    return 0;
}