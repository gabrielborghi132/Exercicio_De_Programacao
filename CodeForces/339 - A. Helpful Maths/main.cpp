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

    string s;
    getline(cin, s);

    vector<char> vt;

    each(x, s)
    {
        if (x != '+')
            vt.push_back(x);
    }
    sort(all(vt));

    FOR(i, 0, sz(vt) - 1)
    {
        cout << vt[i] << '+';
    }

    cout << vt[sz(vt) - 1] << endl;
}