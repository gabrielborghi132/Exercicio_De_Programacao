#include <bits/stdc++.h>
using namespace std;

struct segtree_inc {
    int n;                      // tamanho do vetor original
    vector<int> seg, lazy;      // seg = árvore segmentada, lazy = incrementos pendentes

    // construtor
    segtree_inc(int n) {
        this->n = n;                // guarda tamanho
        seg.assign(4 * n, 0);       // aloca a árvore com valores iniciais 0
        lazy.assign(4 * n, 0);      // lazy começa sem incrementos pendentes
    }

    // constrói a árvore a partir do vetor "a"
    void build(vector<int> &a, int idx, int l, int r) {
        if (l == r) {               // caso base: folha
            seg[idx] = a[l];        // atribui valor diretamente da array
            return;
        }

        int mid = (l + r) / 2;      // calcula o meio do intervalo

        build(a, 2 * idx, l, mid);               // constrói filho esquerdo [l, mid]
        build(a, 2 * idx + 1, mid + 1, r);       // constrói filho direito [mid+1, r]

        seg[idx] = seg[2 * idx] + seg[2 * idx + 1]; // soma dos filhos
    }

    // aplica lazy pendente no nó e repassa para os filhos
    void push(int idx, int l, int r) {
        if (lazy[idx] != 0) {                       // existe incremento pendente?
            seg[idx] += lazy[idx] * (r - l + 1);    // aplica o incremento proporcional ao tamanho do intervalo

            if (l != r) {                           // se não for folha, propaga aos filhos
                lazy[2 * idx]     += lazy[idx];     // adiciona incremento ao filho esquerdo
                lazy[2 * idx + 1] += lazy[idx];     // adiciona incremento ao filho direito
            }

            lazy[idx] = 0;                          // limpa o lazy atual
        }
    }

    // update em um intervalo [ql, qr] somando val
    void update_range(int idx, int l, int r, int ql, int qr, int val) {
        push(idx, l, r);                            // garante que o nó está atualizado

        if (qr < l || ql > r) return;               // intervalo completamente fora

        if (ql <= l && r <= qr) {                   // intervalo completamente dentro
            lazy[idx] += val;                       // acumula incremento pendente
            push(idx, l, r);                        // aplica imediatamente
            return;
        }

        int mid = (l + r) / 2;                      // divide intervalo

        update_range(2 * idx, l, mid, ql, qr, val);         // atualiza lado esquerdo
        update_range(2 * idx + 1, mid + 1, r, ql, qr, val); // atualiza lado direito

        seg[idx] = seg[2 * idx] + seg[2 * idx + 1]; // recalcula com base nos filhos
    }

    // consulta a soma no intervalo [ql, qr]
    int query(int idx, int l, int r, int ql, int qr) {
        push(idx, l, r);                            // aplica lazy se existir

        if (qr < l || ql > r) return 0;             // totalmente fora
        if (ql <= l && r <= qr) return seg[idx];    // totalmente dentro

        int mid = (l + r) / 2;                      // divide intervalo

        return query(2 * idx, l, mid, ql, qr) +             // soma da esquerda
               query(2 * idx + 1, mid + 1, r, ql, qr);      // soma da direita
    }

    // funções de interface para facilitar o uso
    void build(vector<int> &a) { build(a, 1, 0, n - 1); }
    void update_range(int l, int r, int val) { update_range(1, 0, n - 1, l, r, val); }
    int query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }

};