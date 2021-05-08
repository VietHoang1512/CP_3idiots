#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        map<int, int> S, P;
        vector<int> res;
        int m = s.size(), n = p.size();
        for (auto c : p)
        {
            P[c]++;
        }
        for (int i = 0; i < n - 1; i++)
        {
            S[s[i]]++;
        }
        for (int i = n - 1; i < m; i++)
        {
            if ((i - n) >= 0)
                S[s[i - n]]--;
            S[s[i]]++;
            bool equal = true;
            for (auto x : P)
            {
                if (S[x.first] != P[x.first])
                    equal = false;
            }
            if (equal)
                res.push_back(i - n + 1);
        }

        // for (auto x : P)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }
        return res;
    }
};