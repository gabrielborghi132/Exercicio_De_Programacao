#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
struct Node
{
    int min_val;
    int max_val;
};

struct segTree
{
    int n;
    vector<Node> seg;
    segTree(int n)
    {
        this->n = n;

        seg.resize(4 * n);
    }
    Node merge(Node a, Node b)
    {
        Node res;

        res.min_val = min(a.min_val, b.min_val);

        res.max_val = max(a.max_val, b.max_val);

        return res;
    }
    void build(vector<int> &a, int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = {a[l], a[l]};
            return;
        }

        int mid = (l + r) / 2;

        build(a, 2 * idx, l, mid);
        build(a, 2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
        {
            return {INT_MAX, -1};
        }
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }
        int mid = (l + r) / 2;
        return merge(query(2 * idx, l, mid, ql, qr), query(2 * idx + 1, mid + 1, r, ql, qr));
    }

    void update(int idx, int l, int r, int pos, Node val)
    {
        if (l == r)
        {
            seg[idx] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            update(2 * idx, l, mid, pos, val);
        }
        else
        {
            update(2 * idx + 1, mid + 1, r, pos, val);
        }
        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }
    void build(vector<int> &a) { build(a, 1, 1, n); } 
    Node query(int ql, int qr) { return query(1, 1, n, ql, qr); }
    void update(int pos, Node val) { update(1, 1, n, pos, val); }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n) {
        vector<int> a(n + 1);

        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }

        segTree arvore(n);
        arvore.build(a);
        
        int q; 
        cin >> q;
        
        while(q--) {
            int tipo;
            cin >> tipo;
            
            if(tipo == 1) {
                int i, p;
                cin >> i >> p;
                arvore.update(i, {p, p});
            } 
            else {
                int i, j;
                cin >> i >> j;
                Node res = arvore.query(i, j);
                cout << res.max_val - res.min_val << endl;
            }
        }
    }
    return 0;
}