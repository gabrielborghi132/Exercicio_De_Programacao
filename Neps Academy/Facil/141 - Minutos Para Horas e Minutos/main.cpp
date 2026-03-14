#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll minutos;
    cin >> minutos;

    cout << (1 * minutos) / 60 << endl;
    minutos %= 60;
    cout << minutos << endl;
}