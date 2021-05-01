#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    // int dp[shift + 3500][35];

    int lastStoneWeightII(vector<int> &stones)
    {

        sort(stones.begin(), stones.end());

        int total = stones.size();
        vector<map<int, int>> dp(total);
        dp[0][stones[0]] = 1;
        dp[0][-stones[0]] = 1;

        int res = accumulate(stones.begin(), stones.end(), 0);

        for (int i = 1; i < total; i++)
        {
            for (auto x : dp[i - 1])
            {

                dp[i][x.first - stones[i]] = 1;
                dp[i][x.first + stones[i]] = 1;
            }
        }
        for (auto x : dp[total - 1])
        {
            if (x.first >= 0)
                res = min(res, x.first);
        }
        return res;
        // for()
    }
};

// const int shift = 5000;
// class Solution
// {
// public:
//     int dp[shift + 3500][35];

//     int lastStoneWeightII(vector<int> &stones)
//     {
//         sort(stones.begin(), stones.end());

//         int total = stones.size();

//         dp[shift + stones[0]][0] = 1;
//         dp[shift - stones[0]][0] = 1;
// int res = accumulate(stones.begin(), stones.end(), 0);

//         for (int i = 1; i < total; i++)
//         {
//             for (int j = 0; j <= 3200 + shift; j++)
//             {
//                 if (dp[j][i - 1])
//                 {
//                     dp[j + stones[i]][i] = 1;
//                     dp[j - stones[i]][i] = 1;
//                 }
//             }
//         }
//         for (int i = 0; i <= 3200 + shift; i++)
//         {
//             if ((dp[i][total - 1] > 0) && (i - shift >= 0))
//                 res = min(res, i - shift);
//         }
//         return res;
//     }
// };