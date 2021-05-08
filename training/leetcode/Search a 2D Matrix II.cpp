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
        cout << matrix.size() << " " << matrix[0].size();
        for (auto row : matrix)
        {
            if ((row.front() > target) || (row.back() < target)) continue;
            if (binary_search(row.begin(), row.end(), target))
                return true;
        }
        return false;
    }
};