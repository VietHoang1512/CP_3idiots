#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll

int main()
{
}
class Solution
{
public:
    int mySqrt(int x)
    {
        if (!x)
            return 0;
        if (x < 4)
            return 1;
        if (x < 9)
            return 2;
        long long k = 0;
        // while ((1 << (2 * k)) <= x)
        // {
        //     k++;
        // }
        long long l = 1, r = x;
        cout << l << " " << r << endl;
        while (r > l)
        {
            long long tmp = l + (r - l) / 2;
            if (tmp * tmp > x)
            {
                r = tmp;
            }
            else
            {
                l = tmp;
            }
            if (r - l == 1)
            {
                if (r * r <= x)
                    return r;
                return l;
            }
        }
        return l;
    }
};