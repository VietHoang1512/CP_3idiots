class Solution
{
public:
    int n_rows, n_cols;
    int res = 0, empty_traversed = 0, n_empty = 0, source_traversed = -1;

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        n_rows = grid.size();
        n_cols = grid[0].size();
        int n_obstacle;
        int start_x, start_y;
        int target_x, target_y;

        for (int i = 0; i < n_rows; i++)
        {
            for (int j = 0; j < n_cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    start_x = i;
                    start_y = j;
                    cout << "Start from " << start_x << " " << start_y << endl;
                }
                else if (grid[i][j] == 2)
                {
                    target_x = i;
                    target_y = j;
                    cout << "End at " << target_x << " " << target_y << endl;
                }
                else if (grid[i][j] == 0)
                {
                    n_empty++;
                }
                else
                    n_obstacle++;
            }
        }
        cout << "Start traversing\n";
        traverse(start_x, start_y, empty_traversed, grid);

        return res;
    }

    int traverse(int x, int y, int &empty_traversed, vector<vector<int>> &grid)
    {
        cout << "On " << x << " " << y << endl;

        //         Out of bound
        if ((x < 0) || (x > n_rows) || (y < 0) || (y > n_cols))
        {
            cout << "Out of bound here\n";
            return 0;
        }

        //         Arrived target
        if (grid[x][y] == 2)
        {
            cout << "Arrived target\n";
            if (empty_traversed == n_empty)
                res++;
            return 0;
        }

        // Arrived start
        if (grid[x][y] == 1)
        {
            cout << "Arrived start\n";
            source_traversed++;
            if (source_traversed)
                return 0;
        }

        grid[x][y] = -1;
        cout << "Start 1\n";
        traverse(x, y + 1, empty_traversed, grid);
        cout << "Start 2\n";

        traverse(x + 1, y, empty_traversed, grid);
        cout << "Start 3\n";

        traverse(x - 1, y, empty_traversed, grid);
        cout << "Start 4\n";

        traverse(x, y - 1, empty_traversed, grid);

        grid[x][y] = 0;
        return 0;
    }
};