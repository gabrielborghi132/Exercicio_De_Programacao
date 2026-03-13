#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    ll soma = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        soma += x;
    }
    cout << soma << endl;
}