#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> t;
int ti, res, max_t = 0;

bool cmp(int a, int b)
{
    return (a > b);
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> ti;
        max_t = max(max_t, ti);
        t.push_back(ti);
    }
    res = 0;
    sort(t.begin(), t.end(), cmp);
    for (int i = 0; i < t.size(); i++)
    {
        res = max(res, i + 1 + t[i]);
    }
    cout << res+1;
}