#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    bool checkZeroOnes(string s)
    {

        s += '2';
        int total = s.size(), cnt0, cnt1, res0 = 0, res1 = 0;
        cnt0 = (s[0] == '0');
        cnt1 = (s[0] == '1');
        for (int i = 1; i < total; i++)
        {
            if (s[i] != s[i - 1])
            {
                res0 = max(cnt0, res0);
                res1 = max(cnt1, res1);
                cnt0 = (s[i] == '0');
                cnt1 = (s[i] == '1');
            }
            else
            {
                if (s[i] == '0')
                    cnt0++;
                else
                    cnt1++;
            }
        }
        cout << res0 << res1 << endl;
        return res1 > res0;
    }
};