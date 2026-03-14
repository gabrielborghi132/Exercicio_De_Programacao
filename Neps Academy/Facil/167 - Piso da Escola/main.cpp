#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ll a, b;
    cin >> a >> b;

    ll lad_tipo_1 = a * b + (b - 1) * (a - 1);
    ll lad_tipo_2 = (a - 1) * 2 + (b - 1) * 2;

    cout << lad_tipo_1 << endl;
    cout << lad_tipo_2 << endl;
}