#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num_decimal;

    cin >> num_decimal;
    if (num_decimal == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    bitset<32> binario(num_decimal);
    string s = binario.to_string();
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '0')
        {
            s = s.substr(i);
            break;
        }
    }
    cout << s << endl;
    return 0;
}
