/**************************************************/
//         2414 - Desafio do Maior Número
// https://judge.beecrowd.com/pt/problems/view/2414
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int maior = INT_MIN;
    int x;
    while (cin >> x, x)
    {
        if (x > maior)
        {
            maior = x;
        }
    }
    cout << maior << endl;
}