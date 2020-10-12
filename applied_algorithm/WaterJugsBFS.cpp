#include <bits/stdc++.h>

using namespace std;
long long a, b, c;
const long long mx = 10000;
long long res[mx][mx];
bool is_res[mx][mx];
pair<long long, long long> cur(0, 0);
queue<pair<long long, long long>> q;

void push(long long x, long long y)
{
    if (res[x][y] > 0)
        return;
    res[x][y] = res[cur.first][cur.second] + 1;
    q.push(pair<long long, long long>(x, y));
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    res[0][0] = 1;
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.first == c || cur.second == c)
        {
            cout << res[cur.first][cur.second] - 1;
            return 0;
        }
        push(0, cur.second);
        push(cur.first, 0);
        push(a, cur.second);
        push(cur.first, b);
        if (cur.second + cur.first > b)
        {
            push(cur.first - b + cur.second, b);
        }
        else
            push(0, cur.second + cur.first);
        if (cur.first + cur.second > a)
        {
            push(a, cur.second - a + cur.first);
        }
        else
            push(cur.second + cur.first, 0);
    }
    // cout << -1;
}