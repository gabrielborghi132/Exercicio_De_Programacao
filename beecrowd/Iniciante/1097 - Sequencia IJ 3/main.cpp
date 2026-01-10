#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int i = 1;
    int j = 7;
    int i_con = 1;
    int j_con = 7;
    while (i != 11)
    {
        i_con = i;
        j_con = j;
        for (int a = 0; a < 3; a++)
        {
            cout << "I=" << i_con << " J=" << j_con << endl;
            j_con--;
        }
        i += 2;
        j += 2;
    }
}