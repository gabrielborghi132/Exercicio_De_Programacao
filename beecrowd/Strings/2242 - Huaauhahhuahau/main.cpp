/**************************************************/
//        2242 - Huaauhahhuahau
// https://judge.beecrowd.com/pt/problems/view/2242
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    string s2;
    getline(cin, s);
    unordered_set<char> mp = {'a', 'e', 'i', 'o', 'u'};

    for (auto &a : s)
    {
        if (mp.find(a) != mp.end())
        {
            s2.push_back(a);
        }
    }
    int ini = 0;
    int fim = s2.size()-1;

    while (ini < fim)
    {
        if (s2[ini] != s2[fim])
        {
            cout << "N" << endl;
            return 0;
        }
        ini++;
        fim--;
    }
    cout << "S" << endl;
    return 0;
}