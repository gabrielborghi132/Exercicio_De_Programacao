#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct fenwick
{
    int n;
    vector<long long> tree;

    fenwick(int n)
    {
        this->n = n;
        tree.assign(n + 1, 0);
    }

    void build(const vector<int> &v)
    {
        for (int i = 1; i <= n; i++)
        {
            tree[i] += v[i];
            int j = i + (i & -i);
            if (j <= n)
            {
                tree[j] += tree[i];
            }
        }
    }

    void update(int k, int v)
    {
        while (k <= n)
        {
            tree[k] += v;
            k += k & -k;
        }
    }

    long long sum(int k)
    {
        long long soma = 0;
        while (k >= 1)
        {
            soma += tree[k];
            k -= k & -k;
        }
        return soma;
    }

    long long query(int a, int b)
    {
        if (a > b)
            return 0;
        return sum(b) - sum(a - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> vt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vt[i];
    }

    fenwick bit(n);
    bit.build(vt);

    while (q--)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 2)
        {
            cout << bit.query(a, b) << endl;
        }
        else
        {
            int delta = b - vt[a];
            bit.update(a, delta);
            vt[a] = b;
        }
    }
    return 0;
}