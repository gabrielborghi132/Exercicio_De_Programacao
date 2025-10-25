#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 26;
bool visitado[MAX + 1];
int grafo[MAX + 1][MAX + 1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int v, e;
        cin >> v >> e;

        int id_num = 0;
        memset(grafo, 0, sizeof(grafo));
        memset(visitado, false, sizeof(visitado));

        //map<char, int> id;
        //map<int, char> inv;
        for (int j = 0; j < e; ++j) {
            char a, b;
            cin >> a >> b;
            int u = a - 'a';
            int g = b - 'a';
            grafo[u][g] = 1;
            grafo[g][u] = 1;
        }

        auto dfs_iterativa = [&](int inicio) {
            stack<int> pilha;
            pilha.push(inicio);
            visitado[inicio] = true;

            vector<char> componente;

            while (!pilha.empty()) {
                int x = pilha.top();
                pilha.pop();
                componente.push_back('a'+x);

                for (int j = 0;j<v;++j) {
                    if (grafo[x][j] && !visitado[j]) {
                        visitado[j] = true;
                        pilha.push(j);
                    }
                }
            }

            sort(componente.begin(), componente.end());
            for (char c : componente) cout << c << ",";
            cout << endl;
        };

        cout << "Case #" << i << ":" << endl;

        int componentes = 0;
        for (int j = 0;j<v;++j) {
            if (!visitado[j]) {
                dfs_iterativa(j);
                componentes++;
            }
        }

        cout << componentes << " connected components\n\n";
    }
}