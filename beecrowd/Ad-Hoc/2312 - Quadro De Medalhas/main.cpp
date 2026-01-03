/**************************************************/
//         2312 - Quadro De Medalhas
// https://judge.beecrowd.com/pt/problems/view/2312*/
/**************************************************/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool cmp(const tuple<int, int, int, string> &A,
         const tuple<int, int, int, string> &B)
{
    auto [o1, p1, b1, n1] = A;
    auto [o2, p2, b2, n2] = B;

    if (o1 != o2)
        return o1 > o2;
    if (p1 != p2)
        return p1 > p2;
    if (b1 != b2)
        return b1 > b2;
    return n1 < n2;
}
int main()
{
    vector<tuple<int, int, int, string>> vt;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int o, p, b;
        string nome;
        cin >> nome >> o >> p >> b;
        vt.push_back(make_tuple(o, p, b, nome));
    }
    sort(vt.begin(), vt.end(), cmp);

    for (auto [o, p, b, nome] : vt)
    {
        cout << nome << " " << o << " " << p << " " << b << endl;
    }
}
