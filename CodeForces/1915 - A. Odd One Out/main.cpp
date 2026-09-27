#include <bits/stdc++.h>
using namespace std;
#define enl '\n'
using ll = long long;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  while (n--)
  {
    ll num = 0;
    for (int i = 0; i < 3; i++)
    {
      ll x;
      cin >> x;
      num ^= x;
    }
    cout << num << endl;
  }
}