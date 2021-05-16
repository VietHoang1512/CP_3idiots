#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n == 0)
            return 0;
        cout << endl;
        vector<int> nums(n + 1, 0);
        int res = 1;
        nums[1] = 1;
        for (int i = 1; 2 * i <= n; i++)
        {
            nums[2 * i] = nums[i];

            res = max(res, nums[2 * i]);
            // cout << nums[2 * i] << " ";
            if (2 * i + 1 <= n)
            {
                nums[2 * i + 1] = nums[i] + nums[i + 1];
                res = max(res, nums[2 * i + 1]);
                // cout << nums[2 * i + 1] << " ";
            }
        }
        return res;
    }
};