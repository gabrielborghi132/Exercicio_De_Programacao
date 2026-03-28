#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int main() {
  ll n;
  string s;
  cin >> n;
  vector<ll> vt(10, 0);
  for (ll i = 0; i < n; i++) {
    cin >> s;
    for (auto &x : s) {
      vt[x - '0']++;
    }
  }
  for (ll i = 0; i < 10; i++) {
    cout << i << " - " << vt[i] << endl;
  }
}