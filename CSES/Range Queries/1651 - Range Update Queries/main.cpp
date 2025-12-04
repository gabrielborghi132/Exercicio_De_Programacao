#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define endl '\n'

struct segTree
{
    ll n;
    vector<ll> seg, lazy;

    segTree(ll n)
    {
        this->n = n;
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void build(vector<ll> &a, ll idx, ll l, ll r)
    {
        if (l == r)
        {
            seg[idx] = a[l];
            return;
        }

        ll mid = (l + r) / 2;

        build(a, 2 * idx, l, mid);
        build(a, 2 * idx + 1, mid + 1, r);

        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    void push(ll idx, ll l, ll r)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] += lazy[idx] * (r - l + 1);

            if (l != r)
            {
                lazy[2 * idx] += lazy[idx];
                lazy[2 * idx + 1] += lazy[idx];
            }

            lazy[idx] = 0;
        }
    }

    void update_range(ll idx, ll l, ll r, ll ql, ll qr, ll val)
    {
        push(idx, l, r);
        if (qr < l || ql > r)
            return;
        if (ql <= l && r <= qr)
        {
            lazy[idx] += val;
            push(idx, l, r);
            return;
        }

        ll mid = (l + r) / 2;

        update_range(2 * idx, l, mid, ql, qr, val);
        update_range(2 * idx + 1, mid + 1, r, ql, qr, val);

        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    ll query(ll idx, ll l, ll r, ll ql, ll qr)
    {
        push(idx, l, r);

        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return seg[idx];

        ll mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
    }
    void build(vector<ll> &a) { build(a, 1, 1, n); }
    void update_range(ll l, ll r, ll val) { update_range(1, 1, n, l, r, val); }
    ll query(ll ql, ll qr) { return query(1, 1, n , ql, qr); }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n + 1, 0);
    segTree arvore(n);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    arvore.build(a);
    for (ll i = 0; i < q; i++)
    {
        ll escolha;
        cin >> escolha;
        if (escolha == 1)
        {
            ll l, r, val;
            cin >> l >> r >> val;
            arvore.update_range(l, r, val);
        }
        else
        {
            ll ql;
            cin >> ql;
            cout << arvore.query(ql, ql) << endl;
        }
    }
}