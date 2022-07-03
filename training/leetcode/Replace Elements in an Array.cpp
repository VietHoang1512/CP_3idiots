#include <bits/stdc++.h>
using namespace std;

int main()
{
}


bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;
        for (auto op:operations)
        {
            int a = op[0], b = op[1], c=m[a];
            m.erase(a);
            m[b] = c;
            
        }
        vector<pair<int, int>> v;
        for (auto p:m)
            v.push_back(p);
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for (auto p:v){
            res.push_back(p.first);
        }
        return res;
    }
};

