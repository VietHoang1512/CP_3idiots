class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        int cnt[105];
        memset(cnt, 0, sizeof(cnt));
        for (auto x : nums)
        {
            cnt[x]++;
        }
        int tmp = 0;
        for (int i = 0; i < 104; i++)
        {
            if (cnt[i] == 1)
                tmp += i;
        }
        return tmp;
    }
};