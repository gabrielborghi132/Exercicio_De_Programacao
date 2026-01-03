#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
ll soma = 0;
void backtracking(vector<vector<ll>> &resposta, ll start, vector<ll> &atual, vector<bool> &usados, vector<ll> &opcoes)
{
    if (soma == 9 && atual.size() == 3)
    {
        resposta.push_back(atual);
        return;
    }
    if (soma > 9 || atual.size() > 3)
        return;
    for (int i = start; i < opcoes.size(); i++)
    {
        if (usados[opcoes[i]])
            continue;
        if (soma + opcoes[i] > 9)
            continue;
        soma += opcoes[i];
        atual.push_back(opcoes[i]);
        usados[opcoes[i]] = true;
        backtracking(resposta, i + 1, atual, usados, opcoes);
        soma -= opcoes[i];
        atual.pop_back();
        usados[opcoes[i]] = false;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ll>> resposta;
    vector<bool> usados(10, false);
    vector<ll> opcoes = {1, 2, 3, 4, 5};
    vector<ll> atual;
    backtracking(resposta, 0, atual, usados, opcoes);

    for (auto i : resposta)
    {
        cout << "{ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "}" << endl;
    }
}