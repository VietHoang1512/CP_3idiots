#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int res = INT_MAX;
    void TRY(int i, vector<int> &cookies, vector<int> &dp, int n, int k)
    {
        if (i == n)
        {
            int tmp = 0;
            for (int j = 0; j < k; j++)
            {
                tmp = max(tmp, dp[j]);
                // cout <<dp[j]<<" ";
            }
            cout << endl;
        
            res = min(res, tmp);
            return;
        }
        for (int j = 0; j < k; j++)
        {

            dp[j]+=cookies[i];
            TRY(i+1, cookies, dp, k);
            dp[j]-=cookies[i];

        }
    }

    int distributeCookies(vector<int> &cookies, int k)
    {
        int n = cookies.size();
        vector<int> dp(k);
        TRY(0, cookies, dp, n, k);
        // cout <<"***\n";
        return res;
    }

};
