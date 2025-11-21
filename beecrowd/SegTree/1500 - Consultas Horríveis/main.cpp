#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
struct segtree_inc
{
    ll n;
    vector<ll> seg, lazy;
    segtree_inc(ll n)
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

            if (r != l)
            {
                lazy[2 * idx] += lazy[idx];
                lazy[2 * idx + 1] += lazy[idx];
            }

            lazy[idx] = 0;
        }
    }

    void update(ll idx, ll l, ll r, ll ql, ll qr, ll val)
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
        update(2 * idx, l, mid, ql, qr, val);
        update(2 * idx + 1, mid + 1, r, ql, qr, val);

        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    long long query(ll idx, ll l, ll r, ll ql, ll qr)
    {
        push(idx, l, r);

        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return seg[idx];

        ll mid = (l + r) / 2;

        return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
    }

    void build(vector<ll> &a) { build(a, 1, 0, n - 1); }
    void update(ll l, ll r, ll val) { update(1, 0, n - 1, l, r, val); }
    ll query(ll ql, ll qr) { return query(1, 0, n - 1, ql, qr); }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        vector<ll> a(n,0);
        segtree_inc arvore(n);
        arvore.build(a);
        for (int i = 0; i < c; i++)
        {
            ll x;
            cin >> x;
            if (x == 0)
            {
                ll ql, qr, val;
                cin >> ql >> qr >> val;
                arvore.update(--ql, --qr, val);
            }
            else
            {
                ll ql, qr;
                cin >> ql >> qr;
                cout << arvore.query(--ql, --qr) << endl;
            }
        }
    }
}