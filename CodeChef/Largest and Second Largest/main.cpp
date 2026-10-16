#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll n = 0;
        cin >> n;
        ll a = 0;
        ll maior_1 = INT_MIN;
        ll maior_2 = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            cin >> a;
            if (a > maior_1)
            {
                maior_2 = maior_1;
                maior_1 = a;
            }
            else if (a > maior_2 && a != maior_1)
            {
                maior_2 = a;
            }
        }
        cout << (maior_1 + maior_2) << endl;
    }
    return 0;
}