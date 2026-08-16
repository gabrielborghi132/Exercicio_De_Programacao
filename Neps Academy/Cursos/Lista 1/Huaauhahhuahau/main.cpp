#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string s2;
    getline(cin, s);
    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
    for (auto &x : s)
    {
        if (st.find(x) != st.end())
        {
            s2 += x;
        }
    }
    ll l = 0;
    ll j = s2.length() - 1;
    char res = 'S';
    while (l < j)
    {
        if (s2[l] != s2[j])
        {
            res = 'N';
            break;
        }
        l++;
        j--;
    }
    cout << res << endl;
    return 0;
}