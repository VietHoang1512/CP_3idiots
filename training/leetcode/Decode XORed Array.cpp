#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> v;
        v.push_back(first);
        for (auto x : encoded)
        {
            v.push_back(v.back() ^ x);
        }
        return v;
    }
};