#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int i = 0;
    do
    {
        if (t % 2 == 0 && i == 0)
        {
            t++;
        }
        i++;
        cout << t << endl;
        t += 2;
    } while (i < 6);
}