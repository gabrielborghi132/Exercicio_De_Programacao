#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll l, n;
    cin >> l >> n;
    ll ult_zero = -1;
    ll ult_zero2 = -3;
    ll conta = 0;

    for (ll i = 0; i < l; i++)
    {
        bool passou = false;
        ll conta2 = 0;
        for (ll j = 0; j < n; j++)
        {
            ll x;
            cin >> x;
            if (x == 0)
                conta2++;
            if (x != 0 && !passou)
            {
                ult_zero = j;
                passou = true;
            }
        }
        conta = max(conta, conta2);
        if (passou && ult_zero <= ult_zero2 || ((conta == n && conta2 < n)))
        {
            ult_zero2 = n;
            cout << "N" << endl;
            return 0;
        }
        ult_zero2 = max(ult_zero, ult_zero2);
    }
    cout << "S" << endl;
}