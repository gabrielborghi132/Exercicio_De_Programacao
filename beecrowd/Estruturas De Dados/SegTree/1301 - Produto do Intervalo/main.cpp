#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
struct segTree
{
    int n;
    vector<int> seg;
    segTree(int n)
    {
        this->n = n;
        seg.assign(4 * n, 1);
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

    int query(int idx, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
        {
            return 1;
        }
        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }

        int mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) * query(2 * idx + 1, mid + 1, r, ql, qr);
    }

    void update(int idx, int l, int r, int pos, int val)
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

        seg[idx] = seg[2 * idx] * seg[2 * idx + 1];
    }

    void build(vector<int> &a) { build(a, 1, 0, n - 1); }
    int query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
    void update(int pos, int val) { update(1, 0, n - 1, pos, val); }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    while (cin >> n >> k)
    {

        vector<int> a(n + 1);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x > 0)
            {
                a[i] = 1;
            }
            else if(x<0)
            {
                a[i] = -1;
            }else{
                a[i] = 0;
            }
        }
        segTree arvore(n);
        arvore.build(a);
        for (int i = 0; i < k; i++)
        {
            char c;
            int a;
            int b;
            cin >> c >> a >> b;
            a--;
            if (c == 'C')
            {
                int x = 1;
                if (b < 0)
                {
                    x = -1;
                }
                else if (b == 0)
                {
                    x = 0;
                }
                arvore.update(a, x);
            }
            else
            {
                b--;
                int res = arvore.query(a, b);
                if(res>0){
                    cout<<"+";
                }else if(res<0){
                    cout<<"-";
                }else{
                    cout<<"0";
                }
            }
        }
        cout<<endl;
    }
}