#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int res = INT_MAX;

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int total = triangle.size();
        vector<vector<int>> dp(total, vector<int>(total, INT_MAX));
        // TRY(triangle, 0, 0, triangle[0][0]);
        dp[0][0] = triangle[0][0];

        for (int i = 1; i < total; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j < i)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
            }
        }
        for (int i = 0; i < total; i++)
        {
            res = min(res, dp[total - 1][i]);
        }
        return res;
    }
    void TRY(vector<vector<int>> &triangle, int x, int y, int cur_sum)
    {
        // cout << "On " << x << " " << y << ". Values " << triangle[x][y] << endl;
        int total = triangle.size();
        if (x == total - 1)
        {
            // cout << "Current sum " << cur_sum << endl;
            res = min(res, cur_sum);
            return;
        }

        cur_sum += triangle[x + 1][y];
        TRY(triangle, x + 1, y, cur_sum);
        // cout << "Back to " << x << " " << y << ". Values " << triangle[x][y] << endl;
        cur_sum -= triangle[x + 1][y];

        cur_sum += triangle[x + 1][y + 1];
        TRY(triangle, x + 1, y + 1, cur_sum);
        // cout << "Back to " << x << " " << y << ". Values " << triangle[x][y] << endl;
        cur_sum -= triangle[x + 1][y + 1];
    }
};