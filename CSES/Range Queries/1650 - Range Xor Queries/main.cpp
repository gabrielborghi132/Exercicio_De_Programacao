#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
void prefiXor(vector<int> &a, int n, vector<int> &preXor)
{
    preXor[0] = a[0];
    for (int i = 1; i <= n; i++)
        preXor[i] = preXor[i - 1] ^ a[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    vector<int> preXor(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    prefiXor(a, n, preXor);
    for (int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (preXor[b] ^ preXor[a - 1]) << endl;
    }
}