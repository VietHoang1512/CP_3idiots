class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {

        int total = groupSizes.size();
        vector<vector<int>> res;
        vector<int> GroupBySize[500];

        for (int i = 0; i < total; i++)
        {
            GroupBySize[groupSizes[i]].push_back(i);
        }

        for (int i = 0; i <= total; i++)
        {
            int len = GroupBySize[i].size();
            if (!len)
                continue;
            for (int j = 0; j < len; j += i)
            {
                vector<int> p;
                for (int k = 0; k < i; k++)
                {
                    p.push_back(GroupBySize[i][j + k]);
                }
                res.push_back(p);
            }
        }

        return res;
    }
};