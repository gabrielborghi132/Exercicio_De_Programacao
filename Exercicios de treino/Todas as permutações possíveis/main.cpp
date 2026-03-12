#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void gerar_permutacoes(vector<vector<ll>> &respostas, vector<ll> &atual, vector<bool> &used, vector<ll> &opcoes)
{
    if (atual.size() == opcoes.size())
    {
        respostas.push_back(atual);
        return;
    }

    for (int i = 0; i < (int)opcoes.size(); i++)
    {
        if (used[i])
            continue;

        atual.push_back(opcoes[i]);
        used[i] = true;

        gerar_permutacoes(respostas, atual, used, opcoes);

        atual.pop_back();
        used[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<ll>> resposta;
    vector<bool> used(3, false);
    vector<ll> opcoes = {1, 2, 3};
    vector<ll> atual;

    gerar_permutacoes(resposta, atual, used, opcoes);

    for (auto i : resposta)
    {
        cout << "{ ";
        for (auto j : i)
            cout << j << " ";
        cout << "}" << endl;
    }
}