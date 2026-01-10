#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    while (cin >> a >> b, a && b)
    {
        if (a > 0 && b > 0)
            cout << "primeiro" << endl;
        else if (a > 0 && b < 0)
            cout << "quarto" << endl;
        else if (a < 0 && b < 0)
            cout << "terceiro" << endl;
        else
            cout << "segundo" << endl;
    }
}