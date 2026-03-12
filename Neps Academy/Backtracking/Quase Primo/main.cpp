/*
    TEMPLATE: Inclusão-Exclusão com Backtracking

    USO: Contar quantos inteiros de 1 a N são (ou não são)
         divisíveis por pelo menos um elemento de um conjunto.

    IDEIA:
    - Subconjuntos de tamanho ímpar → SOMA  N / produto
    - Subconjuntos de tamanho par   → SUBTRAI N / produto
    - Poda: se produto > N, o ramo não contribui

    COMPLEXIDADE:
    - Pior caso: O(2^K), mas com poda fica muito menor
    - Na prática, subconjuntos com produto > N são cortados cedo

    QUANDO USAR:
    - "Quantos números de 1 a N não são divisíveis por nenhum primo da lista?"
    - "Quantos números de 1 a N são coprimos com certo valor?"
    - Qualquer contagem envolvendo divisibilidade + múltiplos fatores
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N; // limite superior
ll K; // quantidade de primos/fatores

// resposta acumula o total de divisíveis por pelo menos um fator
// (usando inclusão-exclusão)
void backtrack(ll indice, ll produto, ll tam_subconjunto, vector<ll> &fatores, ll &resposta)
{
    for (int i = indice; i < K; i++)
    {
        ll novo_produto = produto * fatores[i];

        // PODA: se o produto já passou de N, esse fator não contribui
        // mas outros menores ainda podem, então usamos continue
        if (novo_produto > N)
            continue;

        // SINAL: subconjunto de tamanho ímpar soma, par subtrai
        if ((tam_subconjunto + 1) % 2 == 1)
            resposta += N / novo_produto;
        else
            resposta -= N / novo_produto;

        // RECURSÃO: avança para o próximo fator
        backtrack(i + 1, novo_produto, tam_subconjunto + 1, fatores, resposta);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    vector<ll> fatores(K);
    for (int i = 0; i < K; i++)
        cin >> fatores[i];

    ll resposta = 0;
    backtrack(0, 1, 0, fatores, resposta);

    // resposta = quantos SÃO divisíveis por pelo menos um fator
    // Se o problema pede os NÃO divisíveis:
    cout << N - resposta << endl;

    // Se o problema pede os divisíveis:
    // cout << resposta << endl;

    return 0;
}