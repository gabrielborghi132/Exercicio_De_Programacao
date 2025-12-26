#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 1010;
int m[MAX][MAX];
int l[MAX], c[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int maxi = -1010;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
            l[i] += m[i][j];
            c[j] += m[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maxi = max(maxi, l[i] + c[j] - 2 * m[i][j]);
        }
    }
    cout << maxi << endl;
}