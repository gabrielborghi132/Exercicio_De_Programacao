#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ll n;
    cin >> n;
    while (n--)
    {
        for (ll i = 0; i < 3; i++)
        {
            int vistos = 0;
            bool interroga = false;
            for (ll j = 0; j < 3; j++)
            {
                char letra;
                cin >> letra;
                if (letra != '?')
                    vistos |= 1 << (letra - 'A');
                else
                    interroga = true;
            }
            if (!interroga)
                continue;
            int faltante = 0b111 ^ vistos;

            for (char c = 'A'; c <= 'C'; c++)
            {
                if (faltante & (1 << (c - 'A')))
                {
                    cout << c << endl;
                }
            }
        }
    }
}