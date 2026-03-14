#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    char c;
    cin >> s >> c;
    cout << count(s.begin(), s.end(), c) << endl;
}