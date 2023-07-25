#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<long long> cum_sum(n+1, 0);
        long long s = 0;
        cout << "\ncum_sum: ";
        for (int i = 0; i < n; i++)
        {
            s += nums[i];
            cum_sum[i] = s;
            cout << s << " ";
        }
        cum_sum[n] = 5e9;
        vector<int> res(m, 0);

        for (int i = 0; i < m; i++)
        {
            long long cur = queries[i];
            res[i] = (upper_bound(cum_sum.begin(), cum_sum.end(), cur ) - cum_sum.begin());
            // if (cum_sum[res[i]]>cur)
            //         res[i]--;
            // res[i] = max(res[i], 0);
        }
        cout << "\n***\n";
        return res;
    }
};