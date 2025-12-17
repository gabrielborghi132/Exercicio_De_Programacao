/**************************************************/
//         1547 - Adivinha
//https://judge.beecrowd.com/pt/problems/view/1547*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        int qt, s;
        cin >> qt >> s;

        int melhorPos = 1;
        int melhorDif = INT_MAX;

        for (int i = 1; i <= qt; i++) {
            int x;
            cin >> x;
            int dif = abs(x - s);

            if (dif < melhorDif) {
                melhorDif = dif;
                melhorPos = i;
            }
        }

        cout << melhorPos << "\n";
    }

    return 0;
}
