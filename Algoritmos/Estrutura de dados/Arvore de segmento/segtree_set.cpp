#include <bits/stdc++.h>
using namespace std;

struct segtree_set {
    int n;                     // tamanho do vetor original
    vector<int> seg, lazy;     // seg = árvore; lazy = valores pendentes de set
    vector<bool> haslazy;      // indica se existe operação pendente no nó

    // construtor
    segtree_set(int n) {
        this->n = n;                  // guarda tamanho
        seg.assign(4 * n, 0);         // inicializa árvore (para soma)
        lazy.assign(4 * n, 0);        // valor pending para SET
        haslazy.assign(4 * n, false); // flag indicando se existe operação
    }

    // construir árvore usando um vetor "a"
    void build(vector<int> &a, int idx, int l, int r) {
        if (l == r) {
            seg[idx] = a[l];          // nó folha recebe valor direto
            return;
        }

        int mid = (l + r) / 2;        // calcula ponto médio

        build(a, 2 * idx, l, mid);           // constrói filho esquerdo
        build(a, 2 * idx + 1, mid + 1, r);   // constrói filho direito

        seg[idx] = seg[2 * idx] + seg[2 * idx + 1]; // soma dos filhos
    }

    // empurra lazy para baixo
    void push(int idx, int l, int r) {
        if (haslazy[idx]) {                           // só aplica se existe lazy pendente
            seg[idx] = lazy[idx] * (r - l + 1);       // atualiza valor do intervalo inteiro

            if (l != r) {                             // se não for folha, propaga pros filhos
                lazy[2 * idx] = lazy[idx];            // filho esquerdo recebe o valor
                lazy[2 * idx + 1] = lazy[idx];        // filho direito recebe o valor
                haslazy[2 * idx] = true;              // marca lazy existente no filho esquerdo
                haslazy[2 * idx + 1] = true;          // marca lazy existente no filho direito
            }

            haslazy[idx] = false;                     // limpa flag do nó atual
        }
    }

    // update em intervalo [ql, qr] atribuindo valor val
    void update_range(int idx, int l, int r, int ql, int qr, int val) {
        push(idx, l, r);                               // garante que o nó está atualizado

        if (qr < l || ql > r) return;                  // intervalo completamente fora

        if (ql <= l && r <= qr) {                      // intervalo totalmente dentro
            lazy[idx] = val;                           // define o valor pendente
            haslazy[idx] = true;                       // marca que existe lazy
            push(idx, l, r);                           // aplica imediatamente
            return;
        }

        int mid = (l + r) / 2;                         // calcula o meio

        update_range(2 * idx, l, mid, ql, qr, val);        // atualiza lado esquerdo
        update_range(2 * idx + 1, mid + 1, r, ql, qr, val);// atualiza lado direito

        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];    // recalcula valor com base nos filhos
    }

    // consulta no intervalo [ql, qr]
    int query(int idx, int l, int r, int ql, int qr) {
        push(idx, l, r);                               // aplica lazy antes da consulta

        if (qr < l || ql > r) return 0;                // completamente fora
        if (ql <= l && r <= qr) return seg[idx];       // totalmente dentro

        int mid = (l + r) / 2;                         // calcula meio

        // soma dos dois lados (pois sua segtree é de soma)
        return query(2 * idx, l, mid, ql, qr) +
               query(2 * idx + 1, mid + 1, r, ql, qr);
    }

    // interfaces para simplificar o uso externo
    void build(vector<int> &a) { build(a, 1, 0, n - 1); }              // construir árvore
    void update_range(int l, int r, int val) {                         // atualizar intervalo
        update_range(1, 0, n - 1, l, r, val);
    }
    int query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }   // consultar intervalo
};
