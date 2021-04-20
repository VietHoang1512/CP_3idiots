#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int total = nums.size();

        for (int i = 0; i < pow(2, total); i++)
        {
            vector<int> cur;
            for (int j = 0; j < total; j++)
            {
                if ((i >> j) & 1)
                    cur.push_back(nums[i]);
            }
            res.push_back(cur);
        }

        return res;
    }
    // void TRY(int k, int cnt, int total, vector<int> cur)
    // {
    //     if (cnt == total)
    //     {
    //         res.push_back(cur);
    //     }
    // }
};