class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        int col[10], row[10], square[10];
        for (int i = 0; i < 9; i++)
        {
            memset(row, 0, sizeof(row));
            memset(col, 0, sizeof(col));
            for (int j = 0; j < 9; j++)
            {
                if ((board[i][j] <= '9') && (board[i][j] >= '0'))
                {
                    row[board[i][j] - '0']++;
                    if (row[board[i][j] - '0'] > 1)
                        return false;
                }
                if ((board[j][i] <= '9') && (board[j][i] >= '0'))
                {
                    col[board[j][i] - '0']++;
                    if (col[board[j][i] - '0'] > 1)
                        return false;
                }
            }
        }
        for (int i = 0; i < 9; i += 3)
        {

            for (int j = 0; j < 9; j += 3)
            {
                memset(square, 0, sizeof(square));
                for (int k = 0; k < 9; k++)
                {
                    if ((board[i + k / 3][j + k % 3] <= '9') && (board[i + k / 3][j + k % 3] >= '0'))
                    {
                        square[board[i + k / 3][j + k % 3] - '0']++;
                        if (square[board[i + k / 3][j + k % 3] - '0'] > 1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};