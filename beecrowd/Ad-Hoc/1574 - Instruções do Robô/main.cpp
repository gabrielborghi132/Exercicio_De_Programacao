#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0;
    cin >> n;
    while (n--)
    {
        int t = 0;
        cin >> t;
        string s = "";
        vector<int> palavras(101, 0);
        int sum = 0;
        cin.ignore();
        string s2, word;
        string linha;
        for (int i = 0; i < t; i++)
        {
            getline(cin, s);
            if (s == "LEFT")
            {
                sum--;
                palavras[i] = -1;
            }
            else if (s == "RIGHT")
            {
                sum++;
                palavras[i] = 1;
            }
            else
            {
                stringstream ss(s);
                vector<string> vt;

                while (ss >> word)
                    vt.push_back(word);
                palavras[i] = palavras[stoi(vt[2]) - 1];
                sum += palavras[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}