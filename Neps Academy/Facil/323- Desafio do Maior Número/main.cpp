#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  ll maior = INT_MIN;
  while (cin >> n, n != 0) {
    if (n > maior) {
      maior = n;
    }
  }
  cout << maior << endl;
  return 0;
}