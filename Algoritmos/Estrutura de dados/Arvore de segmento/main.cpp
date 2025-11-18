#include <bits/stdc++.h>
using namespace std;

typedef struct segtree
{
    int n; // Folhas
    vector<int> seg;
    segtree(int n)
    {
        this->n = n;
        seg.assign(4 * n, INT_MAX);
    }
    // método que constrói a arvore dado um vetor "a"
    void build(vector<int> &a, int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = a[l]; // se for folha, atribui diretamente do vetor
            return;
        }

        int mid = (l + r) / 2;

        build(a, 2 * idx, l, mid);         // constrói o filho esquerdo [2 * idx (nó raiz)]
        build(a, 2 * idx + 1, mid + 1, r); // constrói o filho direito [2 * idx + 1]

        // na volta da recursão, utiliza os valores de esquerda e direita calculados
        seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
        // seg[idx] = seg[2 * idx] + seg[2 * idx + 1]; // segtree de somas
    }
    int query(int idx, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return INT_MAX; // completamente fora de escopo
        if (ql <= l && r <= qr)
            return seg[idx]; // totalmente dentro

        // parcialmente dentro
        int mid = (l + r) / 2;

        return min(
            query(2 * idx, l, mid, ql, qr),
            query(2 * idx + 1, mid + 1, r, ql, qr));
        /*
        return
            query(2 * idx, l, mid, ql, qr) +        // segtree de somas
            query(2 * idx + 1, mid + 1, r, ql, qr);
        */
    }
    void update(int idx, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            seg[idx] = val; // se for folha, trocar o valor
            return;
        }

        int mid = (l + r) / 2;
        // faço apenas o caminho que a troca daquele valor pode alterar algo nos intervalos
        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);

        // refaço os calculos caso a troca de valor tenha interferido
        seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
        // seg[idx] = seg[2 * idx] + seg[2 * idx + 1]; // segtree de somas
    }

    // interfaces para facilitar o uso dos métodos
    void build(vector<int> &a) { build(a, 1, 0, n - 1); }
    int query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
    void update(int pos, int val) { update(1, 0, n - 1, pos, val); }

} segtree;
int main()
{
    vector<int> a = {1, 4, 3, 2, 9, 1, 7, 8};
    int n = a.size();

    segtree st(n);
    st.build(a);

    cout << st.query(1, 4) << endl;

    for (int i = 1; i < (n * 2 - 1); i++)
    {
        cout << st.seg[i] << ", ";
    }
    cout << endl;
    return 0;
}