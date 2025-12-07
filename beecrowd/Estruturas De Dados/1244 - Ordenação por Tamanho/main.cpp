/**************************************************/
//         1244 - Ordenação por Tamanho
//https://judge.beecrowd.com/pt/problems/view/1244*/
//
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool comp(const string &a, const string &b)
{
    return a.size() > b.size();
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string s;
        string word;
        vector<string> vt;

        getline(cin, s);
        stringstream ss(s);

        while (ss >> word)
        {
            vt.push_back(word);
        }

        stable_sort(vt.begin(), vt.end(), comp);

        for (int i = 0; i < vt.size(); i++)
        {
            cout << vt[i];
            if (i != vt.size() - 1)
                cout << " ";
        }
        cout << endl;
    }
}