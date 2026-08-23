#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
ll somaDigitos(ll x)
{
    ll soma = 0;
    while (x > 0)
    {
        soma += x % 10;
        x /= 10;
    }
    return soma;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll conta = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll s = somaDigitos(i);
        if ((i % 2) == (s % 2))
            conta++;
    }
    cout << conta << endl;
    return 0;
}