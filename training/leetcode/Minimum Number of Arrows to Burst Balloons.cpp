#include <bits/stdc++.h>
using namespace std;

int main()
{
}

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] <= b[1];
    return a[0] < b[0];
}
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int total = points.size();
        sort(points.begin(), points.end(), cmp);
        cout << "\n***************\n";
        // for (auto x : points)
        // {
        //     cout << x[0] << "-" << x[1] << " ";
        // }
        int cur = 0, l = points[0][0], r = points[0][1], res = 1;
        for (int i = 1; i < total; i++)
        {
            if (r < points[i][0])
            {
                res++;
                l = points[i][0];
                r = points[i][1];
            }
            else
            {
                l = max(l, points[i][0]);
                r = min(r, points[i][1]);
            }
        }
        return res;
    }
};