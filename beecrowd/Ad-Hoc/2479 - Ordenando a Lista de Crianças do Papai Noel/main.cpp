/**************************************************/
//         2479 - Ordenando a Lista de Crianças do Papai Noel
// https://judge.beecrowd.com/pt/problems/view/2479
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    char c;
    int comportaram = 0;
    int Nao_comportaram = 0;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c >> s[i];
        if (c == '+')
        {
            comportaram++;
        }
        else
        {
            Nao_comportaram++;
        }
    }
    stable_sort(s.begin(), s.end());

    for (auto &a : s)
    {
        cout << a << endl;
    }
    cout << "Se comportaram: " << comportaram << " | Nao se comportaram: " << Nao_comportaram << endl;
}