class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int tmp = 0, res = 0;
        for (auto x : rectangles)
        {
            tmp = max(tmp, min(x[0], x[1]));
        }
        for (auto x : rectangles)
        {
            if (tmp == min(x[0], x[1]))
                res++;
        }
        return res;
    }
};