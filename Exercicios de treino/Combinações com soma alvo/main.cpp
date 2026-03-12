#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void backtracking(vector<vector<ll>> &respostas, ll start, vector<ll> &atual,
                  vector<ll> &opcoes, ll alvo, ll soma_atual)
{
    if (soma_atual == alvo)
    {
        respostas.push_back(atual);
        return;
    }

    for (int i = start; i < (int)opcoes.size(); i++)
    {
        if (soma_atual + opcoes[i] > alvo)
            break; // poda eficiente (opcoes ordenado)

        atual.push_back(opcoes[i]);
        backtracking(respostas, i, atual, opcoes, alvo, soma_atual + opcoes[i]);
        atual.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<ll>> resposta;
    vector<ll> opcoes = {2, 3, 6, 7};
    vector<ll> atual;
    ll alvo = 7;

    sort(opcoes.begin(), opcoes.end()); // garante que o break funciona
    backtracking(resposta, 0, atual, opcoes, alvo, 0);

    for (auto i : resposta)
    {
        cout << "{ ";
        for (auto j : i)
            cout << j << " ";
        cout << "}" << endl;
    }
}