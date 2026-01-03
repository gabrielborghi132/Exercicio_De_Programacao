/**************************************************/
//         22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/description/?envType=problem-list-v2&envId=backtracking*/
//
/**************************************************/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
void resolver(string opcoes, vector<string> &respostas, string atual, int n, int esq, int dir)
{
    if (atual.size() == 2 * n && esq == n && dir == n)
    {
        respostas.push_back(atual);
        return;
    }

    for (auto &item : opcoes)
    {
        if (item == '(' && esq == n)
            continue;
        if (item == ')' && dir == n)
            continue;
        atual.push_back(item);
        if (item == '(' && esq < n)
            resolver(opcoes, respostas, atual, n, esq + 1, dir);
        if (item == ')' && dir < esq)
            resolver(opcoes, respostas, atual, n, esq, dir + 1);
        atual.pop_back();
    }
}
int main()
{
    string opcoes = "()";
    vector<string> resposta;
    int n = 3;
    resolver(opcoes, resposta, "", n, 0, 0);
    for (auto &a : resposta)
    {
        cout << a << endl;
    }
}