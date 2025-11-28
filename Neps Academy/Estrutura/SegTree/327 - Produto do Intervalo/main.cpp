#include <bits/stdc++.h>
using namespace std;

struct segTree
{
    int n;
    vector<long long> seg, lazy;
    vector<bool> haslazy;

    segTree(int n)
    {
        this->n = n;
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        haslazy.assign(4 * n, false);
    }

    long long binpow(long long base, long long exp)
    {
        long long res = 1;
        while (exp > 0)
        {
            if (exp % 2 == 1)
                res = res * base;
            base = base * base;
            exp /= 2;
        }
        return res;
    }

    void build(vector<int> &a, int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(a, 2 * idx, l, mid);
        build(a, 2 * idx + 1, mid + 1, r);

        seg[idx] = seg[2 * idx] * seg[2 * idx + 1];
    }

    void push(int idx, int l, int r)
    {
        if (haslazy[idx])
        {
            int range_len = (r - l + 1);
            seg[idx] = binpow(lazy[idx], range_len);

            if (l != r)
            {
                lazy[2 * idx] = lazy[idx];
                lazy[2 * idx + 1] = lazy[idx];
                haslazy[2 * idx] = true;
                haslazy[2 * idx + 1] = true;
            }
            haslazy[idx] = false;
        }
    }

    void update_range(int idx, int l, int r, int ql, int qr, int val)
    {
        push(idx, l, r);
        if (qr < l || ql > r)
            return;

        if (ql <= l && r <= qr)
        {
            lazy[idx] = val;
            haslazy[idx] = true;
            push(idx, l, r);
            return;
        }

        int mid = (l + r) / 2;

        update_range(2 * idx, l, mid, ql, qr, val);
        update_range(2 * idx + 1, mid + 1, r, ql, qr, val);

        seg[idx] = seg[2 * idx] * seg[2 * idx + 1];
    }

    long long query(int idx, int l, int r, int ql, int qr)
    {
        push(idx, l, r);

        if (qr < l || ql > r)
            return 1;

        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        return query(2 * idx, l, mid, ql, qr) *
               query(2 * idx + 1, mid + 1, r, ql, qr);
    }

    void build(vector<int> &a) { build(a, 1, 0, n - 1); }
    void update_range(int l, int r, int val)
    {
        update_range(1, 0, n - 1, l, r, val);
    }
    long long query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
};

int main()
{
    int n, k;
    while (cin >> n >> k)
    {

        vector<int> a(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        segTree arvore(n);
        arvore.build(a);
        for (int i = 0; i < k; i++)
        {
            char c;
            int a;
            int b;
            cin>>c>>a>>b;
            if(c=='C'){
                arvore.update_range(a,a,b);
            }else{
                arvore.query(a,b);
            }
        }
    }
}