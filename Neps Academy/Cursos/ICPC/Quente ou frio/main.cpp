#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if (n > 10)
        cout << "Frio" << endl;
    else if (n >= 6)
        cout << "Morno" << endl;
    else if (n >= 3)
        cout << "Quente" << endl;
    else
        cout << "Fervendo" << endl;
    return 0;
}