#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
void backtracking(vector<vector<ll>> &respostas, vector<ll> &atual, vector<bool> &used, vector<ll> &opcoes)
{
    if (respostas.size() >= 1)
        return;
    if (atual.size() == 6)
    {
        ll primeira = atual[0] + atual[1] + atual[2];
        ll segunda = atual[3] + atual[4];
        ll terceira = atual[5];
        if (primeira == segunda && primeira == terceira)
        {
            respostas.push_back(atual);
        }
        return;
    }
    for (int i = 0; i < opcoes.size(); i++)
    {
        if (used[i])
            continue;
        atual.push_back(opcoes[i]);
        used[i] = true;
        backtracking(respostas, atual, used, opcoes);
        atual.pop_back();
        used[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> opcoes(6, 0);
    for (int i = 0; i < 6; i++)
    {
        cin >> opcoes[i];
    }
    vector<vector<ll>> respostas;
    vector<bool> used(2000, false);
    vector<ll> atual;

    backtracking(respostas, atual, used, opcoes);

    if (respostas.empty())
        cout << "N" << endl;
    else
        cout << "S" << endl;
}