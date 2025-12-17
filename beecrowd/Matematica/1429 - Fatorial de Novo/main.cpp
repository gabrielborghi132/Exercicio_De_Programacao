/**************************************************/
//        1429 - Fatorial de Novo!
// https://judge.beecrowd.com/pt/problems/view/1429
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 1e4;
vector<int> vt(MAX);
int fatorial(int n)
{
    if(vt[n]!=0)
        return vt[n];
    if (n <= 1)
        return 1;
    vt[n] = n * fatorial(n - 1);
    return vt[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n)
    {
        string s = to_string(n);
        int j = 1;
        int soma = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            soma += (s[i] - '0') * fatorial(j);
            j++;
        }
        cout << soma << endl;
    }
}