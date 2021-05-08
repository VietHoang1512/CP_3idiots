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
    vector<int> findRightInterval(vector<vector<int>> &inp)
    {
        cout << "\n*********************\n";
        vector<vector<int>> intervals = inp;
        map<int, map<int, int>> m;
        int total = intervals.size();
        vector<int> res(total, -1);
        for (int i = 0; i < total; i++)
        {
            m[inp[i][0]][inp[i][1]] = i;
        }

        sort(intervals.begin(), intervals.end(), cmp);
        for (auto x : intervals)
        {
            cout << x[0] << "-" << x[1] << " ";
        }
        for (int i = 0; i < total - 1; i++)
        {
            for (int j = i; j < total; j++)
            {
                if (intervals[j][0] >= intervals[i][1])
                {
                    res[i] = j;
                    break;
                }
            }
        }
        vector<int> result(total, -1);
        for (int i = 0; i < total; i++)
        {
            if (res[i] == -1)
                continue;
            int src = m[intervals[i][0]][intervals[i][1]], des = m[intervals[res[i]][0]][intervals[res[i]][1]];
            result[src] = des;
        }
        return result;
    }
};
