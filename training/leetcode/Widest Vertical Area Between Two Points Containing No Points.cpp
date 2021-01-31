class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        set<int> s;
        vector<int> v;
        for (vector<int> point : points)
        {
            s.insert(point[0]);
        }
        v.assign(s.begin(), s.end());
        sort(v.begin(), v.end());
        int len = v.size(), res = 0;

        for (int i = 0; i < len - 1; i++)
        {
            res = max(res, v[i + 1] - v[i]);
        }
        return res;
    }
};