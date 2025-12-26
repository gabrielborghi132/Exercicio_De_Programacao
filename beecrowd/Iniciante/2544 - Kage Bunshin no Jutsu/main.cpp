/**************************************************/
//        2544 - Kage Bunshin no Jutsu
// https://judge.beecrowd.com/pt/problems/view/2544
/**************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    while (cin >> n) {
        int k = 0;
        while (n > 1) {
            n /= 2;
            k++;
        }
        cout << k << "\n";
    }
    return 0;
}
