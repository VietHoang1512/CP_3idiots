class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp = matrix;
        int val[200000], res = 0;
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = matrix[i][j] * (dp[i - 1][j] + 1);
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        for (int i = 0; i < m; i++)
        {
            memset(val, 0, sizeof(val));
            vector<int> idx_v;
            set<int> idx_s;
            for (int j = 0; j < n; j++)
            {
                int tmp = dp[i][j];
                val[tmp]++;
                idx_s.insert(tmp);
            }
            for (auto x : idx_s)
            {
                idx_v.push_back(x);
            }
            sort(idx_v.rbegin(), idx_v.rend());
            int tmp = 0;
            for (auto j : idx_v)
            {
                tmp += val[j];
                res = max(res, tmp * j);
            }
        }
        return res;
    }
};