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
    
    // relaxar todos os caminhos possíveis via cada nó intermediário k
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p;
    cin>>n>>m>>p;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i == j ? 0 : INF);
    // Ler as arestas
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    
    floyd_warshall();
    
    // Processar as consultas
    for(int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        if(dist[a][b] < INF) 
            cout << "Lets que lets\n";
        else 
            cout << "Deu ruim\n";
    }
    
    return 0;
}