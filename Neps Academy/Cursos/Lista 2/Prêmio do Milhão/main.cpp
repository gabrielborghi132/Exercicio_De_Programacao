#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    ll soma = 0;
    ll target = -1;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        soma += x;
        if (soma >= 1000000 && target == -1)
        {
            target = i;
        }
    }
    cout << target << endl;
    return 0;
}