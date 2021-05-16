#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int minSwaps(string s)
    {
        int cnt0 = 0, cnt00 = 0, cnt01 = 0, cnt1 = 0, cnt10 = 0, cnt11 = 0, total = s.size();
        for (int i = 0; i < total; i++)
        {
            char c = s[i];
            if (c == '0')
            {
                cnt0++;
                if (i % 2 == 0)
                    cnt00++;
                else
                    cnt01++;
            }
            else
            {
                cnt1++;
                if (i % 2 == 0)
                    cnt10++;
                else
                    cnt11++;
            }
        }
        if (total % 2)
        {
            if (abs(cnt0 - cnt1) != 1)
                return -1;
            if (cnt0 - cnt1 == 1)
            {
                return cnt01;
            }
            else
            {
                return cnt11;
            }
        }
        else
        {
            if (cnt0 != cnt1)
                return -1;
            return min(cnt00, cnt01);
        }
        return 0;
    }
};