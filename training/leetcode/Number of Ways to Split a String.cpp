#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    int numWays(string s)
    {
        int total = s.size(), cnt = 0;
        for (auto c : s)
        {
            if (c == '1')
                cnt++;
        }
        if (cnt % 3)
            return 0;
        if (cnt == 0)
    }
};