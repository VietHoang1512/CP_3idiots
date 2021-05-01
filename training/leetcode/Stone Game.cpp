#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 505;
class Solution
{
public:
    int dp[mx][mx];
    bool stoneGame(vector<int> &piles)
    {
        int total = piles.size();
        for (int i = 0; i < total; i++)
        {
            dp[i][i] = piles[i];
        }
        for (int i = 0; i < total - 1; i++)
        {
            for (int j = 1; j < total; j++)
            {
                int tmp = (total + i + j) % 2 ? 1 : -1;
                dp[i][j] = max(dp[i + 1][j] + piles[i] * tmp, dp[i][j - 1] + piles[j] * tmp);
            }
        }
        return dp[0][total - 1]>0;
    }
};