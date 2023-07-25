#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int total = positions.size();
        vector<int> v1(total), v2(total);
        for (int i = 0; i < total; i++)
        {
            if (directions[i] == 'L')
                v2[positions[i]] = healths[i];
            if (directions[i] == 'R')
                v1[positions[i]] = healths[i];
        }
    }
};