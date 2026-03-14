#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_set<char> mp = {'a', 'e', 'i', 'o', 'u'};

    string s;
    cin >> s;
    string vogal;
    string consoante;

    for (auto &x : s)
    {
        if (mp.find(x) != mp.end())
            vogal.push_back(x);
        else
            consoante.push_back(x);
    }
    cout << "Vogais: ";
    for (auto &x : vogal)
        cout << x;
    cout << endl;
    cout << "Consoantes: ";
    for (auto &x : consoante)
        cout << x;
    cout << endl;
}