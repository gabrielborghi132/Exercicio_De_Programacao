#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

bool eh_primo(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int x;

    cin >> x;

    if (eh_primo(x))
    {
        cout << "S" << "\n";
    }
    else
    {
        cout << "N" << "\n";
    }
}