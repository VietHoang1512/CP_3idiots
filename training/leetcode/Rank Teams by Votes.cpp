#include <bits/stdc++.h>
using namespace std;

int main()
{
}

const int mx = 30;

bool cmp(vector<int> a, vector<int> b)
{
    int total = a.size();
    for (int i = 0; i < total; i++)
    {
        if (a[i] > b[i])
            return true;
        if (a[i] < b[i])
            return false;
    }
    return false;
}

class Solution
{
public:
    string rankTeams(vector<string> &votes)
    {

        vector<vector<int>> dp(mx, vector<int>(mx, 0));
        for (auto c : votes[0])
        {
            dp[c - 'A'][mx - 1] = 'Z' - c + 1;
        }
        for (auto vote : votes)
        {
            for (int i = 0; i < vote.size(); i++)
            {
                // cout << (vote[i] - 'A') << "-" << i << endl;
                dp[vote[i] - 'A'][i]++;
            }
        }
        // cout << "\nDONE\n";
        sort(dp.begin(), dp.end(), cmp);
        string res;
        for (auto r : dp)
        {
            if (r.back())
            {
                res += ('Z' - r.back() + 1);
            }
        }
        return res;
    }
};