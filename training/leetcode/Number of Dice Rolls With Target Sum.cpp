#include <bits/stdc++.h>
using namespace std;

int main()
{
}
const int mod = 1e9 + 7;

class Solution
{
public:
    int dp[35][1005];
    int numRollsToTarget(int d, int f, int target)
    {
        for (int i = 1; i <= f; i++)
        {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= d; i++)
        {

            for (int j = i; j <= i * f; j++)
                for (int k = 1; k <= f; k++)
                {
                    if (j >= k)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
                }
        }
        return dp[d][target];
    }
};