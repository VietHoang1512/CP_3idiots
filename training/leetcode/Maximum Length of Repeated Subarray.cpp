#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    if ((i > 0) && (j > 0))
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    else
                        dp[i][j] = 1;
                    res = max(res, dp[i][j]);
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return res;
    }
};
