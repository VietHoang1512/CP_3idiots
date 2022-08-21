#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int secondsToRemoveOccurrences(string s)
    {
        int total = s.size(), res = 0;

        while (1)
        {
            int replace = 0;
            int cur_replace = 0;
            for (int i = 0; i < total-1; i++)
            {
                if ((s[i] == '0') && (s[i+1] == '1') && (!cur_replace))
                {

                    s[i] = '1';
                    s[i + 1] = '0';
                    cur_replace = 1;
                }
                else
                    cur_replace = 0;
                replace = max(replace, cur_replace);
            }
            res += replace;
            if (replace == 0)
                break;
        }
        return res;
    }
}

;