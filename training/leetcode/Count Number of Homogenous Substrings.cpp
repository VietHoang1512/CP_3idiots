class Solution
{
public:
    int countHomogenous(string s)
    {
        long long len = s.size();
        long long dp[100005], cum[100005];
        long long mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        cum[0] = 1;
        for (long long i = 1; i < len; i++)
        {
            cum[i] = (cum[i - 1] * (s[i] == s[i - 1]) + 1) % mod;

            dp[i] = (dp[i - 1] + cum[i]) % mod;
            // long long j = i;
            // while (j--)
            // {
            //     if (s[i] == s[j])
            //     {
            //         dp[i]++;
            //     }
            //     else
            //         break;
            //     dp[i] %= mod;
            // }
        }
        return dp[len - 1];
    }
};