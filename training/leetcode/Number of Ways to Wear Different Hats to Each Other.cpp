#include <bits/stdc++.h>
using namespace std;

int main()
{
}
const int mod = 1e9 + 7;
class Solution
{
public:
    int numberWays(vector<vector<int>> &hats)
    {
        int n = hats.size();
        vector<vector<int>> hat2ppl(40), dp(40, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (auto x : hats[i])
            {
                hat2ppl[x-1].push_back(i);
            }
        }
    }
};