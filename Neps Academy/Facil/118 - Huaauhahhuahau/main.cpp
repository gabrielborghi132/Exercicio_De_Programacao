#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

bool eh_palindromo(const string &s)
{
    ll i = 0;
    ll j = s.size() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
string tira_consoante(const string &s)
{
    unordered_set<char> mp = {'a', 'e', 'i', 'o', 'u'};
    string s2;
    for (auto &x : s)
    {
        if (mp.find(x) != mp.end())
            s2.push_back(x);
    }
    return s2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    s = tira_consoante(s);
    if (eh_palindromo(s))
        cout << 'S' << endl;
    else
        cout << 'N' << endl;
}