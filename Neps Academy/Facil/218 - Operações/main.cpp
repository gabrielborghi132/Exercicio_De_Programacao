#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    char a;
    double b, c;
    cin >> a >> b >> c;
    if (a == 'M')
        cout << fixed << setprecision(2) << b * c << endl;
    else
        cout << fixed << setprecision(2) << b / c << endl;
}