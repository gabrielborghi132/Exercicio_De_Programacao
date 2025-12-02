/**************************************************/
//         1192 - O jogo Matemático de Paula
//https://judge.beecrowd.com/pt/problems/view/1192*/
/**************************************************/

#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int primeiro, ultimo;
        primeiro = s[0] - '0';
        ultimo = s[2] - '0';
        if (s[0] == s[2])
        {
            cout << primeiro * ultimo << endl;
        }
        else if (s[1] >= 'A' && s[1] <= 'Z')
        {
            cout << ultimo - primeiro << endl;
        }
        else if (s[1] >= 'a' && s[1] <= 'z')
        {
            cout << primeiro + ultimo << endl;
        }
    }
    return 0;
}