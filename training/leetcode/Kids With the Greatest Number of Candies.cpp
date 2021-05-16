#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (auto c : candies)
        {
            if (c + extraCandies >= mx)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};