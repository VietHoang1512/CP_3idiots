#include <bits/stdc++.h>
using namespace std;

int main()
{
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

class Solution
{
public:
    int minDeletions(string s)
    {
        // cout << "\n\n";
        unordered_map<int, int> m;
        int res = 0;
        for (auto c : s)
        {
            m[c - 'a']++;
        }
        vector<pair<int, int>> v;
        for (auto p : m)
        {
            v.push_back(p);
        }
        if (v.size() == 1)
            return 0;
        sort(v.begin(), v.end(), cmp);
        // for (auto p:v)
        // cout << p.first << "-" << p.second << " ";
        int prev = v[0].second;
        for (int i = 1; i < v.size(); i++)
        {
            int cur = v[i].second;
            if (cur >= prev)
            {
                if (prev == 0)
                {
                    res += cur;
                    cur = 0;
                }
                else
                {
                    res += (cur - prev + 1);
                    cur = prev - 1;
                }
            }
            prev = cur;
        }
        return res;
    }
};