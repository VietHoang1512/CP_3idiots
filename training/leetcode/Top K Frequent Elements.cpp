#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll
// next_permutation(arr.begin(), arr.end()), prev_permutation(arr.begin(), arr.end())

int main()
{
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second >= b.second;
}

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        vector<pair<int, int>> v;
        for (auto n : nums)
        {
            m[n]++;
        }
        v.insert(v.end(), m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);
        for (auto p : v)
        {
            cout << p.second << " ";
        }
        cout << "\n";
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(v[i].first);
        }
        return res;
    }
};