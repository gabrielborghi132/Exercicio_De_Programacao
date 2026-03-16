#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

void backtrack(vector<vector<ll>> &respostas, vector<ll> &atual, ll start, vector<ll> &opcoes)
{
    respostas.push_back(atual);

    for (int i = start; i < (int)opcoes.size(); i++)
    {
        if (i > start && opcoes[i] == opcoes[i - 1])
            continue;
        atual.push_back(opcoes[i]);
        backtrack(respostas, atual, i + 1, opcoes);
        atual.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<ll>> respostas;
    vector<ll> atual;
    ll start = 0;
    vector<ll> opcoes = {1, 2, 2};
    backtrack(respostas, atual, start, opcoes);

    for (auto &i : respostas)
    {
        cout << "[";
        for (auto &x : i)
        {
            cout << x << " ";
        }
        cout << "]" << endl;
    }
}