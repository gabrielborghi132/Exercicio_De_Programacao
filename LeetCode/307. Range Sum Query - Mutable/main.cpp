#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    int n;
    vector<int> seg;

    SegTree() : n(0) {}

    SegTree(int n) : n(n)
    {
        seg.assign(4 * n, 0);
    }

    void build(const vector<int> &a, int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, 2 * idx, l, mid);
        build(a, 2 * idx + 1, mid + 1, r);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    int query(int idx, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return seg[idx];
        int mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) +
               query(2 * idx + 1, mid + 1, r, ql, qr);
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
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }

    void build(vector<int> &a) { build(a, 1, 0, n - 1); }
    int query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
    void update(int pos, int val) { update(1, 0, n - 1, pos, val); }
};

class NumArray
{
private:
    int n;
    SegTree st;

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        st = SegTree(n);
        st.build(nums);
    }

    void update(int index, int val)
    {
        st.update(index, val);
    }

    int sumRange(int left, int right)
    {
        return st.query(left, right);
    }
};
