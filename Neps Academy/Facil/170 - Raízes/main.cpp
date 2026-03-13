#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        cout << fixed << setprecision(4) << sqrt(x) << endl;
    }
}