#include <bits/stdc++.h>
using namespace std;

int main()
{
}

class Solution
{
public:
    int findValidSplit(vector<int> &nums)
    {
        map<int, int> m;
        int len = nums.size();

        vector<int> v(len);
    
        iota(v.begin(), v.end(), 1);
        for (int i = 0; i < len; i++)
        {
            for (int j = len - 1; j >= i; j--)
            {
                if (__gcd(nums[i], nums[j]) > 1)
                {
                    m[i] = j;
                    break;
                }
            }
        }
        
        // for (int i = 0; i < len; i++)
        // {
        //     if (m[i] == i)
        //         if (i < len)
        //             return i + 1;
        //     i = m[i];

        // }
        return -1;
    }
};