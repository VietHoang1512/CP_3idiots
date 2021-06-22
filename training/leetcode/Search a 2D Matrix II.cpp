#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // cout << matrix.size() << " " << matrix[0].size();
        // for (auto row : matrix)
        // {
        //     if ((row.front() > target) || (row.back() < target)) continue;
        //     if (binary_search(row.begin(), row.end(), target))
        //         return true;
        // }
        // return false;
        int m = matrix.size(), n = matrix[0].size();
        int h = 0, w = n - 1;
        while (1)
        {
            // cout << h << " " << w << endl;
            if (matrix[h][w] == target)
                return true;
            if (matrix[h][w] < target)
            {
                if (h == m - 1)
                    return false;
                h++;
            }
            else if (matrix[h][w] > target)
            {
                if (w == 0)
                    return false;
                w--;
            }
        }
        cout << "\n\n";
        return false;
    }
};