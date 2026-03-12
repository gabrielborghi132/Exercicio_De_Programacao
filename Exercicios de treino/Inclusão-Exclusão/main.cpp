#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
ll n, a, b, c;
int main()
{
    cin >> n >> a >> b >> c;

    ll soma = (n / a) + (n / b) - (n / (a * b)) - (n / (a * c)) - (n / (b * c)) + (n / (a * b * c));

    cout << soma << endl;
}