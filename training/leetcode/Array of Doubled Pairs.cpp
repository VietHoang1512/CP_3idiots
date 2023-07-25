#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        map<int, map<int, int>> m;
        int n_zero = 0;
        for (auto n : arr)
        {
            // cout << "Processing " << n;
            if (n == 0)
            {
                n_zero++;
                continue;
            }
            int e = 0;
            while (n % 2 == 0)
            {
                e++;
                n /= 2;
            }
            m[n][e]++;
            // cout << "->" << n << "*2^" << e << endl;
        }
        if (n_zero % 2)
            return false;
        for (auto p : m)
        {
            // cout << "\n"
            //      << p.first << ": ";
            int cur = -1, n_cur = 0;
            for (auto n : p.second)
            {
                // cout << n.first << "-" << n.second << " ";
                if ((cur >= 0) && (n.first != cur + 1))
                    return false;
                if (n_cur > 0)
                {
                    n.second -= n_cur;
                    if (n.second < 0)
                        return false;
                }
                if (n.second>0)
                {
                    cur = n.first;
                    n_cur = n.second;
                }
                else
                {
                    cur = -1;
                    n_cur = 0;
                }
            }
            if (n_cur != 0)
                return false;
        }
        return true;
    }
};