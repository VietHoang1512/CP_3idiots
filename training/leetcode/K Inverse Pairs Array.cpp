#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        int mod = 1000000007;
        if (n == 1)
            return k == 0;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)), S(n + 1, vector<int>(k + 1, 0));
        dp[2][1] = 1;
        dp[2][0] = 1 S[2][1] = 1;
        S[2][0] = 1;
        for (int i = 3; i <= n; i++)
        {
            for (int j = 0; j <= min(1000, i * (i - 1) / 2); j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 1;
                    S[i][j] = 1;
                    continue;
                }
                else if (j == 1)
                {
                    dp[i][j] = i - 1;
                    S[i][j] = i;
                    continue
                }
                // S[i][j] = (S[i][j] + S[i - 1][j - 1]) % mod;
                for(int l=0;l<=j;l++)
                {
                    dp[i][j] = 
                }
            }
        }
    }
};