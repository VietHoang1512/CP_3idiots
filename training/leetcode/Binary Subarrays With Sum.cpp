#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        int total = A.size(), res = 0;
        vector<map<int, int>> dp(total);
        dp[0][A[0]]++;
        // dp[0][0]++;
        // cout << 0 << ": " << A[0] << "(" << dp[0][A[0]] << ")\n";
        res += dp[0][S];
        for (int i = 1; i < total; i++)
        {
            // cout << i << ": ";
            dp[i][A[i]] = 1;

            for (auto x : dp[i - 1])
            {
                // dp[i][A[i]]++;
                dp[i][x.first + A[i]] += dp[i - 1][x.first];
                // dp[i][x.first] = dp[i - 1][x.first];

                // cout << x.first + A[i] << "(" << dp[i][x.first + A[i]] << ") ";
            }
            res += dp[i][S];
            // for (auto x : dp[i])
            // {
            //     cout << x.first << "(" << dp[i][x.second] << ") ";
            // }
            // cout << endl;
        }
        return res;
    }
};