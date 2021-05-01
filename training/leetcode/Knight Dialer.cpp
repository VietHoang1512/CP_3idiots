#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mod = 1e9 + 7;
class Solution
{
public:
    int dp[10][5005];
    int knightDialer(int n)
    {
        if (n == 1)
            return 10;
        if (n == 2)
            return 20;
        vector<int> v2{04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94};
        for (auto x : v2)
        {
            dp[x % 10][2] += 1;
        }
        for (int i = 3; i <= n; i++)
        {
            for (auto x : v2)
            {
                int src = x / 10, dest = x % 10;
                dp[dest][i] = (dp[dest][i] + dp[src][i - 1]) % mod;
            }
        }
        int res = 0;
        for (int i = 0; i < 10; i++)
        {
            res = (res + dp[i][n]) % mod;
        }
        return res;
    }
};
