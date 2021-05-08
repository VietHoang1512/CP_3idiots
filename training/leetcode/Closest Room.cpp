#include <bits/stdc++.h>
using namespace std;

int main()
{
}

bool cmp(vector<int> a, vector<int> b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[0] < b[0];
}

class Solution
{
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
    {

        int n = rooms.size();
        int k = queries.size();
        sort(rooms.begin(), rooms.end(), cmp);
        sort(queries.begin(), queries.end());
        vector<int> res(k, -1);
    }
};