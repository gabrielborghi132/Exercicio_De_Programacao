#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    vector<ll> par;
    vector<ll> impar;

    for (ll i = 0; i < 10; i++)
    {
        ll x;
        cin >> x;
        if (x % 2 == 0)
            par.push_back(x);
        else
            impar.push_back(x);
    }

    for (ll i = 0; i < (int)par.size() - 1; i++)
    {
        cout << par[i] << " ";
    }
    cout << par[par.size() - 1] << endl;

    for (ll i = 0; i < (int)impar.size() - 1; i++)
    {
        cout << impar[i] << " ";
    }
    cout << impar[impar.size() - 1] << endl;
}