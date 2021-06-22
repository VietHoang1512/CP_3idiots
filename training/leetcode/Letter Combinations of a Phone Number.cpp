#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}

class Solution
{
public:
    vector<char> v[10];
    vector<int> src;
    vector<string> res;
    vector<string> letterCombinations(string digits)
    {

        v[2] = {'a', 'b', 'c'};
        v[3] = {'d', 'e', 'f'};
        v[4] = {'g', 'h', 'i'};
        v[5] = {'j', 'k', 'l'};
        v[6] = {'m', 'n', 'o'};
        v[7] = {'p', 'q', 'r', 's'};
        v[8] = {'t', 'u', 'v'};
        v[9] = {'w', 'x', 'y', 'z'};

        for (auto c : digits)
        {
            src.push_back(c - '0');
        }
        TRY("");
        return res;
    }
    void TRY(string cur)
    {
        int total = src.size(), len = cur.size();
        if (len == total)
        {
            if (len)
                res.push_back(cur);
            // cout << "Found " << cur << endl;
            return;
        }
        for (auto d : v[src[len]])
        {
            TRY(cur + d);
        }
    }
};