#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int res = 0;
        for (auto x : items)
        {
            if ((ruleKey == "type") && (ruleValue == x[0]))
            {
                res++;
            }
            else if ((ruleKey == "color") && (ruleValue == x[1]))
            {
                res++;
            }
            else if ((ruleKey == "name") && (ruleValue == x[2]))
            {
                res++;
            }
        }
        return res;
    }
};