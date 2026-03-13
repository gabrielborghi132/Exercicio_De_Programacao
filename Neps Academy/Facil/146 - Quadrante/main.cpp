#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    if (a == 0 || b == 0)
        cout << "eixos" << endl;
    else if (a > 0 && b > 0)
        cout << "Q1" << endl;
    else if (a < 0 && b > 0)
        cout << "Q2" << endl;
    else if (a < 0 && b < 0)
        cout << "Q3" << endl;
    else if (a > 0 && b < 0)
        cout << "Q4" << endl;
}