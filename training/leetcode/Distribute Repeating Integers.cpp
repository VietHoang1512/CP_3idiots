#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canDistribute(vector<int> &nums, vector<int> &quantity)
    {
        map<int, int> cnt;
        int total = quantity.size();
        for (auto num : nums)
        {
            cnt++;
        }
        vector<int> v;
        for (auto p : cnt)
        {
            v.push_back(p.second);
        }
        int len = v.size();
        // sort(quantity.rbegin(), quantity.rend());
        // vector<int> count;
        // for (int i = 0; i < total; i++)
        // {
        //     sort(v.begin(), v.end());
        //     bool satisfied = false;
        //     for (int j = 0; j < len; j++)
        //     {
        //         if (v[j] >= quantity)
        //         {
        //             v[j] -= quantity;
        //             satisfied = true;
        //             break;
        //         }
        //     }
        //     if(!satisfied) return false;
        // }
        // return true;









        
    }
};