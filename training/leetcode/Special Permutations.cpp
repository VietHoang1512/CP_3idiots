#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int res = 0;
    int mod = 1e9 + 7;
    int specialPerm(vector<int> &nums)
    {
        int total = nums.size();
        vector<int> visited(total);
        map<int, vector<int>> mg, ml;
        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                if (i != j)
                {

                    if ((nums[i] % nums[j]) == 0)
                    {

                        ml[i].push_back(j);
                    }
                    if ((nums[j] % nums[i]) == 0)
                    {
                        mg[i].push_back(j);
                    }
                }
            }
        }
        for (int i = 0; i < total; i++)
        {
            DFS(visited, mg, ml, i, 0, 1);
            DFS(visited, mg, ml, i, 0, 0);
        }
        return res;
    }
    void DFS(vector<int> &visited, map<int, vector<int>> &mg, map<int, vector<int>> &ml, int x, int cnt, int greater)
    {
        int total = visited.size();
        visited[x] = 1;
        cnt++;
        if (cnt == total)
        {
            res++;
            visited[x] = 0;
            cnt--;
            res %= mod;
            return;
        }
        if (greater)
        {
            for (auto y : mg[x])
            {
                if (!visited[y])
                {
                    DFS(visited, mg, ml, y, cnt, x, 0);
                }
            }
        }
        else
        {
            for (auto y : ml[x])
            {
                if (!visited[y])
                {
                    DFS(visited, mg, ml, y, cnt, x, 1);
                }
            }
        }

        visited[x] = 0;
        cnt--;
    }
};