#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

struct Balde
{
    ll min_val;
    ll max_val;
    ll res;
};

struct segTree
{
    ll n;
    vector<Balde> seg;
    // Definimos o neutro completo
    const Balde NEUTRO = {LLONG_MAX, LLONG_MIN, -1};

    segTree(ll n)
    {
        this->n = n;
        seg.resize(4 * n, NEUTRO);
    }

    Balde combine(Balde a, Balde b)
    {
        // CORREÇÃO 1: Verificar se B é o neutro, não A de novo
        if (a.min_val == LLONG_MAX) return b;
        if (b.min_val == LLONG_MAX) return a;

        Balde ans;
        ans.min_val = min(a.min_val, b.min_val);
        ans.max_val = max(a.max_val, b.max_val);

        // A lógica da resposta: melhor da esq, melhor da dir, ou cruzamento entre eles
        ans.res = max({a.res, b.res, b.max_val - a.min_val, a.max_val - b.min_val});
        return ans;
    }

    void build(vector<ll> &a, ll idx, ll l, ll r)
    {
        if (l == r)
        {
            // CORREÇÃO 2: a[l-1] porque o vetor 'a' é 0-based e 'l' é 1-based
            seg[idx] = {a[l-1], a[l-1], -1};
            return;
        }

        ll mid = (l + r) / 2;
        build(a, 2 * idx, l, mid);
        build(a, 2 * idx + 1, mid + 1, r);

        seg[idx] = combine(seg[2 * idx], seg[2 * idx + 1]);
    }

    Balde query(ll idx, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
        {
            // CORREÇÃO 3: Retornar NEUTRO para garantir que o .res seja -1 e não lixo
            return NEUTRO;
        }

        if (ql <= l && r <= qr)
        {
            return seg[idx];
        }

        ll mid = (l + r) / 2;

        Balde left = query(2 * idx, l, mid, ql, qr);
        Balde right = query(2 * idx + 1, mid + 1, r, ql, qr);

        return combine(left, right);
    }

    void update(ll idx, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            // O problema diz "adicionar bola", então mantemos o min/max atualizados
            seg[idx].min_val = min(seg[idx].min_val, val);
            seg[idx].max_val = max(seg[idx].max_val, val);
            seg[idx].res = -1; // Um único balde nunca tem diferença válida entre baldes distintos
            return;
        }

        ll mid = (l + r) / 2;
        if (pos <= mid)
        {
            update(2 * idx, l, mid, pos, val);
        }
        else
        {
            update(2 * idx + 1, mid + 1, r, pos, val);
        }

        seg[idx] = combine(seg[2 * idx], seg[2 * idx + 1]);
    }

    void build(vector<ll> &a) { build(a, 1, 1, n); }
    Balde query(ll ql, ll qr) { return query(1, 1, n, ql, qr); }
    void update(ll pos, ll val) { update(1, 1, n, pos, val); }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    if (!(cin >> n >> m)) return 0; // Boa prática em CP
    
    segTree arvore(n);
    vector<ll> a;
    
    // Reserva memória pra evitar realocações (opcional, mas bom)
    a.reserve(n); 

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    
    arvore.build(a);
    
    for (ll i = 0; i < m; i++)
    {
        ll tipo;
        cin >> tipo;
        if (tipo == 1)
        {
            ll pos, val;
            cin >> pos >> val; 
            arvore.update(pos, val);
        }
        else
        {
            ll ql, qr;
            cin >> ql >> qr;
            cout << arvore.query(ql, qr).res << endl;
        }
    }
    return 0;
}