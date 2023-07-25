#include <bits/stdc++.h>
using namespace std;

long long main()
{
}

class Solution
{
public:
    long long findScore(vector<int> &NUMS)
    {
        vector<long long> nums(NUMS.begin(), NUMS.end()); 
        priority_queue<pair<long long, int>> PQ;
        
        long long len = nums.size(), marked = 0, res=0;
        vector<long long> v(len, 0);

        for (int i = 0; i < len; i++)
        {
            PQ.push({-nums[i], -i});
        }
        while (marked < len)
        {
            while (PQ.size() && v[-PQ.top().second])
            {
                PQ.pop();
            }
            long long cur=-PQ.top().first, ind=-PQ.top().second;
            // cout << cur << " ";
            v[ind] = 1;
            marked++;
            if (ind > 0)
            {
                if (!v[ind - 1])
                {
                    v[ind - 1] = 1;
                    marked++;
                    // cout << nums[ind - 1]<<" ";
                }
            }
            if (ind < len - 1)
            {
                if (!v[ind + 1])
                {
                    v[ind + 1] = 1;
                    marked++;
                    // cout << nums[ind + 1]<<" ";

                }
            }
            res+=cur;
            // cout << "\n";
        }
        // cout << "\n\n";
        return res;
    }
};