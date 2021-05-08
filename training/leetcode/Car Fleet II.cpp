#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars)
    {
        int total = cars.size();
        vector<double> res(total, 0.0);
        res[total - 1] = -1;
        for (int i = 0; i < total - 1; i++)
        {
            if (cars[i][1] <= cars[i + 1][1])
            {
                res[i] = -1;
                continue;
            }
            res[i] = (cars[i + 1][0] - cars[i][0] - 0.0) / (cars[i][1] - cars[i + 1][1]);
        }
        return res;
    }
};