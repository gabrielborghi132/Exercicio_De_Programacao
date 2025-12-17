/**************************************************/
//        Knight Tournament
// https://codeforces.com/contest/356/problem/A
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
        seg.assign(n * 4, 0);
    }
    void update(ll idx, ll l, ll r, ll ql, ll qr, ll winner, vector<ll> &ans)
    {
        if (seg[idx] == 1)
            return;
        if (l > qr || r < ql)
            return;

        if (l == r)
        {
            if (l != winner)
            {
                seg[idx] = 1;
                ans[l] = winner;
            }
            return;
        }

        ll mid = (l + r) / 2;
        update(2 * idx, l, mid, ql, qr, winner, ans);
        update(2 * idx + 1, mid + 1, r, ql, qr, winner, ans);

        seg[idx] = seg[2 * idx] & seg[2 * idx + 1];
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    segTree arvore(n);
    
    vector<ll> ans(n + 1, 0); 

    for (ll i = 0; i < m; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        arvore.update(1, 1, n, l, r, x, ans); 
    }

    for(ll i = 1; i <= n; i++){
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << endl;
}