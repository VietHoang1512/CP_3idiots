#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        int total = words.size();
        vector<vector<int>> v(total);
        unordered_map<string, int> m;
        unordered_map<int, int> n;
        unordered_map<string, int> str2id;
        for (int j = 0; j < total; j++)
        {
            string w = words[j];
            string s = "";
            int len = w.length();
            for (int i = 0; i < len; i++)
            {
                s += w[i];
                if (m.find(s) == m.end())
                {
                    m[s] = 1;
                    str2id[s] = m.size();
                }
                else
                {
                    m[s]++;
                }
                n[str2id[s]] = m[s];
                v[j].push_back(str2id[s]);
            }
        }

        vector<int> res;
        for (int i = 0; i < total; i++)
        {
            string w = words[i];
            int len = w.size();
            int cnt = 0;
            for (auto s : v[i])
            {
                cnt += n[s];
            }
            res.push_back(cnt);
        }
        return res;
    }
};