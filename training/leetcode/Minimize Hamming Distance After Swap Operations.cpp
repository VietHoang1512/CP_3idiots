#include <bits/stdc++.h>
using namespace std;

int main()
{
}
const int mx = 1e5 + 5;

class Solution
{
public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int total = source.size(), dist = 0;
        vector<int> parent(total, 0); //, allocated(total, 0), truth(total, 0);
        // vector<int> dp[mx];
        map<int, vector<int>> m;
        for (int i = 0; i < total; i++)
        {
            // if (source[i] == target[i])
            // {
            //     allocated[i] = 1;
            //     truth[i] = 1;
            // }
            // else
            // {
            //     dist++;
            // }
            parent[i] = i;
        }
        for (auto p : allowedSwaps)
        {
            UNION(parent, p[0], p[1]);
        }
        for (int i = 0; i < total; i++)
        {
            FIND(parent, i);
            m[parent[i]].push_back(i);
            // cout << parent[i] << " ";
        }
        int res = 0;
        for (auto x : m)
        {
            cout << x.first;
            map<int, int> temp_map;
            int tmp_res = x.second.size();
            for (auto y : x.second)
            {
                temp_map[y]++;
            }
            for (auto y : x.second)
            {
                if (temp_map[y])
                {
                    temp_map[y]--;
                    tmp_res--;
                }
            }
            res += tmp_res;
        }
        // for (int i = 0; i < total; i++)
        // {
        //     if (!truth[i])
        //     {
        //         for (auto x : dp[parent[i]])
        //         {
        //             if ((!allocated[x]) && (source[x] == target[i]))
        //             {
        //                 dist--;
        //                 truth[i] = 1;
        //                 allocated[x] = 1;
        //                 break;
        //             }
        //         }
        //     }
        // }

        cout << endl;
        return dist;
    }
    int FIND(vector<int> &parent, int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = FIND(parent, parent[u]);
    }
    void UNION(vector<int> &parent, int u, int v)
    {
        int p1 = FIND(parent, u), p2 = FIND(parent, v);
        if (p1 <= p2)
            parent[p2] = p1;
        else
            parent[p1] = p2;
    }
};