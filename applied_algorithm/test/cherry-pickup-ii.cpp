class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        const int mx = 70;
        int n_rows = grid.size();
        int n_cols = grid[0].size();
        int next_score, tmp;
        int dp[mx][mx][mx];

        for (int i = 0; i < n_cols; i++)
        {
            for (int j = 0; j < n_cols; j++)
            {
                if (i != j)
                {
                    dp[n_rows - 1][i][j] = grid[n_rows - 1][i] + grid[n_rows - 1][j];
                }
                else
                {
                    dp[n_rows - 1][i][j] = grid[n_rows - 1][i];
                }
            }
        }

        for (int row = n_rows - 2; row >= 0; row--)
        {
            // cout << "\n On row " << row << " ";
            for (int col_x = 0; col_x < n_cols; col_x++)
            {

                for (int col_y = 0; col_y < n_cols; col_y++)
                {

                    // cout << "\ncolumn x " << col_x << " column y " << col_y << " ";
                    if (col_x == col_y)
                    {
                        tmp = grid[row][col_x];
                    }
                    else
                    {
                        tmp = grid[row][col_x] + grid[row][col_y];
                    }

                    next_score = dp[row + 1][col_x][col_y];

                    for (int next_col_x = col_x - 1; next_col_x <= col_x + 1; next_col_x++)
                    {
                        if ((next_col_x < 0) || (next_col_x >= n_cols))
                            continue;

                        for (int next_col_y = col_y - 1; next_col_y <= col_y + 1; next_col_y++)
                        {
                            if ((next_col_y < 0) || (next_col_y >= n_cols))
                                continue;
                            next_score = max(next_score, dp[row + 1][next_col_x][next_col_y]);
                        }
                    }
                    dp[row][col_x][col_y] = tmp + next_score;
                }
            }
        }
        return dp[0][0][n_cols - 1];
    }
};