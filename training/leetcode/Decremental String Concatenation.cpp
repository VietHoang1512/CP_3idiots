#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeConcatenatedLength(vector<string> &words)
    {
        int total = words.size(), alpha = 'z' - 'a' + 1;
        vector<vector<vector<int>>> dp(total, vector<vector<int>>(alpha, vector<int>(alpha, -1)));
        int len = words[0].size();
        dp[0][words[0][0] - 'a'][words[0][len - 1] - 'a'] = len;
        int res=len;
        for (int i = 1; i < total; i++)
        {
            len = words[i].size()
            int start = words[i][0]-'a', end = words[i][len-1]-'a';
            for (int j = 0; j < alpha; j++)
            {
                for (int k = 0; k < alpha; k++)
                {
                    if (dp[i-1][j][k] == -1)
                        continue;
                    dp[i][j][end] = max(dp[i][j][end], dp[i-1][j][k]+len-1*(start==k)); 
                    dp[i][start][k] = max(dp[i][start][k], dp[i-1][j][k]+len-1*(end==j)); 
                    res = max(res, dp[i][j][end]);
                    res = max(res, dp[i][start][k]);

                }
            }
        }
        return res;
    }
};