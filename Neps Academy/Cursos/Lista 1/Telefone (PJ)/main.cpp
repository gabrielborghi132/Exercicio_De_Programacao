#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string grupos = "abcdefghijklmnopqrstuvwxyz";
    string digitos = "22233344455566677778889999";
    vector<char> numeros(26);
    for (ll i = 0; i < 26; i++)
    {
        numeros[grupos[i] - 'a'] = digitos[i];
    }
    string s;
    string res;
    cin >> s;
    for (auto &x : s)
    {
        x = tolower(x);
        if (x == '1' || x == '-')
            res += x;
        else
            res += numeros[x - 'a'];
    }
    cout << res << endl;
    return 0;
}
