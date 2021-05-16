#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int maxDiff(int num)
    {
        vector<int> v;
        while (num)
        {
            v.push_back(num % 10);
            num /= 10;
        }
        reverse(v.begin(), v.end());

        int total = v.size();
        vector<int> mn = v, mx = v;
        // Find min
        if (v[0] > 1)
        {
            for (int i = total - 1; i >= 0; i--)
            {
                if (v[i] == v[0])
                {
                    mn[i] = 1;
                }
            }
        }
        else
        {
            int tmp = -1;
            for (int i = 0; i < total; i++)
            {
                if (v[i] > 1)
                {
                    tmp = v[i];
                    break;
                }
            }
            for (int i = 0; i < total; i++)
            {
                if (v[i] == tmp)
                {
                    mn[i] = 0;
                }
            }
        }

        if (v[0] < 9)
        {
            for (int i = total - 1; i >= 0; i--)
            {
                if (v[i] == v[0])
                {
                    mx[i] = 9;
                }
            }
        }
        else
        {
            int tmp = -1;
            for (int i = 0; i < total; i++)
            {
                if (v[i] < 9)
                {
                    tmp = v[i];
                    break;
                }
            }
            for (int i = 0; i < total; i++)
            {
                if (v[i] == tmp)
                {
                    mx[i] = 9;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < total; i++)
        {
            res += pow(10, i) * (mx[total - 1 - i] - mn[total - 1 - i]);
        }
        // cout << endl;
        // for (auto x : v)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x : mn)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        // for (auto x : mx)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        return res;
    }
};