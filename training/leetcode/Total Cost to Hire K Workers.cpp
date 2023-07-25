#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1, pq2;
        int total = costs.size();
        for (int i = 0; i < total; i++)
        {
            pq1.push({costs[i], i});
            pq2.push({costs[total - 1 - i], total - 1 - i});
        }
        long long res = 0;
        int l = k, r = total - k - 1;
        vector<int> dp(total, 0);
        while (k--)
        {
        tryAgain:
            int chosen = 1;
            if (pq1.top().first < pq2.top().first)
            {
                if (dp[pq1.top().second])
                {

                    pq1.pop();
                    if (l < total)
                    {
                        pq1.push({costs[l], l});
                        l++;
                    }
                    goto tryAgain;
                }
                res += (long long)pq1.top().first;
                dp[pq1.top().second]++;
                pq1.pop();
                if (l < total)
                {
                    pq1.push({costs[l], l});
                    l++;
                }
            }
            else if (pq1.top().first > pq2.top().first)
            {
                if (dp[pq2.top().second])
                {

                    pq2.pop();
                    if (r >= 0)
                    {
                        pq2.push({costs[r], r});
                        r--;
                    }
                    goto tryAgain;
                }
                res += (long long)pq2.top().first;
                dp[pq2.top().second]++ pq2.pop();
                if (r >= 0)
                {
                    pq2.push({costs[r], r});
                    r--;
                }
            }
            else
            {
                if (pq1.top().second == pq2.top().second)
                {
                    res += (long long)pq1.top().first;
                    dp[pq1.top().second]++;
                    pq2.pop();
                    if (r >= 0)
                    {
                        pq2.push({costs[r], r});
                        r--;
                    }
                    pq1.pop();
                    if (l < total)
                    {
                        pq1.push({costs[l], l});
                        l++;
                    }
                }
                else if (pq1.top().second < pq2.top().second)
                {
                    res += (long long)pq1.top().first;
                    dp[pq1.top().second]++;
                    pq1.pop();
                    if (l < total)
                    {
                        pq1.push({costs[l], l});
                        l++;
                    }
                }
                else
                {
                    res += (long long)pq1.top().first;
                    dp[pq2.top().second]++;
                    pq2.pop();
                    if (r >= 0)
                    {
                        pq2.push({costs[r], r});
                        r--;
                    }
                }
            }
        }
        return res;
    }
};