#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        int total = intervals.size();
        vector<int> keep(total, 1);
        for (int i = 0; i < total - 1; i++)
        {
            for (int j = i + 1; j < total; j++)
            {

                if ((intervals[i][0] <= intervals[j][0]) && (intervals[i][1] >= intervals[j][1]))
                {
                    keep[j] = 0;
                }
                else if ((intervals[j][0] <= intervals[i][0]) && (intervals[j][1] >= intervals[i][1]))
                {
                    keep[i] = 0;
                }
            }
        }
        return accumulate(keep.begin(), keep.end(), 0);
    }
};