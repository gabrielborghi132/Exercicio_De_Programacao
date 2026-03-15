#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin >> n;
  for (ll i = n + 1; i < n + 10; i++) {
    cout << i << " ";
  }
  cout << n + 10 << endl;
  return 0;
}