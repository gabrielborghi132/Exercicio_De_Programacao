#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
string solve(int N, int X, const vector<int> &A)
{
    for (int i = 0; i < N; i++)
    {
        if (A[i] == X)
            return "YES";
    }
    return "NO";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vt{7, 3, 5, 2, 1};
    cout << solve(5, 10, vt) << endl;
    return 0;
}
