#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    n -= 3;
    n = n % 8;
    if (n == 3)
        cout << 1 << endl;
    else if (n == 4)
        cout << 2 << endl;
    else
        cout << 3 << endl;
    return 0;
}