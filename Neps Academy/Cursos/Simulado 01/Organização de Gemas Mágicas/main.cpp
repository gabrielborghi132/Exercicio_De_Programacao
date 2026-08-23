#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> vt(26, 0);
    string s;
    getline(cin, s);
    for (auto &x : s)
    {
        vt[x - 'a']++;
    }
    string res = "";
    unordered_set<char> st;
    for (auto &x : s)
    {
        if (st.find(x) == st.end())
        {
            res += string(vt[x - 'a'], x);
        }
        st.insert(x);
    }
    cout << res << endl;
    return 0;
}