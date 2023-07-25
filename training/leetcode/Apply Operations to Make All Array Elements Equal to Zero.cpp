#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkArray(vector<int> &nums, int k)
    {
        int total = nums.size() cur = 0;
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            q.push(nums[i]);
            nums[i] -= cur;
            if (nums[i] < 0)
                return false;
            cur += nums[i];
        }
        for(int i=k; i<total; i++){
            int v = q.front();
            cur -= v;
            q.pop();
            nums[i] -= cur;
            if (nums[i] < 0)
                return false;
            cur += nums[i];
            q.push(nums[i]);
        }
        return true;
    }
};