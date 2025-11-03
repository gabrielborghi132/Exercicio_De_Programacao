#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 505;

int n, m; // n = número de nós, m = número de arestas
int dist[MAXN][MAXN]; // matriz de distâncias

// algoritmo de Floyd–Warshall com detecção de ciclos negativos
bool floyd_warshall() {
    // inicializar a matriz de distâncias
    // isso só aé necessário se você não fez antes de rodar o algorítmo
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i == j ? 0 : INF);

    // relaxar todos os caminhos possíveis via cada nó intermediário k
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // detecção de ciclo negativo
    // um ciclo negativo ocorre se tem valor negativo na diagonal principal
    bool tem_ciclo_negativo = false;
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) {
            tem_ciclo_negativo = true;
            break;
        }
    }

    return tem_ciclo_negativo;
}