#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 1e5;

vector<int> grafo[MAX + 1];
bool visitados[MAX + 1];
int dist[MAX+1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, e, l, p;
    int teste = 1;

    while (cin >> c >> e >> l >> p) {
        if (!c && !e && !l && !p) break;

        
        for (int i = 1; i <= c; i++) {
            grafo[i].clear();
            visitados[i] = false;
            dist[i] = -1;
        }

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        vector<int> adj;

        auto bfs = [&](int inicio) {
            queue<int> fila;
            fila.push(inicio);
            visitados[inicio] = true;
            dist[inicio] = 0;
            while (!fila.empty()) {
                int u = fila.front();
                fila.pop();

                for (int v : grafo[u]) {
                    if (!visitados[v]) {
                        visitados[v] = true;
                        fila.push(v);
                        dist[v] = dist[u] + 1;
                    }
                }
            }
        };

        bfs(l);
        for(int i = 1; i <= c; i++) {
            if (dist[i] > 0 && dist[i] <= p) {
                adj.push_back(i);
            }
        }
        sort(adj.begin(), adj.end());

        cout << "Teste " << teste++ << endl;
        for (int i = 0; i < adj.size(); i++) {
            cout << adj[i] << ' ';
        }
        cout << endl<<endl;
    }
}
