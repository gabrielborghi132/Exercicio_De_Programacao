/**************************************************/
//        1235 - De Dentro para Fora
// https://judge.beecrowd.com/pt/problems/view/1235
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    int n;
    cin>>n;
    cin.ignore();
    while (n--)
    {
        string s;
        getline(cin,s);
        string s1 = s.substr(0, s.size() / 2);
        string s2 = s.substr(s.size() / 2, s.size());

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        cout << s1 + s2 << endl;
    }
}