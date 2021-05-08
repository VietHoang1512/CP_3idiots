#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res;
        // for (int i = 0; i < k; i++)
        // {
        //     res.push_back(nums[i]);
        // }

        for (int i = 0; i < n; i++)
        {
            for (auto x : res)
                cout << x << " ";
            cout << endl;
            while (res.size() && (res.size() + (n - i) >= k) && (res.back() > nums[i]))
            {
                res.pop_back();
            }
            if (res.size() < k)
                res.push_back(nums[i]);
        }
        for (auto x : res)
            cout << x << " ";
        return res;
    }
};