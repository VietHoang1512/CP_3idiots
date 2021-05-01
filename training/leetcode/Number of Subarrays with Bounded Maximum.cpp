#include <bits/stdc++.h>
using namespace std;

int main()
{
}

// const int mx = 50005;
class Solution
{
public:
    // int dp[mx];
    int numSubarrayBoundedMax(vector<int> &A, int L, int R)
    {   
        A.push_back(INT_MAX);
        int res = 0, cur_max = 0, cur = 0;
        int total = A.size();
        // if ((A[0] >= L) && (A[0] <= R))
        //     dp[0] = 1;
        // cout << dp[0] << " ";

        for (int i = 0; i < total; i++)
        {
            cur_max = max(cur_max, A[i]);
            if ((cur_max >= L) && (cur_max <= R))
                cur++;
            else
            {
                res += cur * (cur + 1) / 2;
                cur_max = 0;
                cur = 0;
            }

            // if ((A[i] >= L) && (A[i] <= R))
            // dp[i] = 1 + dp[i - 1];
            // res = max(res, dp[i]);
            // cout << dp[i] << " ";
        }
        return res;
    }
};
