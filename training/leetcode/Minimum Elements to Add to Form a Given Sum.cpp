#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        int total = nums.size();
        int l = 0, r = total - 1;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        while (r >= l)
        {
            if (r == l)
            {
                sum += nums[l];
                break;
            }
            sum += (nums[l] + nums[r]);
            l++;
            r--;
        }

        //  long long sum = accumulate(nums.begin(), nums.end(), 0);
        double need = abs((double)(goal - sum));
        return ceil(need / limit);
    }
};