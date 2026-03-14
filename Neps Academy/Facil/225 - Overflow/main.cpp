#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ll a, b, d;
    char c;

    cin >> a >> b >> c >> d;

    if (c == '+')
    {
        if (b + d > a)
            cout << "OVERFLOW" << endl;
        else
            cout << "OK" << endl;
    }
    else
    {
        if (b * d > a)
            cout << "OVERFLOW" << endl;
        else
            cout << "OK" << endl;
    }
}