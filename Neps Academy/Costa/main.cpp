#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> vt(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vt[i][j];
        }
    }

    long long cont = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vt[i][j] == '#') {

                if (i == 0) cont++;
                else if (i == n - 1) cont++;
                else if (j == 0) cont++;
                else if (j == m - 1) cont++;

                else if (vt[i-1][j] == '.') cont++;
                else if (vt[i+1][j] == '.') cont++;
                else if (vt[i][j-1] == '.') cont++;
                else if (vt[i][j+1] == '.') cont++;
            }
        }
    }

    cout << cont << endl;
    return 0;
}
