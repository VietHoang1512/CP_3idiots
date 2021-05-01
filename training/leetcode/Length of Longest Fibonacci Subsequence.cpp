#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 1005;
class Solution
{
public:
    int dp[mx][mx];
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int total = arr.size();
        int res = 0;
        unordered_map<int, int> m;
        // for (int i = 1; i < total; i++)
        // {
        //     dp[0][i] = 2;
        // }
        for (int i = 0; i < total; i++)
        {
            m[arr[i]] = i;
        }
        // cout << 0 << " -> " << m[0] << endl;

        // for (auto x : arr)
        // {
        //     cout << x << " -> " << m[x] << endl;
        // }
        for (int i = 0; i < total - 1; i++)
        {
            for (int j = i + 1; j < total; j++)
            {
                if (arr[j] >= 2 * arr[i])
                    break;
                int tmp = arr[j] - arr[i];
                if (!m.count(tmp))
                    continue;
                dp[i][j] = dp[m[tmp]][i] + 1;
                res = max(res, dp[i][j]);
            }
        }

        // for (int i = 0; i < total; i++)
        // {
        //     for (int j = 0; j < total; j++)
        //     {

        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (res > 0)
            return res + 2;
        return 0;
    }
};