/**************************************************/
//         1245 - Botas Perdidas
//https://judge.beecrowd.com/pt/problems/view/1245*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    int n;
    while (cin >> n)
    {
        map<pair<int, char>, int> mp;
        int pares_formados = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            char s;
            cin >> x >> s;

            char oposto = (s == 'D') ? 'E' : 'D';

            if (mp[{x, oposto}] > 0)
            {
                mp[{x, oposto}]--;
                pares_formados++;
            }
            else
            {
                mp[{x, s}]++;
            }
        }
        cout << pares_formados << endl;
    }
}