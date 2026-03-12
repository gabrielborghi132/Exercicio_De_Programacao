#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
void backtrack(vector<ll> &opcoes, vector<ll> &atual, vector<bool> &usados)
{
    if (atual.size() == opcoes.size() && atual[0] == 1)
    {
        cout << "[";
        for (auto &x : atual)
        {
            cout << x << " ";
        }
        cout << "]" << endl;
        return;
    }
    for (int i = 0; i < (int)opcoes.size(); i++)
    {
        if (usados[i] == true)
            continue;
        usados[i] = true;
        atual.push_back(opcoes[i]);
        if (atual[0] != 1)
        {
            atual.pop_back();
            usados[i] = false;
            continue;
        }
        backtrack(opcoes, atual, usados);
        atual.pop_back();
        usados[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> opcoes = {1, 2, 3};
    vector<ll> atual;
    vector<bool> usados(1000, false);
    backtrack(opcoes, atual, usados);
}