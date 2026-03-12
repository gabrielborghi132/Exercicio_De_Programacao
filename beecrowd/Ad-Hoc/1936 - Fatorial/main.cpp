#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define endl '\n'
ll const MAX = 1e6;
vector<ll> memo(MAX, -1);
ll fat(ll num)
{
    if (memo[num] != -1)
        return memo[num];
    memo[num] = fat(num - 1) * num;
    return memo[num];
}
int main()
{

    ll n;
    cin >> n;
    memo[0] = 1;
    memo[1] = 1;
    ll sum = 0;
    ll i = 20;
    ll res = 0;
    fat(20);
    while (res != n)
    {
        if (res + memo[i] <= n)
        {
            sum++;
            res += fat(i);
        }
        else
        {
            i--;
        }
    }
    cout << sum << endl;
    return 0;
}