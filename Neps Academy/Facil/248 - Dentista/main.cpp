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
bool compare(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.se < b.se)
        return true;
    return false;
}
int main()
{
    FAST_IO;

    ll n;
    cin >> n;

    vector<pair<ll, ll>> vt;

    FOR(i, 0, n)
    {
        ll a, b;
        cin >> a >> b;
        vt.push_back(mp(a, b));
    }
    sort(all(vt), compare);

    ll comeca = 0;
    ll termina = 0;
    ll count = 1;
    comeca = vt[0].fi;
    termina = vt[0].se;
    FOR(i, 1, n)
    {
        if (vt[i].fi >= termina)
        {
            termina = vt[i].se;
            count++;
        }
    }
    cout << count << endl;
}