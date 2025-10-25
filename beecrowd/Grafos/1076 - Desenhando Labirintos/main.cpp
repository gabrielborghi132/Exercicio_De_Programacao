#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, v, a;
        cin >> n >> v >> a;
        
        vector<vector<int>> grid(v, vector<int>(v, 0));
        vector<bool> visitado(v, false);

        for (int i = 0; i < a; ++i) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = 1;
            grid[y][x] = 1;
        }

        int contagem = 0;

        auto dfs_iterativa = [&](int inicio) {
            stack<int> pilha;
            pilha.push(inicio);
            visitado[inicio] = true;
            contagem++;

            while (!pilha.empty()) {
                int x = pilha.top();
                pilha.pop();
                contagem++;
                for (int i = 0; i < v; ++i) {
                    if (grid[x][i] && !visitado[i]) {
                        visitado[i] = true;
                        contagem++;
                        pilha.push(i);
                    }
                }
            }
        };

        dfs_iterativa(n);
        cout << contagem -2 << endl;
    }

    return 0;
}