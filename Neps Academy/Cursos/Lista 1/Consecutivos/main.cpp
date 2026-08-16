#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> vt(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> vt[i];
    }
    ll maior = LLONG_MIN, atual = 1;
    for (ll i = 0; i < n; i++)
    {
        if (i > 0 && vt[i] == vt[i - 1])
            atual++;
        else
            atual = 1;
        maior = max(maior, atual);
    }
    cout << maior << endl;
    return 0;
}