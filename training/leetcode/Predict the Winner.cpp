#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 25;
class Solution
{
public:
    int dp[mx][mx];
    bool PredictTheWinner(vector<int> &nums)
    {
        int total = nums.size();
        for (int i = 0; i < total; i++)
        {
            int tmp = total % 2 ? 1 : -1;

            dp[i][i] = tmp * nums[i];
        }
        for (int k = 1; k <= total - 1; k++)
        {
            for (int i = 0; i < total - k; i++)
            {
                int j = i + k;
                int tmp = (total + i + j) % 2;
                if (tmp)
                    dp[i][j] = max(dp[i + 1][j] + nums[i], dp[i][j - 1] + nums[j]);
                else
                    dp[i][j] = min(dp[i + 1][j] - nums[i], dp[i][j - 1] - nums[j]);
            }
        }
        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][total - 1] >= 0;
    }
};