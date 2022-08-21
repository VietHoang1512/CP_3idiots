#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        map<char, int> m;
        for (auto c : s)
        {
            m[c]++;
            if (m[c] > 1)
                return c;
        }
    }
};