#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int grafo[MAX + 1][MAX + 1];
bool visitado[MAX + 1];
int v, e;

void dfs(int u, int nivel, bool &temAresta) {
    visitado[u] = true;
    for (int j = 0; j < v; ++j) {
        if (grafo[u][j]) {
            temAresta = true;
            for (int i = 0; i < nivel * 2; ++i)
                cout << " ";
            cout << u << "-" << j;
            if (!visitado[j]) {
                cout << " pathR(G," << j << ")\n";
                dfs(j, nivel + 1, temAresta);
            } else {
                cout << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int caso = 1; caso <= n; ++caso) {
        memset(grafo, 0, sizeof(grafo));
        memset(visitado, false, sizeof(visitado));

        cin >> v >> e;
        for (int i = 0; i < e; ++i) {
            int a, b;
            cin >> a >> b;
            grafo[a][b] = 1;
        }

        cout << "Caso " << caso << ":\n";

        for (int i = 0; i < v; ++i) {
            if (!visitado[i]) {
                bool temAresta = false;
                dfs(i, 1, temAresta);
                if (temAresta)
                    cout << "\n";
            }
        }

    }
    return 0;
}