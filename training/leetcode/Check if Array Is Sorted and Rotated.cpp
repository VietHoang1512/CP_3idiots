class Solution
{
public:
    bool check(vector<int> &nums)
    {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        int total = nums.size();
        for (int i = 0; i < total; i++)
        {
            vector<int> tmp;
            for (int j = 0; j < total; j++)
            {
                tmp.push_back(nums[(i + j) % total]);
            }
            if (tmp == sorted_nums)
                return true;
        }
        return false;
    }
};