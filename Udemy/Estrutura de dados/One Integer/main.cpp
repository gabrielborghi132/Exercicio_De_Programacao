#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int solve(vector<int> vt)
{
    int a, b, soma = 0;
    priority_queue<int, vector<int>, greater<int>> pq(vt.begin(), vt.end());
    while (pq.size() != 1)
    {
        a = pq.top();
        pq.pop();
        b = pq.top();
        soma += a + b;
        pq.pop();
        pq.push(a + b);
    }
    return soma;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vt = {5, 4, 3, 2, 1};
    cout << solve(vt) << endl;
}