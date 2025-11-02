#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 100; // Número máximo de vértices (ajuste conforme o problema)

// Estruturas de dados principais
int grafo[MAX][MAX]; // Matriz de adjacência - grafo[u][v] = 1 se existe aresta entre u e v
bool vis[MAX];       // Marca os vértices já visitados durante a DFS

// Função de Busca em Profundidade (DFS) recursiva usando matriz de adjacência
// u: vértice atual sendo visitado
// n: número total de vértices no grafo
void dfs_iterativo(int start, int n) {
    stack<int> st;
    st.push(start);
    vis[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";

        for (int v = n - 1; v >= 0; v--) { // ordem reversa para manter consistência
            if (grafo[u][v] && !vis[v]) {
                vis[v] = true;
                st.push(v);
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
    memset(grafo, 0, sizeof(grafo));   // Inicializa matriz com 0 (sem arestas)
    memset(vis, false, sizeof(vis));   // Marca todos os vértices como não visitados

    // Lê as arestas e constrói a matriz de adjacência
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        grafo[a][b] = 1; // Marca que existe aresta de a para b
        grafo[b][a] = 1; // Marca que existe aresta de b para a (grafo não-direcionado)
                         // Remova esta linha se o grafo for direcionado
    }

    int origem; // Vértice de origem para iniciar a DFS
    cin >> origem;

    // Executa a DFS a partir da origem e imprime os vértices visitados
    cout << "DFS a partir de " << origem << ": ";
    dfs_iterativo(origem, n);
    cout << endl;


    return 0;
}
