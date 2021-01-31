class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        int total = grid.size();
        int maxc[total], maxr[total];
        for (int i = 0; i < total; i++)
        {
            int tmp_r = 0, tmp_c = 0;

            for (int j = 0; j < total; j++)
            {
                tmp_r = max(tmp_r, grid[i][j]);
                tmp_c = max(tmp_c, grid[j][i]);
            }
            maxc[i] = tmp_c;
            maxr[i] = tmp_r;
            // cout << i << " " << tmp_c << " " << tmp_r << endl;
        }
        int res = 0;
        for (int i = 0; i < total; i++)
        {
            for (int j = 0; j < total; j++)
            {
                res += min(maxr[i], maxc[j]) - grid[i][j];
            }
        }
        return res;
    }
};