#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maximizeGreatness(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        cout << "\n***\n";
        int cur = nums[0], cnt = 0;
        vector<int> v;
        for (auto n : nums)
        {
            if (n == cur)
            {
                cnt++;
            }
            else
            {
                v.push_back(cnt);
                cur = n;
                cnt = 1;
            }
        }
        v.push_back(cnt);
        int len = v.size();
        if (len == 1)
            return 0;
        int res = 0, left = 0;
        for (int i = 0; i < len - 1; i++)
        {
            if (v[i + 1] > v[i])
            {
                res += v[i];
                res += min(left, v[i+1]-v[i]);
                left = max(0, left-v[i+1]+v[i]);
            }
            else
            {
                res += v[i + 1];
                left += (v[i]-v[i+1]);
            }
        }
        return res;
    }
};