#include <bits/stdc++.h>
using namespace std;

// ── Tipos ────────────────────────────────────────────
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

// ── I/O rápido ───────────────────────────────────────
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl '\n'

// ── Loops ────────────────────────────────────────────
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define each(x, v) for (auto &x : (v))

// ── Utilidades ───────────────────────────────────────
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

// ── Debug (desative antes de submeter!) ──────────────
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << '\n'
#else
#define dbg(x)
#endif

// ── Constantes ───────────────────────────────────────
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main()
{
    FAST_IO;
    ll n, m;
    cin >> n >> m;

    ll posicao_atual = 1;
    ll tempo_total = 0;

    for (int i = 0; i < m; i++)
    {
        ll destino;
        cin >> destino;

        if (destino >= posicao_atual)
        {
            tempo_total += (destino - posicao_atual);
        }
        else
        {
            tempo_total += (n - posicao_atual) + destino;
        }

        posicao_atual = destino;
    }

    cout << tempo_total << endl;

    return 0;
}