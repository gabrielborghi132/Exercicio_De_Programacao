#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll soma_1 = 0;
    ll soma_2 = 0;
    ll soma_3 = 0;

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            if (i == 0)
                soma_1 += x;
            else if (i == 1)
                soma_2 += x;
            else
                soma_3 += x;
        }
    }
    cout << "Linha 0: " << soma_1 << endl;
    cout << "Linha 1: " << soma_2 << endl;
    cout << "Linha 2: " << soma_3 << endl;
}