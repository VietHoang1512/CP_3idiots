class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int dp[1005][1005];
        vector<int> val;
        memset(dp, -1, sizeof(dp));
        int m = matrix.size(), n = matrix[0].size();
        dp[0][0] = matrix[0][0];
        val.push_back(dp[0][0]);
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] ^ matrix[i][0];
            val.push_back(dp[i][0]);
        }

        for (int i = 1; i < n; i++)
        {
            dp[0][i] = dp[0][i - 1] ^ matrix[0][i];
            val.push_back(dp[0][i]);
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1] ^ matrix[i][j];
                // cout << dp[i - 1][j] << dp[i][j - 1] << dp[i - 1][j -1] << matrix[i][j] << endl;
                val.push_back(dp[i][j]);
            }
        }
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        sort(val.rbegin(), val.rend());
        return val[k - 1];
    }
};