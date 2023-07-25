#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
        int total = nums.size();
        map<int, vector<int>> m;

        for (int i = 0; i < total; i++)
        {
            cout << endl
                 << nums[i] << ": ";
            for (auto p : prime_divisor(nums[i]))
                m[p].push_back(i);
        }
        vector<int> parent(total);
        for (int i = 0; i < total; i++)
        {
            parent[i] = i;
        }
        for (auto p : m)
        {
            int len = p.second.size();
            for (int i = 0; i < len - 1; i++)
            {
                Union(p.second[i], p.second[i + 1], parent);
            }
        }
        map<int, int> cnt;
        int res = 1;
        for (int i = 0; i < total; i++)
        {
            int cur_parent = Find(i, parent);
            cnt[cur_parent]++;
            res = max(res, cnt[cur_parent]);
        }
        return res;
    }
    set<int> prime_divisor(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                set<int> res = prime_divisor(n / i);
                res.insert(i);
                return res;
            }
        }
        return {n};
    }
    void Union(int i, int j, vector<int> &parent)
    {
        int a = Find(i, parent);
        int b = Find(j, parent);
        parent[b] = min(a, b);
        parent[a] = min(a, b);
    }
    int Find(int i, vector<int> &parent)
    {
        if (parent[i] == i)
            return i;
        return Find(parent[i], parent);
    }
};