#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<int> fita(n);
    vector<int> esq(n), dir(n), resp(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        fita[i] = x;
    }
    ll posicao_do_ultimo_zero = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (fita[i] == 0)
            posicao_do_ultimo_zero = i;
        if (posicao_do_ultimo_zero == INT_MAX)
            esq[i] = INT_MAX;
        else
        {
            ll x = i - posicao_do_ultimo_zero;
            if (x >= 9)
                esq[i] = 9;
            else
                esq[i] = x;
        }
    }
    posicao_do_ultimo_zero = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (fita[i] == 0)
            posicao_do_ultimo_zero = i;
        if (posicao_do_ultimo_zero == INT_MAX)
            dir[i] = INT_MAX;
        else
        {
            ll x = posicao_do_ultimo_zero - i;
            if (x >= 9)
                dir[i] = 9;
            else
                dir[i] = x;
        }
    }
    for (int i = 0; i < n; i++)
    {
        resp[i] = min(dir[i], esq[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << resp[i] << " ";
    }
    cout << resp[n - 1] << endl;
}