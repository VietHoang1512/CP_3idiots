#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll
// next_permutation(arr.begin(), arr.end()), prev_permutation(arr.begin(), arr.end())

int main()
{
}
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        if (n==1) return 1;
        int l = 1, r = n;
        while (r > l)
        {
            int tmp = l + (r - l) / 2;
            if (isBadVersion(tmp))
            {
                r = tmp;
            }
            else
            {
                l = tmp;
            }
            if (r - l == 1)
            {
                if (isBadVersion(l))
                    return l;
                return r;
            }
        }
        return r;
    }
};