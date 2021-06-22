#include <bits/stdc++.h>
using namespace std;

// #define __builtin_popcount __builtin_popcountll
// next_permutation(arr.begin(), arr.end()), prev_permutation(arr.begin(), arr.end())

int main()
{
}

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int total = height.size();
        int l = 0, r = total - 1;
        int res = 0, cnt = 1;
        while (cnt)
        {
            // cout << l << " " << r << endl;
            if (r <= l)
                return res;
            res = max(res, (r - l) * min(height[l], height[r]));
            if (height[l] <= height[r])
            {
                cnt = 0;
                for (int i = l; i <= r; i++)
                {
                    if (height[i] > height[l])
                    {
                        l = i;
                        cnt = 1;
                        break;
                    }
                }
                continue;
            }
            if (height[r] <= height[l])
            {
                cnt = 0;

                for (int i = r; i >= l; i--)
                {
                    if (height[i] > height[r])
                    {
                        r = i;
                        cnt = 1;

                        break;
                    }
                }
                continue;
            }
        }
        return res;
    }
};