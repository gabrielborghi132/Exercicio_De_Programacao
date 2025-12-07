/**************************************************/
//         1548 - Fila do Recreio
//https://judge.beecrowd.com/pt/problems/view/1548*/
//
/**************************************************/



#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        priority_queue<int> pq;
        vector<int> vt;
        int x;
        cin >> x;
        for (int i = 0; i < x; i++)
        {
            int temp;
            cin >> temp;
            pq.push(temp);
            vt.push_back(temp);
        }
        int soma = pq.size();
        int i = 0;
        while (!pq.empty())
        {
            int a = pq.top();
            if (a != vt[i])
            {
                soma--;
            }
            pq.pop();
            i++;
        }
        cout << soma << endl;
    }
}