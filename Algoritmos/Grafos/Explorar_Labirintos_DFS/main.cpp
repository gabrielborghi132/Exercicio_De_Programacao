#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX = 1005; // tamanho máximo da matriz
int n, m;             // dimensões do labirinto
char grid[MAX][MAX];  // matriz do labirinto
bool vis[MAX][MAX];   // marca as posições visitadas

// movimentos: cima, baixo, esquerda, direita
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool dentro(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (dentro(nx, ny) && !vis[nx][ny] && grid[nx][ny] != '#') {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int sx, sy; // ponto inicial
    cin >> sx >> sy;

    dfs(sx, sy);

    cout << "Mapa visitado (V = visitado):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) cout << 'V';
            else cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
