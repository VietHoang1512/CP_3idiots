#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
    {
        int total = nums.size();
        vector<vector<int>> cnt(total + 5, vector<int>(105));
        cnt[1][nums[0]]++;
        for (int i = 1; i <= total; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                cnt[i + 1][j] = cnt[i][j] + ((i < total) && (nums[i] == j));
            }
        }
        vector<int> res;
        for (auto q : queries)
        {
            int l = q[0], r = q[1] + 1;
            set<int> s;
            vector<int> v;
            for (int j = 0; j <= 100; j++)
            {
                if (cnt[r][j] - cnt[l][j])
                    s.insert(j);
            }

            // v.insert(v.end(), s.begin(), s.end());
            // // for (auto c : v)
            // // {
            // //     cout << c << " ";
            // // }
            // // cout << endl;
            // if (v.size() == 1)
            // {
            //     res.push_back(-1);
            //     continue;
            // }
            // int tmp = INT_MAX / 2;
            // for (int i = 1; i < v.size(); i++)
            // {
            //     tmp = min(tmp, v[i] - v[i - 1]);
            // }
            if (s.size() == 1)
            {
                res.push_back(-1);
                continue;
            }
            int prev = -INT_MAX / 3;
            int tmp = INT_MAX / 2;
            for (auto c : s)
            {
                tmp = min(tmp, c - prev);
                prev = c;
            }
            res.push_back(tmp);
        }
        return res;
    }
};