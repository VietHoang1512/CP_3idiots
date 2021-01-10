#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5;

int n;
int res[mx], A[mx];
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    memset(res, -1, sizeof(res));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
        v.push_back({A[i], i});
    }
    sort(v.begin(), v.end(), cmp);
    int max_id = v[0].second;

    for (int i = 1; i < n; i++)
    {
        int cur_id = v[i].second;

        if (cur_id < max_id)
            res[cur_id] = max_id - i - 1;
        max_id = max(max_id, cur_id);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }

    // int cur_min = A[n], cur_min_id = n;
    // // res[n] = -1;
    // for (int i = n - 1; i > 0; i--)
    // {
    //     if (A[i] > cur_min)
    //     {

    //         res[i] = cur_min_id - i - 1;
    //     }
    //     else if (A[i] < cur_min)
    //     {
    //         res[i] = -1;
    //         cur_min = A[i];
    //         cur_min_id = i;
    //     }
    // }
}