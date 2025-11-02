#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 100; // Número máximo de vértices (ajuste conforme o problema)

// Estruturas de dados principais
int grafo[MAX][MAX]; // Matriz de adjacência - grafo[u][v] = 1 se existe aresta entre u e v
bool vis[MAX];       // Marca os vértices já visitados durante a BFS
int dist[MAX];       // Armazena a menor distância de cada vértice até a origem

// Função de Busca em Largura (BFS) usando matriz de adjacência
// start: vértice inicial da busca
// n: número total de vértices no grafo
void bfs(int start, int n) {
    queue<int> q;       // Fila para processar vértices na ordem de distância
    q.push(start);      // Adiciona o vértice inicial na fila
    vis[start] = true;  // Marca o vértice inicial como visitado
    dist[start] = 0;    // A distância da origem para ela mesma é 0

    // Processa todos os vértices alcançáveis a partir da origem
    while (!q.empty()) {
        int u = q.front(); // Pega o primeiro vértice da fila
        q.pop();           // Remove da fila

        // Verifica todos os possíveis vizinhos (de 0 até n-1)
        for (int v = 0; v < n; v++) {
            // Se existe aresta de u para v E v ainda não foi visitado
            if (grafo[u][v] && !vis[v]) {
                vis[v] = true;          // Marca v como visitado
                dist[v] = dist[u] + 1;  // Calcula a distância: distância do pai + 1
                q.push(v);              // Adiciona v na fila para processar seus vizinhos
            }
        }
    }
}

int main() {
    // Otimização de I/O para entrada/saída mais rápida
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n = número de vértices, m = número de arestas
    cin >> n >> m;

    // Inicializa as estruturas de dados
    memset(grafo, 0, sizeof(grafo));      // Inicializa matriz com 0 (sem arestas)
    memset(vis, false, sizeof(vis));      // Marca todos como não visitados
    fill(dist, dist + n, -1);             // Inicializa distâncias com -1 (inalcançável)

    // Lê as arestas e constrói a matriz de adjacência
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a][b] = 1; // Marca que existe aresta de a para b
        grafo[b][a] = 1; // Marca que existe aresta de b para a (grafo não-direcionado)
                         // Remova esta linha se for grafo direcionado
    }

    int origem; // Vértice de origem para a BFS
    cin >> origem;

    // Executa a BFS a partir da origem
    bfs(origem, n);

    // Imprime as distâncias de todos os vértices até a origem
    cout << "Distâncias a partir de " << origem << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] != -1)
            cout << "Vértice " << i << ": " << dist[i] << endl; // Vértice alcançável
        else
            cout << "Vértice " << i << ": INF" << endl;         // Vértice inalcançável
    }

    return 0;
}
