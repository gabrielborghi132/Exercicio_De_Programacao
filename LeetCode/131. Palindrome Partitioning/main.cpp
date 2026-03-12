#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool ehPalindromo(string s)
{
    int i = 0;
    int j = (int)s.size() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void backtrack(int start, vector<vector<string>> &resposta, string &opcoes, vector<string> &atual)
{
    if (start == (int)opcoes.size())
    {
        resposta.push_back(atual);
        return;
    }

    for (int i = start; i < (int)opcoes.size(); i++)
    {
        string s = opcoes.substr(start, i - start + 1);
        if (ehPalindromo(s))
        {
            atual.push_back(s);
            backtrack(i + 1, resposta, opcoes, atual);
            atual.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<string>> resposta;
    vector<string> atual;
    string opcoes = "aab";

    backtrack(0, resposta, opcoes, atual);

    for (auto &particao : resposta)
    {
        for (auto &s : particao)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}