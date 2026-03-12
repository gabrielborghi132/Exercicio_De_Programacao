#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void backtrack(vector<vector<int>> &resposta, vector<int> &opcoes, vector<int> &atual, int mask, int n)
{
    if (mask == (1 << n) - 1)
    {
        resposta.push_back(atual);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            continue;
        if (i > 0 && opcoes[i] == opcoes[i - 1] && !(mask & (1 << (i - 1))))
            continue;
        atual.push_back(opcoes[i]);

        backtrack(resposta, opcoes, atual, mask | (1 << i), n);

        atual.pop_back();
    }
}
int main()
{
    vector<int> opcoes = {1, 1, 2};
    int n = opcoes.size();
    vector<vector<int>> resposta;
    vector<int> atual;
    int mask = 0;
    sort(opcoes.begin(), opcoes.end());
    backtrack(resposta, opcoes, atual, mask, n);

    for (auto &v : resposta)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
}