#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
struct fenwick
{
    ll n;
    vector<ll> tree;

    fenwick(ll n)
    {
        this->n = n;
        tree.assign(n + 2, 0);
    }
    void build(vector<ll> v)
    {
        for (ll i = 1; i <= n; i++)
        {
            tree[i] ^= v[i];
            ll j = i + (i & -i);
            if (j <= n)
            {
                tree[j] ^= tree[i];
            }
        }
    }
    void update(ll k, ll v)
    {
        while (k <= n)
        {
            tree[k] ^= v;
            k += k & -k;
        }
    }
    ll sum(ll k)
    {
        ll soma = 0;
        while (k >= 1)
        {
            soma ^= tree[k];
            k -= k & -k;
        }
        return soma;
    }

    ll query(ll a, ll b)
    {
        if (a > b)
            return 0;
        return sum(b) ^ sum(a - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    vector<ll> v(n + 1);
    fenwick tree(n);
    vector<ll> diff(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        diff[i] = v[i] ^ v[i-1];
    }
    tree.build(diff);
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int a, b, d;
            cin >> a >> b >> d;
            tree.update(a, d);
            tree.update(b + 1, d);
        }
        else
        {
            int a;
            cin >> a;
            cout << tree.sum(a) << endl;
        }
    }
}