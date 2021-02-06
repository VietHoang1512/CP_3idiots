const int mx = 100005;
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int len = nums.size();
        int pos[mx], neg[mx];
        memset(pos, 0, sizeof(pos));
        memset(neg, 0, sizeof(neg));

        int res = -INT_MAX;

        for (int i = 1; i <= len; i++)
        {

            pos[i] = max(nums[i - 1], pos[i - 1] + nums[i - 1]);
            neg[i] = min(nums[i - 1], neg[i - 1] + nums[i - 1]);
            res = max(res, max(pos[i], -neg[i]));
        }
        return res;
    }
};