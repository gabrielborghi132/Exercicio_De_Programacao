/**************************************************/
//        Xenia and Bit Operations
// https://codeforces.com/contest/339/problem/D
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
struct segTree
{
    ll n;
    vector<ll> seg;

    segTree(ll n)
    {
        this->n = n;
        seg.resize((1 << n) * 4);
    }
    void build(vector<ll> &a, ll idx, ll l, ll r, bool operacao)
    {
        if (l == r)
        {
            seg[idx] = a[l];
            return;
        }

        ll mid = (l + r) / 2;

        build(a, idx * 2, l, mid, !operacao);
        build(a, idx * 2 + 1, mid + 1, r, !operacao);

        if (operacao)
        {
            seg[idx] = seg[2 * idx] | seg[2 * idx + 1];
        }
        else
        {
            seg[idx] = seg[2 * idx] ^ seg[2 * idx + 1];
        }
    }
    ll query(ll idx, ll l, ll r, ll ql, ll qr, bool operacao)
    {
        if (ql > r || qr < l)
        {
            return 0;
        }
        else if (ql <= l && r <= qr)
        {
            return seg[idx];
        }

        ll mid = (l + r) / 2;

        if (operacao)
        {
            return query(2 * idx, l, mid, ql, qr, !operacao) | query(2 * idx + 1, mid + 1, r, ql, qr, !operacao);
        }
        else
        {
            return query(2 * idx, l, mid, ql, qr, !operacao) ^ query(2 * idx + 1, mid + 1, r, ql, qr, !operacao);
        }
    }

    void update(ll idx, ll l, ll r, ll pos, ll val, bool operacao)
    {

        if (l == r)
        {
            seg[idx] = val;
            return;
        }
        ll mid = (l + r) / 2;

        if (pos <= mid)
        {
            update(2 * idx, l, mid, pos, val, !operacao);
        }
        else
        {
            update(2 * idx + 1, mid + 1, r, pos, val, !operacao);
        }
        if (operacao)
        {
            seg[idx] = seg[2 * idx] | seg[2 * idx + 1];
        }
        else
        {
            seg[idx] = seg[2 * idx] ^ seg[2 * idx + 1];
        }
    }

    void build(vector<ll> &a, bool operacao) { build(a, 1, 1, 1<<n, operacao); }
    int query(ll ql, ll qr, bool operecao) { return query(1, 1, 1<<n, ql, qr, operecao); }
    void update(ll pos, ll val, bool operacao) { update(1, 1, 1<<n, pos, val, operacao); }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    ll N = 1LL << n;
    vector<ll> a(N + 1, 0);
    bool operacao = true;
    for (ll i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    segTree arvore(n);
    if (n % 2 == 0)
    {
        arvore.build(a, false);
        operacao = false;
    }
    else
    {
        arvore.build(a, true);
        operacao = true;
    }

    for (ll i = 0; i < m; i++)
    {
        int c, b;
        cin >> c >> b;
        arvore.update(c, b, operacao);
        cout << arvore.seg[1] << endl;
    }
}