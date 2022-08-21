#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries)
    {
        int len = nums.size(), total = removeQueries.size();
        vector<long long> res;
        map<long long, long long> m;
        long long s = accumulate(nums.begin(), nums.end(), 0LL);
        m[len - 1] = s;
        for (auto query : removeQueries)
        {
            long long k = m.upper_bound(query)->first;
            long long s = m[k];
            s -= nums[query];
        }

        return res;
    }
};