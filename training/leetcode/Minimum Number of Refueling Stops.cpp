#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int total = stations.size();
        vector<vector<int>> dp(total + 1, vector<int>(total + 1));
        for (int i = 0; i <= total; i++)
            dp[0][i] = startFuel;
        for (int i = 1; i <= total; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[i - 1] < stations[j][0])
                    break;
                dp[i] = max(dp[i - 1] + stations[j][1], dp[i]);
            }
        }
        for (int i = 0; i <= total; i++)
        {
            if (dp[i] > target)
                return i;
        }
        return -1;
    }
};