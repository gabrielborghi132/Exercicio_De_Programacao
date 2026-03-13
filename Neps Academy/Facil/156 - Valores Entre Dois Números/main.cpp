#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    for (int i = min(a, b); i < max(a, b); i++)
    {
        cout << i << " ";
    }
    cout << max(a, b) << endl;
}