#include <bits/stdc++.h>
using namespace std;

int main()
{
}
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(grid);
        for (int i=1; i<m; i++){
            for (int j=0; j<n; j++){
                int tmp = INT_MAX;
                for (int k=0; k<n; k++)
                    tmp = min(tmp, grid[i][j] + dp[i-1][k] + moveCost[grid[i-1][k]][j]);
                dp[i][j] = tmp;
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};