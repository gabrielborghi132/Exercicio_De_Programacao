#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 1e5 + 5;

// Estruturas de dados principais
vector<int> grafo[MAX]; // Lista de adjacência - grafo[u] contém todos os vizinhos de u
int dist[MAX];          // Armazena a distância de cada vértice até a origem
bool vis[MAX];          // Marca os vértices já visitados

// Função de Busca em Largura (BFS) - encontra a menor distância da origem até todos os vértices
void bfs(int start) {
    queue<int> q;       // Fila para processar os vértices na ordem correta
    q.push(start);      // Adiciona o vértice inicial na fila
    vis[start] = true;  // Marca o vértice inicial como visitado
    dist[start] = 0;    // A distância da origem para ela mesma é 0

    // Processa todos os vértices alcançáveis
    while (!q.empty()) {
        int u = q.front(); // Pega o primeiro vértice da fila
        q.pop();           // Remove da fila

        // Percorre todos os vizinhos do vértice atual
        for (int v : grafo[u]) {
            if (!vis[v]) {              // Se o vizinho ainda não foi visitado
                vis[v] = true;          // Marca como visitado
                dist[v] = dist[u] + 1;  // A distância é a distância do pai + 1
                q.push(v);              // Adiciona na fila para processar seus vizinhos
            }
        }
    }
}

int main() {
    // Otimização de I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n = número de vértices, m = número de arestas
    cin >> n >> m;

    // Lê as arestas e constrói o grafo não-direcionado
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a].push_back(b); // Adiciona aresta de a para b
        grafo[b].push_back(a); // Adiciona aresta de b para a (grafo não-direcionado)
    }

    int origem; // Vértice de origem para a BFS
    cin >> origem;

    // Executa a BFS a partir da origem
    bfs(origem);

    // Imprime as distâncias de todos os vértices até a origem
    for (int i = 1; i <= n; i++) {
        if (vis[i]) cout << "Dist[" << i << "] = " << dist[i] << endl; // Vértice alcançável
        else cout << "Dist[" << i << "] = INF" << endl;                // Vértice inalcançável
    }

    return 0;
}
