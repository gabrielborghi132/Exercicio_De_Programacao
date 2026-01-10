#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int soma = 0;
    if (a > b)
        swap(a, b);
    if (a == b && a % 13 != 0)
    {
        cout << a << endl;
        return 0;
    }
    for (int i = a; i <= b; i++)
    {
        if (i % 13 != 0)
        {
            soma += i;
        }
    }
    cout << soma << endl;
}