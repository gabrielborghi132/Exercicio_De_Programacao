#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    while (cin >> a >> b, a)
    {
        cin.ignore();
        string str;
        getline(cin, str);
        string s = "";
        ll k = b;
        for (ll i = 0; i < a; i++)
        {

            while (k > 0 && !s.empty() && str[i] > s.back())
            {
                s.pop_back();
                k--;
            }
            s.push_back(str[i]);
        }
        while (k--)
            s.pop_back();
        cout << s << endl;
    }
    return 0;
}