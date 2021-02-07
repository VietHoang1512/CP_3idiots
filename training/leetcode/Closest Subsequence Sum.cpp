class Solution
{
public:
    int res = INT_MAX;
    int minAbsDifference(vector<int> &nums, int goal)
    {
        int n = nums.size();
        TRY(nums, 0, 0, n, goal);
        return res;
    }
    void TRY(vector<int> nums, int k, int cur, int n, int goal)
    {
        if (k == n)
            return;
        int tmp = cur + nums[k];

        res = min(res, abs(cur - goal));
        res = min(res, abs(tmp - goal));

        TRY(nums, k + 1, tmp, n, goal);
        TRY(nums, k + 1, cur, n, goal);
    }
};