#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<char> p;
        for (auto c : pattern)
        {
            p.push_back(c);
        }

        vector<bool> res;
        for (auto query : queries)
        {
            int pos = 0;
            bool r = true;
            for (int i = 0; i < query.size(); i++)
            {
                if (query[i] <= 'Z' && query[i] >= 'A')
                {
                    if (pos >= pattern.size() || pattern[pos] != query[i])
                    {
                        r = false;
                    }
                    else
                    {
                        pos++;
                    }
                }
                else
                {
                    if (pattern[pos] == query[i])
                    {
                        pos++;
                    }
                }
            }
            if (pos != pattern.size())
                r = false;
            res.push_back(r);
        }
        return res;
    }
};