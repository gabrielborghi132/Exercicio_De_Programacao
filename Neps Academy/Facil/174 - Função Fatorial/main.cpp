#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
ll fatorial(ll n)
{
    if (n <= 1)
        return 1;
    return n * fatorial(n - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << fatorial(n) << endl;
    return 0;
}