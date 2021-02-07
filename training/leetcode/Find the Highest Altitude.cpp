class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int res = 0, cum = 0, tmp = 0, total = gain.size();
        for (int i = 0; i < total; i++)
        {
            cum += gain[i];
            if (cum > res)
                res = cum;
        }
        return res;
    }
};