#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
struct fenwick {
    int n;
    vector<int> tree;

    fenwick(int n) {
        this->n = n;
        // Corrigido: n + 1 para suportar índices de 1 até n
        tree.assign(n + 1, 0); 
    }
    void build(const vector<int>& v) {
        // v é o vetor original (0-indexed)
        for (int i = 1; i <= n; i++) {
            tree[i] += v[i-1]; // Adiciona o valor atual
            int j = i + (i & -i); // Calcula o sucessor direto
            if (j <= n) {
                tree[j] += tree[i]; // Propaga a soma para o pai
            }
        }
    }
    void update(int k, int v) {
        // k deve ser >= 1
        while (k <= n) {
            tree[k] += v;
            k += k & -k; // Sobe para o pai/responsável
        }
    }

    int sum(int k) {
        int soma = 0;
        // Soma os prefixos descendo na árvore
        while (k >= 1) {
            soma += tree[k];
            k -= k & -k; // Remove o bit menos significativo
        }
        return soma;
    }

    // Dica do Professor: Função utilitária para soma de intervalo [a, b]
    int query(int a, int b) {
        if (a > b) return 0;
        return sum(b) - sum(a - 1);
    }
};  
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}