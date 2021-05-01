#include <bits/stdc++.h>
using namespace std;

int main()
{
}

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int total = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        cout << "\n***************\n";
        // for (auto x : intervals)
        // {
        //     cout << x[0] << "-" << x[1] << " ";
        // }
        int l = intervals[0][0], r = intervals[0][1];
        vector<vector<int>> res;

        for (int i = 1; i < total; i++)
        {
            if (r < intervals[i][0])
            {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else
            {
                r = max(r, intervals[i][1]);
            }
        }
        res.push_back({l, r});
        return res;
    }
};