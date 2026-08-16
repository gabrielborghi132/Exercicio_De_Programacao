#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while (cin >> n, n)
    {
        ll conta = 0;
        ll x = 0;

        while (n >= 2)
        {
            if (n == 2)
                n++;
            x = n / 3;
            conta += x;
            n %= 3;
            n += x;
        }
        cout << conta << endl;
    }
    return 0;
}