class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int len = nums.size();
        int sum_nearest = nums[0] + nums[1] + nums[2], nearest = abs(sum_nearest - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i++)
        {
            for (int j = i + 1; j < len - 1; j++)
            {
                for (int k = j + 1; k < len; k++)
                {
                    int sum_tmp = nums[i] + nums[j] + nums[k];
                    int tmp = abs(sum_tmp - target);
                    if (tmp < nearest)
                    {
                        sum_nearest = sum_tmp;
                        nearest = tmp;
                    }
                }
            }
        }
        return sum_nearest;
    }
};