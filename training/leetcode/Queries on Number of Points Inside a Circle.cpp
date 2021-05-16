#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
    {
        int total = queries.size();
        vector<int> res(total);
        for (int i = 0; i < total; i++)
        {
            int cnt = 0;
            int x = queries[i][0], y = queries[i][1], r = queries[i][2];
            for (auto p : points)
            {
                if ((x - p[0]) * (x - p[0]) + (y - p[1]) * (y - p[1]) <= r * r)
                {
                    cnt++;
                }
            }
            res[i] = cnt;
        }
        return res;
    }
};