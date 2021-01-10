#include <bits/stdc++.h>
using namespace std;

int n_test;
int L, C, p;
int cnt[2000][2000];
// pair<int, int> p;
int res;
vector<pair<int, int>> radar1, radar2;
int main()

{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n_test;
    while (n_test--)
    {

        memset(cnt, 0, sizeof(cnt));
        radar1.clear(), radar2.clear();
        cin >> L >> C;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> p;
                if (p)
                    radar1.push_back({i, j});
            }
        }

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> p;
                if (p)
                    radar2.push_back({i, j});
            }
        }

        for (pair<int, int> p1 : radar1)
        {
            for (pair<int, int> p2 : radar2)
            {
                cnt[p1.first - p2.first + 1000][p1.second - p2.second + 1000]++;
            }
        }
        res = 0;
        for (int i = 0; i < 2000; i++)
        {
            for (int j = 0; j < 2000; j++)
                res = max(res, cnt[i][j]);
        }
        cout << res << endl;
    }
}