/**************************************************/
//        1104 - Troca de Cartas
// https://judge.beecrowd.com/pt/problems/view/1104
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    while (cin >> a >> b, a)
    {
        set<int> s1, s2;
        int temp;

        for (int i = 0; i < a; i++)
        {
            cin >> temp;
            s1.insert(temp);
        }

        for (int i = 0; i < b; i++)
        {
            cin >> temp;
            s2.insert(temp);
        }

        vector<int> diff1, diff2;

        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(diff1));

        set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(diff2));

        cout << min(diff1.size(), diff2.size()) << endl;
    }
    return 0;
}