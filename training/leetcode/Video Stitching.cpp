#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int T)
    {
        int total = clips.size();

        vector<int> dp(total + 1, 0);
        for (int i = 1; i <= total; i++)
        {

            for (auto x : clips)
            {
                if (x[0] <= dp[i - 1])
                {
                    dp[i] = max(dp[i], x[1]);
                    if (dp[i] >= T)
                        return i;
                }
            }
        }
        if (!T)
            return 0;
        return -1;
    }
};
