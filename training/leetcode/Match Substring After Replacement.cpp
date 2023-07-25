#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool matchReplacement(string s, string sub, vector<vector<char>> &mappings)
    {
        // cout << endl;
        int len = sub.size(), total = s.size();

        map<pair<char, char>, int> m;
        for (auto mapping : mappings)
        {
            m[{mapping[0], mapping[1]}] = 1;
        }
        for (int i = 0; i <= total - len; i++)
        {
            int mapped = true;
            // string tmp = s.substr(i, len);
            for (int j = 0; j < len; j++)
            {
                if ((s[i+j] != sub[j]) && (!m[{sub[j], s[i+j]}])){
                    mapped = false;
                    break;
                }
            }
            if (mapped)
            {
                // cout << tmp;
                return true;
            }
        }
        return false;
    }
};