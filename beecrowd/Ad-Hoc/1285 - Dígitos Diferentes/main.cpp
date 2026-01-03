/**************************************************/
//         1285 - Dígitos Diferentes
// https://judge.beecrowd.com/pt/problems/view/1285*/
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool repetiu(int num)
{
    vector<bool> vt(5001, false);
    string s = to_string(num);
    for (auto &a : s)
    {
        if (!vt[a - '0'])
            vt[a - '0'] = true;
        else
            return true;
    }
    return false;
}
int resolver(int n, int m)
{
    int contagem = 0;
    for (int i = n; i <= m; i++)
    {
        if (!repetiu(i))
            contagem++;
    }
    return contagem;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m)
    {
        cout << resolver(n, m) << endl;
    }
}