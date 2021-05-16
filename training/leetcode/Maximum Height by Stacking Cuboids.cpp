#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> dp;
    int total;
    int maxHeight(vector<vector<int>> &cuboids)
    {
        int res = 0;
        total = cuboids.size();
        for (int i = 0; i < total; i++)
        {
            cuboids.push_back({cuboids[i][1], cuboids[i][2], cuboids[i][0]});
        }
        for (int i = 0; i < total; i++)
        {
            cuboids.push_back({cuboids[i][1], cuboids[i][0], cuboids[i][2]});
        }
        for (int i = 0; i < total; i++)
        {
            cuboids.push_back({cuboids[i][2], cuboids[i][0], cuboids[i][1]});
        }
        for (int i = 0; i < total; i++)
        {
            cuboids.push_back({cuboids[i][2], cuboids[i][1], cuboids[i][0]});
        }
        for (int i = 0; i < total; i++)
        {
            cuboids.push_back({cuboids[i][0], cuboids[i][2], cuboids[i][1]});
        }
        total = cuboids.size();
        vector<int> tmp(total, 0);
        dp = tmp;
        for (int i = 0; i < 6 * total; i++)
        {
            res = max(res, DP(i, cuboids));
        }
        return res;
    }
    int DP(int j, vector<vector<int>> &cuboids)
    {
        if (dp[j] > 0)
            return dp[j];
        dp[j] = cuboids[j][2];
        for (int i = 0; i < total; i++)
        {
            if ((((i - j) % (total / 6)) != 0) && (cuboids[i][0] <= cuboids[j][0]) && (cuboids[i][1] <= cuboids[j][1]) && (cuboids[i][2] <= cuboids[j][2]))
            {
                dp[j] = max(dp[j], cuboids[j][2] + DP(i, cuboids));
            }
        }
        return dp[j];
    }
};