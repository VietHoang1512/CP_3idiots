#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int total = s.size();
        int cnt = 0;
        if (total == 1)
            return true;
        for (int i = 0; i + 1 < total; i++)
        {
            if ((s[i] == '0') && (s[i + 1] == '1'))
                cnt++;
        }

        return cnt == 1;
    }
};