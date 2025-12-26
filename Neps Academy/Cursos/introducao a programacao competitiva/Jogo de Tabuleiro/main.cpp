#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int const INF = INT_MAX;
int const MAX = 10;
vector<vector<int>> memo;
int resolve(int n, int x, int y, vector<vector<int>> &vt)
{
    if (memo[x][y] != INF)
    {
        return memo[x][y];
    }
    if ((x == 0 || y == 0) && (x < n || y < n))
    {
        return vt[x][y];
    }
    int valor = resolve(n, x - 1, y, vt) + resolve(n, x, y - 1, vt) + resolve(n, x - 1, y - 1, vt);
    if (valor >= 2)
    {
        memo[x][y] = 0;
    }
    else
    {
        memo[x][y] = 1;
    }
    vt[x][y] = memo[x][y];
    return vt[x][y];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    memo.assign(n, vector<int>(n, INF));
    vector<vector<int>> vt(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vt[i][j];
        }
    }
    cout << resolve(n, n - 1, n - 1, vt) << endl;
}
