#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        unordered_map<char, int> m;

        for (auto c : t)
        {
            m[c]++;
        }
        for (auto c : s)
        {
            m[c]--;
        }
        for (auto p : m)
        {
            if (p.second)
            {
                return p.first;
            }
        }
        return 'a';
    }
};